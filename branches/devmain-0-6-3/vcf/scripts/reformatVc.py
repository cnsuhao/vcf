#!/usr/bin/env python
#Author: Marcello Pietrobon
#

"""
"""

import sys
import os
import os.path
import shutil
import filecmp
import ConfigParser
import re
from optparse import OptionParser

backupFiles = False

modules ={}


# globals
compilerVc6  = 'vc6'
compilerVc70 = 'vc70'
compilerVc71 = 'vc71'
g_default_config = "reformatVcConfig.ini"

#enum AppType
enumAppTypeNone = 0
enumAppTypeExe  = 1
enumAppTypeDll  = 2
enumAppTypeLib  = 3

enum_ADD_NONE        = 0
enum_ADD_CPP         = 1
enum_SUBTRACT_CPP    = 2
enum_ADD_LINK32      = 3
enum_SUBTRACT_LINK32 = 4
enum_ADD_LIB32       = 5
enum_SUBTRACT_LIB32  = 6
enum_ADD_BSC32       = 7

#enumStatic  = { 'static' : 1, 'dynamic' : 2 }

re_trueproject = re.compile( r'# Microsoft Developer Studio Project File - Name="(?P<trueProjectName>[a-zA-Z0-9_ \\/.]*?)" - Package Owner=<([0-9]+)>' )
re_output_or_intermed_dir = re.compile( r'(^# PROP (Output|Intermediate)_Dir "(?P<subdir>[a-zA-Z0-9_ $\(\)\\/.]*?)")' )
re_output_dir = re.compile( r'^# PROP Output_Dir "(?P<subdir>[a-zA-Z0-9_ $\(\)\\/.]*?)"' )
re_intermed_dir = re.compile( r'^# PROP Intermediate_Dir "(?P<subdir>[a-zA-Z0-9_ $\(\)\\/.]*?)"' )
#re_configuration = re.compile( r'"\$\(CFG\)"(\s+)==(\s+)"(?P<projectName>\w+)(\s+)-(\s+)(?P<platform>\w+)(\s+)(?P<configName>\w+)"' )
re_configuration = re.compile( r'"\$\(CFG\)"(\s+)==(\s+)"(?P<projectName>\w+)(\s+)-(\s+)(?P<platform>(\w+\s+)+)(?P<configName>\w+)"' )

re_LIB32_static             = re.compile( r'^LIB32\s*=' )
re_PROP                     = re.compile( r'^# PROP' )
re_ADD                      = re.compile( r'^# ADD' )
re_ADD_CPP                  = re.compile( r'^# ADD CPP' )
re_ADD_CPP_ALL              = re.compile( r'^# ADD (BASE |)CPP' )
re_ADD_CPP_BASE             = re.compile( r'^# ADD BASE CPP' )
re_SUBTRACT_CPP             = re.compile( r'^# SUBTRACT CPP' )
re_ADD_LINK32               = re.compile( r'^# ADD LINK32' )
re_ADD_LINK32_ALL           = re.compile( r'^(# ADD (BASE |)LINK32)' )
re_ADD_LINK32_BASE          = re.compile( r'^# ADD BASE LINK32' )
re_SUBTRACT_LINK32          = re.compile( r'^# SUBTRACT LINK32' )
re_ADD_LIB32                = re.compile( r'^# ADD LIB32' )
re_ADD_LIB32_ALL            = re.compile( r'^# ADD (BASE |)LIB32' )
re_ADD_LIB32_BASE           = re.compile( r'^# ADD BASE LIB32' )
re_SUBTRACT_LIB32           = re.compile( r'^# SUBTRACT LIB32' )
re_ADD_BSC32                = re.compile( r'^# ADD BSC32' )
re_ADD_BSC32_ALL            = re.compile( r'^# ADD (BASE |)BSC32' )
re_ADD_BSC32_BASE           = re.compile( r'^# ADD BASE BSC32' )
re_option_out_dir           = re.compile( r'/out:"(?P<subdir>[a-zA-Z0-9_ $\(\)\\/.]*?)"' )


################################################################################
class StringUtils:
    """Utilities class"""
    def replace( text, str, replac ):
        i = text.find( str )
        if ( i != -1 ):
            ls = len(str)
            text = text[:i] + replac + text[i+ls:]
        return text
    replace = staticmethod(replace)

    def stripSpacesInExcess( line ):
        # eliminates double spaces
        ( ln, crlf ) = StringUtils.getEol( line )
        if ( 0 < ln and ( line[ln-1] == ' ' or line[ln-1] == '\t' ) ):
            line = line[:ln-1]
        line = re.sub( '\s+', ' ', line )
        # also this would do the work
        # line = ' '.join( line.split() )

        # eliminates space at the eol
        ln = len( line )
        if ( 0 < ln and ( line[ln-1] == ' ' or line[ln-1] == '\t' ) ):
            line = line[:ln-1]

        line += crlf
        return line
    stripSpacesInExcess = staticmethod(stripSpacesInExcess)

    def getEol( line ):
        ln = len( line )
        if ( 0 < ln and line[ln-1] == '\n' ):
            ln -= 1
            if ( 0 < ln and line[ln-1] == '\r' ):
                ln -= 1
        return ( ln, line[ln:] )
    getEol = staticmethod(getEol)

    def trimCommas( text ):
        #if surrounded by commas, removes them
        ld = len( text )
        if ( 1 < ld ):
            if ( ( text[0] == '\'' and text[-1] == '\'' ) or ( text[0] == '\"' and text[-1] == '\"' ) ):
                text = text[1:-1]
        return text
    trimCommas = staticmethod(trimCommas)

    def stripComment( text, rightTrim = True ):
        #remove anything after tha last '#' unless it is before a comma
        i = text.find( '#' )
        if ( i != -1 ):
            # trivial implementaion disabled
            if ( False ):
                c = max(text.rfind('\''), text.rfind('\"') )
                if ( c < q ):
                    text = text[:q]
                    text = text.rstrip()

            t = text
            lt = len(t)
            pound  = 0
            apex   = False
            comma  = False
            escaped = False
            i = 0
            while ( i < lt ):
                c = t[i]
                if ( c == '\n' ):
                    break
                elif ( c == '#' ):
                    if ( not escaped ):
                        if ( not comma and not apex ):
                            pound += 1
                            break
                    escaped = False
                elif ( c == '\'' ):
                    if ( not escaped ):
                        if ( comma ):
                            raise Exception ( 'Unbalanced commas in text: ' + text )
                        apex = not apex
                    escaped = False
                elif ( c == '\"' ):
                    if ( not escaped ):
                        if ( comma ):
                            raise Exception ( 'Unbalanced apexes in text: ' + text )
                        comma = not comma
                    escaped = False
                elif ( c == '\\' ):
                    escaped = not escaped
                else:
                    escaped = False

                i += 1
                continue

            if ( pound ):
                text = text[:i]
                if ( rightTrim ):
                    text = text.rstrip()
        return text
    stripComment = staticmethod(stripComment)


################################################################################
class FileUtils:
    def backup( filename ):
        if ( len(filename) > 4 and filename[-4:] == '.bak' ):
                # does not backup backup files
            pass
        else :
            bakname = filename + '.bak'
            if ( os.path.exists( bakname ) ) :
                print 'removing ' + bakname
                os.remove( bakname )
                shutil.copyfile( fullname, bakname )
    backup = staticmethod(backup)

    def sameDrive( path1, path2 ):
        ( d1, p1 ) = os.path.splitdrive( path1 )
        ( d2, p2 ) = os.path.splitdrive( path2 )
        if ( len(d1) and len(d2) and d1 != d2 ):
            return False
        return True
    sameDrive = staticmethod(sameDrive)

    def normPathOS( path, unixStyle ):
        # gets rid of exceding './' ( included the first ) and of the final '/'
        path = os.path.normpath( path )
        path = path.replace("\\", "/")
        path = path.replace("//", "/")   # eliminates doubles
        if ( not unixStyle ):
            path = path.replace("/", "\\")

        return path
    normPathOS = staticmethod(normPathOS)

    def normDirOS( path, unixStyle ):
        if ( unixStyle ):
            sep = '/'
        else:
            sep = '\\'
        #path += '/' # this to make sure that os.path.dirname doesn't cut away the last part of the path
        #path = os.path.dirname( path )
        if ( path != '' ):
            path += sep # this to make sure that os.path.dirname doesn't cut away the last part of the path
        path = FileUtils.normPathOS( path, unixStyle )
        path += sep # we consider normalized a path with the slash at the end
        return path
    normDirOS = staticmethod(normDirOS)

    def getNormSep( unixStyle ):
        c = '/'
        if ( not unixStyle ):
            c = '\\'
        return c
    getNormSep = staticmethod(getNormSep)

    def absolutePath( workingpath, path, unixStyle ):
        if ( len( path ) == 0 ):
            raise Exception( 'absolutePath() relative path is empty' )

        workingpath = workingpath.replace("\\", "/")
        workingpath = workingpath.replace("//", "/")   # eliminates doubles
        wp = workingpath.find( './' )
        if ( wp != -1 ):
            raise Exception( 'absolutePath() malformed working path \'%s\' ' % workingpath )
            #workingpath = FileUtils.absolutePath( '', workingpath, unixStyle ) # this might solve well the problem: will check later

        if ( len ( workingpath ) == 0 ):
            workingpath = os.getcwd()
            workingpath = os.path.normpath( workingpath )

        path = path.replace("\\", "/")
        path = path.replace("//", "/")   # eliminates doubles

        workingpath = workingpath.replace("\\", "/")
        workingpath = workingpath.replace("//", "/")   # eliminates doubles

        if ( len ( workingpath ) == 0 ):
            raise Exception( 'absolutePath() couldn\'t get any working path ' )

        # extract current drive
        if ( not FileUtils.sameDrive( workingpath, path ) ):
            raise Exception( 'absolutePath() not same drive for %s and %s! ' % ( workingpath, path ) )

        # makes sure we don't add an absolute path to another one
        ( wdrive, wpath ) = os.path.splitdrive( workingpath )
        ( rdrive, rpath ) = os.path.splitdrive( path )
        
        if ( rpath[0] == '/' ):
                # path is already an absolute path let's just add the drive
            if ( len( rdrive ) == 0 ):
                path = wdrive + path
                return path

        rp = rpath.find( '../' )
        if ( rp != -1 ):
            rpath = path
            wpath = wpath
            if ( wpath[-1] == '/' ):
                wpath = wpath[:-1] # because we are going to wpath.rfind( sep )
            while ( rp != -1 ):
                rp = rpath.find( '../' )
                if ( rp != 0 ):
                    if ( rp == -1 ):
                        break
                    # a path like foo/../bar is malformed
                    raise Exception( 'absolutePath() malformed path \'%s\' ' % path )
                rpath = rpath[3:]
                wp = wpath.rfind( '/' )
                if ( wp != -1 ):
                    wpath = wpath[:wp]

            path = wdrive + wpath + '/' + rpath
        else:
            if ( rpath[0] == '/' ):
                # nothing to do: just make sure of the drive
                path = wdrive + '/' + rpath
            else:
                lp = len( path )
                if ( lp and rpath[0] == '.' ):
                    if ( 1 < lp and rpath[1] == '/' ):
                        # eliminates first './'
                        rpath = rpath[ 2:]
                    else:
                        raise Exception( 'absolutePath() malformed path \'%s\' ' % path )

                path = wdrive + wpath + '/' + rpath

        lastSep = ''
        if ( path and path[-1] == '/' ):
            lastSep = FileUtils.getNormSep( unixStyle )
        path = FileUtils.normPathOS( path, unixStyle ) # this eliminates the last '/' even if it is a dir
        path += lastSep

        return path
    absolutePath = staticmethod(absolutePath)

    def relativePath( basepath, path, minPathIsDot, unixStyle ):
        # the implementation currently assumes that only the basepath is a directories
        # but if the path was a directory for sure ( '/' or '\\' at the end ) then that quality is kept 
        if ( not FileUtils.sameDrive( basepath, path ) ):
            raise Exception( 'relativePath() not same drive for %s and %s! ' % ( basepath, path ) )

        sep = FileUtils.getNormSep( unixStyle )

        # manages all the '../' and conform the path as in basepath
        bpath = basepath
        bpath = bpath.replace("\\", "/")
        bpath += '/'                       # (*) make sure it has '/' at the end
        bpath = bpath.replace("//", "/")   # eliminates doubles

        rpath = path
        rpath = rpath.replace("\\", "/")
        rpath = rpath.replace("//", "/")   # eliminates doubles

        ( bdrive, bpath ) = os.path.splitdrive( bpath ) # %%% fixed: was basepath
        ( rdrive, rpath ) = os.path.splitdrive( rpath ) # %%% fixed: was path

        fromRelativePath = ( rpath and rpath[0] != '/' )

        if ( fromRelativePath ):
            rp = rpath.find( '../' )
            while ( rp != -1 ):
                if ( rp != 0 ):
                    # a path like foo/../bar is malformed
                    raise Exception( 'relativePath() malformed path \'%s\' ' % path )
                else:
                    rpath = rpath[3:]
                    bp = bpath.rfind( '/' )
                    if ( bp != -1 ):
                        bpath = bpath[:bp]
                    else:
                        bpath = ''
                rp = rpath.find( '../' )
                if ( bpath == '' ):
                    raise Exception( 'relativePath() too many \'../\': the relative path cannot go up past the root of the drive. ( basepath, path ) = ( %s, %s )' % ( basepath, path ) )
                continue
            
            # attention: normPathOS eliminates all the last '/', but of course not the initial dot. It instead creates '.' if rpath was ''
            wasDirectoryForSure = ( rpath and rpath[-1] == '/' )
            rpath = FileUtils.normPathOS( rpath, unixStyle )
            if ( minPathIsDot ):
                if ( rpath == '.' ):
                    path = rpath + sep
                else:
                    relCurrPath = '.' + sep # '/.' or '.\\' always standing for bdrive + bpath
                    path = relCurrPath + rpath
                    if ( wasDirectoryForSure ):
                        path += sep
            else:
                if ( rpath == '.' ):
                    path = ''
                else:
                    path = rpath            
                    if ( wasDirectoryForSure ):
                        path += sep
        else:
            relpath = ''
            bp = rp = 0
            if ( rp != -1 ):
                while ( bp != -1 and rp != -1 ):
                    bp = bpath.find( '/' )
                    rp = rpath.find( '/' )
                    if ( bp != -1 and rp != -1 ):
                        bs = bpath[:bp]
                        rs = rpath[:rp]
                        if ( bs.lower() == rs.lower() ):
                            bpath = bpath[bp+1:]
                            rpath = rpath[rp+1:]
                        else:
                            break

                bp = bpath.find( '/' )
                while ( bp != -1 ):
                    bp = bpath.find( '/' )
                    if ( bp != -1 ):
                        bs = bpath[:bp]
                        bpath = bpath[bp+1:]
                        relpath += '../'

                if ( minPathIsDot and relpath == '' ):
                    relpath = './'
    
                path = relpath + rpath
    
                if ( not unixStyle ):
                    path = path.replace("/", "\\")

        return path
    relativePath = staticmethod(relativePath)


################################################################################
class DspApp:
    def __init__(self):
        version = '0.0.1 - 28 feb 2004'

        self.initialCwd = os.getcwd()
        self.workingDir = self.initialCwd

        self.usage = "usage: \%prog [-f] [-r] [-q] [-v] firstarg secondarg"
        self.allowedDirsList = []
        self.allowedAbsoluteDirsList = []
        self.excludedSubdirsList = []
        self.changedFiles   = 0
        self.unchangedFiles = 0
        self.createdFiles   = 0

        self.section = ''

        optparser = OptionParser( self.usage )
        optparser.add_option(   "--@"                               , type = "string"  , dest = "fileconfig"                    , default=g_default_config, help="configuration file" )

        optparser.add_option(   "--workingDir"                      , type = "string"  , dest = "workingDir"                    , default='.'   , help="set the current directory, it uses os.getCwd() if empty" )

        optparser.add_option(   "-f", "--file"                      , type = "string"  , dest = "filename"                      , default=""    , help="process the specified filename only" )
        optparser.add_option(   "-r", "--recurse"                   , type = "int"     , dest = "recurse"                       , default=False , help="recursion into subdirectories" )

        optparser.add_option(   "-u", "--unixStyle"                 , type = "int"     , dest = "unixStyle"                     , default=True  , help="unix Style i.e. path with \'/\' instead than with \'\\\' " )

        optparser.add_option(   "-v", "--verbose"                   , type = "int"     , dest = "verbose"                       , default=False , help="verbose level" )
        optparser.add_option(   "-p", "--prompt"                    , type = "int"     , dest = "prompt"                        , default=True  , help="ask to press any key before continuing" )

        optparser.add_option(   "-w", "--createWorkspace"           , type = "int"     , dest = "createWorkspace"               , default=True  , help="creates a workspace with all the projects we worked with ( i.e. in the allowed directories )" )
        optparser.add_option(   "--workspaceName"                   , type = "string"  , dest = "workspaceName"                 , default='./workspace.dsw' , help="directory where the created workspace will be located and its name" )
        optparser.add_option(   "--dependenciesWorkspace"           , type = "string"  , dest = "dependenciesWorkspace"         , default=''    , help="workspace with all the dependencies to copy into the workspaceName workspace" )

        optparser.add_option(   "--enableVcfSpecific"               , type = "int"     , dest = "enableVcfSpecific"             , default=True  , help="enable any vcf-specific action" )
        optparser.add_option(   "--modifyVc6"                       , type = "int"     , dest = "modifyVc6"                     , default=True  , help="enable any modification on the original vc6 files" )

        optparser.add_option(   "--deleteLines"                     , type = "int"     , dest = "deleteLines"                   , default=True  , help="eliminates all lines with string given in deleteLineString" )
        optparser.add_option(   "--deleteLineString"                , type = "string"  , dest = "deleteLineString"              , default=''    , help="string to find for lines to be deleted ( see deleteLines ) ( i.e. \'# PROP Scc_\'" )
        optparser.add_option(   "--conformLibsToDlls"               , type = "int"     , dest = "conformLibsToDlls"             , default=True  , help="conforms the folders of dsp library projects to the ones of the project for the Dll version( the association table is in inside the code )" )
        optparser.add_option(   "--reformatOutputIntermediateDirs"  , type = "int"     , dest = "reformatOutputIntermediateDirs", default=True  , help="reformat the Output Directories [note though that in normal cases we want /out: and vc6 removes the /Fo option ]"        )
        optparser.add_option(   "--reformatOptionOutput"            , type = "int"     , dest = "reformatOptionOutput"          , default=True  , help="reformat the option Output                 /Fo"     )
        
        optparser.add_option(   "--reformatOptionPdb"               , type = "int"     , dest = "reformatOptionPdb"             , default=False , help="reformat/delete the option ProgramDatabase /pdb"    )
        optparser.add_option(   "--reformatOptionBrowse"            , type = "int"     , dest = "reformatOptionBrowse"          , default=False , help="reformat/delete the option Browse          /Br"     )

        optparser.add_option(   "--copyToVc70"                      , type = "int"     , dest = "copyToVc70"                    , default=False , help="copy dsp files in corresponding directories for vc70 ( option VCF specific )" )
        optparser.add_option(   "--copyToVc71"                      , type = "int"     , dest = "copyToVc71"                    , default=False , help="copy dsp files in corresponding directories for vc71 ( option VCF specific )" )

        optparser.add_option(   "--allowDirs"                       , type = "int"     , dest = "allowDirs"                     , default=True  , help="works only with selected directories and its subdirectories" )
        optparser.add_option(   "--excludeSubdirs"                  , type = "int"     , dest = "excludeSubdirs"                , default=False , help="exclude the subdirectories containing the strings specified in the excludeSubdirs section" )

        (self.options, args) = optparser.parse_args()
        #if ( len(args) != 1 ):
        #    optparser.error("incorrect number of arguments")

        #import types
        self.config = ConfigParser.ConfigParser()
        self.readConfigFile()

        # make sure '/? doesn't let the program to start
        i = -1
        for s in sys.argv:
            i += 1
            if ( 0 < i and s and s[0] == '/' ):
                if ( s == '/?' or s.lower() == '/h' or s.lower() == '/help' ):
                #optparser.print_usage()
                    optparser.print_help()
                    raise Exception( 'invalid option: ' + s )

        if ( 0 < self.options.verbose ):
            self.printOptions()
            if (len (self.options.filename) ):
                print "reading %s ..." % self.options.filename

        return

    def printOptions( self ):
        #defaults = optparser.defaults
        #if defaults:
        #    for (attr, val) in defaults.items():
        #        #setattr(self, attr, val)
        #        x = getattr( self.options, attr )
        #        if type(x) is str:
        #            print attr + ' = ' + x
        #        if type(x) is int:
        #            print attr + ' = ' + x
        #        print attr + ' = ' + x

        print '[' + self.section + ']'
        print ' --workingDir                 = ' + str(self.currentdir                       )
        print ''
        print ' --@= ' + str(self.options.fileconfig)
        print ''
        print ' --file           = \'' + str(self.options.filename) + '\''
        print ' --recurse        = ' + str(self.options.recurse)
        print ' --verbose        = ' + str(self.options.verbose)
        print ' --prompt         = ' + str(self.options.prompt )
        print ''
        print ' --unixStyle      = ' + str(self.options.unixStyle)
        print ''
        print ' --enableVcfSpecific              = ' + str(self.options.enableVcfSpecific               )
        print ''
        print ' --modifyVc6                      = ' + str(self.options.modifyVc6                       )
        print ''
        print ' --createWorkspace                = ' + str(self.options.createWorkspace                 )
        print ' --workspaceName                  = ' + str(self.options.workspaceName                   )
        print ' --dependenciesWorkspace          = ' + str(self.options.dependenciesWorkspace           )
        print ''
        print ' --deleteLines                    = ' + str(self.options.deleteLines                     )
        print ' --deleteLineString               = \'' + str(self.options.deleteLineString              ) + '\''
        print ' --conformLibsToDlls              = ' + str(self.options.conformLibsToDlls               )
        print ' --reformatOutputIntermediateDirs = ' + str(self.options.reformatOutputIntermediateDirs  )
        print ' --reformatOptionOutput           = ' + str(self.options.reformatOptionOutput            )

        print ''
        print ' --reformatOptionPdb              = ' + str(self.options.reformatOptionPdb               )

        if ( self.options.reformatOptionBrowse == +1 ):
            print ' --reformatOptionBrowse           = ' + str(self.options.reformatOptionBrowse            ) + ' ( the bsc file will be placed in the same dir of the main output ! )'
        else:
            print ' --reformatOptionBrowse           = ' + str(self.options.reformatOptionBrowse            )

        print ' --copyToVc70                     = ' + str(self.options.copyToVc70                      )
        print ' --copyToVc71                     = ' + str(self.options.copyToVc71                      )

        print ' --allowDirs      = ' + str(self.options.allowDirs)
        if ( self.options.allowDirs ):
            print '   ' + str( self.allowedDirsList )
        print ' --excludeSubdirs = ' + str( self.options.excludeSubdirs )
        if ( self.options.excludeSubdirs ):
            print '   ' + str( self.excludedSubdirsList )
        print ''

        return

    def configGetStr( self, section, option ):
        s = self.config.get( section, option )
        s = StringUtils.stripComment( s )
        s = StringUtils.trimCommas( s )
        return s

    def configGetInt( self, section, option ):
        s = self.configGetStr( section, option )
        value = eval( s )
        return value

    def configGetBool( self, section, option ):
        s = self.configGetStr( section, option )
        return eval ( s )
        if ( False ):
            s = s.lower()
            if ( s == 'true' ):
                value = 1
            elif ( s == 'false' ):
                value = 0
            else:
                value = eval( s )

        return value

    def toBoolStr( self, val ):
        if ( val ):
            s = 'True'
        else:
            s = 'False'
        return s

    def readConfigFile( self ):
        if ( self.options.fileconfig and os.path.exists( self.options.fileconfig ) ):
            self.config.read( self.options.fileconfig )
            if ( self.config.has_section( 'activesection' ) ):
                section = self.configGetStr ( 'activesection', 'section' )
                self.section = section
                if ( self.config.has_section( section ) ):
                    section_dirlist                             = self.configGetStr ( section, 'section_dirlist'                )
                    section_excludesubdirlist                   = self.configGetStr ( section, 'section_excludesubdirlist'      )

                    self.options.filename                       = self.configGetStr ( section, 'file'                           )
                    self.options.recurse                        = self.configGetBool( section, 'recurse'                        )
                    self.options.verbose                        = self.configGetInt ( section, 'verbose'                        )
                    self.options.prompt                         = self.configGetInt ( section, 'prompt'                         )

                    self.options.unixStyle                      = self.configGetBool( section, 'unixStyle'                      )
                    self.options.deleteLines                    = self.configGetBool( section, 'deleteLines'                    )
                    self.options.deleteLineString               = self.configGetStr ( section, 'deleteLineString'               )
                    self.options.conformLibsToDlls              = self.configGetBool( section, 'conformLibsToDlls'              )

                    self.options.reformatOutputIntermediateDirs = self.configGetInt( section, 'reformatOutputIntermediateDirs'  )
                    self.options.reformatOptionOutput           = self.configGetInt( section, 'reformatOptionOutput'            )
                    self.options.reformatOptionPdb              = self.configGetInt( section, 'reformatOptionPdb'               )
                    self.options.reformatOptionBrowse           = self.configGetInt( section, 'reformatOptionBrowse'            )

                    self.options.enableVcfSpecific              = self.configGetBool( section, 'enableVcfSpecific'              )
                    self.options.modifyVc6                      = self.configGetBool( section, 'modifyVc6'                      )
                    self.options.copyToVc70                     = self.configGetBool( section, 'copyToVc70'                     )
                    self.options.copyToVc71                     = self.configGetBool( section, 'copyToVc71'                     )

                    self.options.workingDir                     = self.configGetStr ( section, 'workingDir'                     )
                    self.options.createWorkspace                = self.configGetBool( section, 'createWorkspace'                )
                    self.options.workspaceName                  = self.configGetStr ( section, 'workspaceName'                  )
                    self.options.dependenciesWorkspace          = self.configGetStr ( section, 'dependenciesWorkspace'          )
                    self.options.allowDirs                      = self.configGetBool( section, 'allowDirs'                      )
                    self.options.excludeSubdirs                 = self.configGetBool( section, 'excludeSubdirs'                 )

                    if ( self.options.workingDir == '' ):
                        self.currentdir = os.getcwd()
                    else:
                        self.currentdir = FileUtils.normDirOS( self.options.workingDir, True )
                        if ( self.currentdir.find( './' ) != -1 ):
                            self.currentdir = FileUtils.absolutePath( os.getcwd(), self.currentdir, self.options.unixStyle )

                    # please, make sure the name contains the dirname too
                    self.options.workspaceName = FileUtils.relativePath( self.currentdir, self.options.workspaceName, True, self.options.unixStyle )
                    if ( self.options.workspaceName == '.' + FileUtils.getNormSep( self.options.unixStyle ) ): self.options.workspaceName = ''
                    self.options.dependenciesWorkspace = FileUtils.relativePath( self.currentdir, self.options.dependenciesWorkspace, True, self.options.unixStyle )
                    if ( self.options.dependenciesWorkspace == '.' + FileUtils.getNormSep( self.options.unixStyle ) ): self.options.dependenciesWorkspace = ''

                    if ( self.options.allowDirs ):
                        if ( self.config.has_section( section_dirlist ) ):
                            dirpairs = self.config.items( section_dirlist )
                            self.allowedDirsList = []
                            for dir in dirpairs:
                                ( namesection, namedir ) = dir
                                namedir = StringUtils.stripComment( namedir )
                                namedir = StringUtils.trimCommas( namedir )
                                namedir = namedir.lower()
                                namedir = FileUtils.normDirOS( namedir, self.options.unixStyle )
                                self.allowedDirsList.append( namedir )
                                absNamedir = FileUtils.absolutePath( self.currentdir, namedir, self.options.unixStyle )
                                self.allowedAbsoluteDirsList.append( absNamedir )
                        else:
                            raise Exception( 'The section \'%s\' in the config file \'%s\' does not exists !' % ( section_dirlist, self.options.fileconfig ) )

                    if ( self.options.excludeSubdirs ):
                        if ( self.config.has_section( section_excludesubdirlist ) ):
                            dirpairs = self.config.items( section_excludesubdirlist )
                            self.excludedSubdirsList = []
                            for dir in dirpairs:
                                ( namesection, namedir ) = dir
                                namedir = StringUtils.stripComment( namedir )
                                namedir = StringUtils.trimCommas( namedir )
                                namedir = namedir.lower()
                                namedir = FileUtils.normDirOS( namedir, self.options.unixStyle )
                                self.excludedSubdirsList.append( namedir )
                        else:
                            raise Exception( 'The section \'%s\' in the config file \'%s\' does not exists !' % ( section_excludesubdirlist, self.options.fileconfig ) )
                else:
                    raise Exception( 'The section \'%s\' in the config file \'%s\' does not exists !' % ( section, self.options.fileconfig ) )
            else:
                raise Exception( 'The section \'%s\' in the config file \'%s\' does not exists !' % ( 'activesection', self.options.fileconfig ) )
        else:
            raise Exception( 'The config file \'%s\' does not exists !' % self.options.fileconfig )

        return

    def checkAllowedDir( self, filename ):
        allow = True
        if ( app.options.allowDirs or app.options.excludeSubdirs ):
            fn = filename.lower()
            fn = os.path.dirname( fn )
            if ( fn == '' ):
                fn = './'
            fn = FileUtils.normDirOS( fn, self.options.unixStyle ) # add last sep

            if ( app.options.allowDirs ):
                allow = False
                fnAbs = FileUtils.absolutePath( app.currentdir, fn, self.options.unixStyle )
                for subdir in app.allowedAbsoluteDirsList:
                    if ( fnAbs.find(subdir) != -1 ):
                        allow = True
                        break

            if ( allow and app.options.excludeSubdirs ):
                fnRel = FileUtils.relativePath( app.currentdir, fn, True, self.options.unixStyle )
                for subdir in app.excludedSubdirsList:
                    if ( fnRel.find(subdir) != -1 ):
                        allow = False
                        break

        return allow


################################################################################
class Workspace:
    """Creates a workspace with all projects in Visual Studio 6."""
    def __init__( self, workspacename ):
        self.prjNames = []
        self.prjPaths = []
        self.workspacename = ''
        self.setName( workspacename )
        self.dependencies = {}

    def setName( self, workspacename ):
        self.workspacename = workspacename
        # makes sure it has the '.dsw. extension
        ( root, ext ) = os.path.splitext( self.workspacename )
        if ( ext == '' ):
            self.workspacename = root + '.dsw'

        workspaceDirname = os.path.dirname( workspacename )
        if ( not os.path.exists( workspaceDirname ) ):
            msg = 'The directory for the workspace \'%s\' does not exist. Create it [y/n] ?' % workspacename
            c = raw_input( msg ).lower
            if ( c == 'y' or c == 'yes' ):
                os.makedirs( workspaceDirname )
            else:
                raise Exception( 'Workspace\'s directory \'%s\' not created !' % workspaceDirname )
        return

    def setProjects( self, prjNames, prjPaths ):
        self.prjNames = prjNames
        self.prjPaths = prjPaths

    def create( self ):
        self.getWorkspaceDependencies( app.options.dependenciesWorkspace )

        workspacedirname = os.path.dirname( self.workspacename )
        if ( not os.path.exists( workspacedirname ) ):
            raise Exception( 'Workspace directory \'%s\' does not exist.\n           It should have been already created !' % workspacedirname )

        if ( os.path.exists( self.workspacename ) ):
            os.remove( self.workspacename )

        fd = file( self.workspacename, 'w' );

        header =  'Microsoft Developer Studio Workspace File, Format Version 6.00\n'
        header += '# WARNING: DO NOT EDIT OR DELETE THIS WORKSPACE FILE!\n'
        header += '\n'
        header += '###############################################################################\n'
        header += '\n'
        fd.writelines( header )


        #'Project: "%s"="%s" - Package Owner=<4>\n'
        prjBody1 =  '\n'
        prjBody1 += 'Package=<5>\n'
        prjBody1 += '{{{\n'
        prjBody1 += '}}}\n'
        prjBody1 += '\n'
        prjBody1 += 'Package=<4>\n'
        prjBody1 += '{{{\n'
        #'    Begin Project Dependency'
        #'    Project_Dep_Name Dialogs'
        #'    End Project Dependency'
        prjBody2 =  '}}}\n'
        prjBody2 += '\n'
        prjBody2 += '###############################################################################\n'
        prjBody2 += '\n'

        #sorting
        projects = zip( self.prjNames, self.prjPaths )
        projects.sort()

        dependencyStringList = ''
        for (prjName, prjPath) in projects:
            relPrjPath = FileUtils.relativePath( workspacedirname, prjPath, True, app.options.unixStyle )

            prjLine = r'Project: "' + prjName + r'"="' + relPrjPath + '" - Package Owner=<4>\n'
            fd.writelines( prjLine )

            fd.writelines( prjBody1 )

            if ( self.dependencies ):
                if ( self.dependencies.has_key( prjName ) ):
                    dependencyStringList = self.dependencies[ prjName ]
                    if ( dependencyStringList ):
                        fd.writelines( dependencyStringList )

            fd.writelines( prjBody2 )

        fd.close

        print ' created workspace: %s' % self.workspacename
        
        return

    def addProject( self, prjName, prjPath ):
        self.prjNames.append( prjName )
        self.prjPaths.append( prjPath )
        return

    def getWorkspaceDependencies( self, dependencyWorkspaceName ):
        self.dependencies.clear()

        if ( not dependencyWorkspaceName ):
            return

        dependencyWorkspaceDirname = os.path.dirname( dependencyWorkspaceName )
        if ( not os.path.exists( dependencyWorkspaceDirname ) ):
            raise Exception( 'Dependency Workspace directory \'%s\' does not exist !\n' % dependencyWorkspaceDirname )
        if ( not os.path.exists( dependencyWorkspaceName ) ):
            raise Exception( 'Dependency Workspace \'%s\' does not exist !\n' % dependencyWorkspaceName )

        fw = file( dependencyWorkspaceName, 'r' );
        wlines = fw.readlines()
        fw.close

        rec = re.compile( r'Project:\s*?"(?P<prjName>[a-zA-Z0-9_ ]*?)"\s*?=' )

        dependencyStringList = ''
        state = 0
        nPrjs = 0
        for n in range( len( wlines ) ):
            line = wlines[n]

            if ( state == 0 ):
                dependencyStringList = ''
                m = rec.match( line )
                if ( m ):
                    prjName = m.group('prjName')
                    if ( not prjName ):
                        raise Exception( 'Error: no project extracted from line [%d]: %s' % ( n, line ) )
                    nPrjs += 1
                    state = 1
            elif ( state == 1 and re.match( 'Package=<4>', line ) ):
                state = 2
            elif ( state == 2 and re.match( '{{{', line ) ):
                state = 3
            elif ( state == 3 ):
                if ( re.match( '}}}', line ) ):
                    self.dependencies[ prjName ] = dependencyStringList
                    state = 0
                else:
                    dependencyStringList += line
            else:
                pass

        nDeps = len( self.dependencies )
        if ( nDeps != nPrjs ):
            raise Exception( 'dependencies[%d] != nPrjs[%d] ( state[%d] ). Workspace: %s' % ( nDeps, nPrjs, state, dependencyWorkspaceName ) )
        elif ( state != 0 ):
            raise Exception( 'wrong state: [%d]  ( but dependencies[%d] == nPrjs[%d] ). Workspace: %s' % ( state, nDeps, nPrjs, dependencyWorkspaceName ) )

        return

    def conformLibsToDlls( self ):
        if ( not app.options.conformLibsToDlls ):
            return
        
        # %%%
        #tableAssocLib = [ ( 'FoundationKit'  , 'FoundationKitDll'   ), \
        #                  ( 'GraphicsKit'    , 'GraphicsKitDll'     ), \
        #                  ( 'ApplicationKit' , 'ApplicationKitDll'  ), \
        #                  ( 'NetworkKit'     , 'NetworkKitDll'      ), \
        #                  ( 'RemoteObjectKit', 'RemoteObjectKitDll' )  \
        #                ]
               
        # first check if the libs exist
        
        #sorting to spead up the search
        projects = zip( self.prjNames, self.prjPaths )
        projects.sort()

        # very brute force search
        #for ( libname, dllname ) in tableAssocLib # %%%
        if ( False ):
            libNameFound = ''
            dllNameFound = ''
            lw_libname = libname.lower()
            lw_dllname = dllname.lower()
            for (prjName, prjPath) in projects:
                prjName = prjName.lower()
                if ( prjName == lw_libname ):
                    libNameFound = libname
                    libPath = prjPath
                    break
            for (prjName, prjPath) in projects:
                prjName = prjName.lower()
                if ( prjName == lw_dllname ):
                    dllNameFound = libname
                    dllPath = prjPath
                    break
                
            if ( libPath and dllPath ):
                conformLibToDll( self, libPath, dllPath )
            else:
                print 'conformLibsToDlls: ( libPath, dllPath ) not found: ( %s, %s )' % ( libNameFound, dllNameFound )
        
        conformLibToDll( self, libname, dllname )
        
        print ' libraries conformed.'
        return
 
    def conformLibToDll( self, libname, dllname ):
        dr = DspFile( app, libname )
        dr.readlines()
        
        dw = DspFile( app, dllname )
        dw.readlines()
        
        target = dr.readTarget()
        
        dw.replaceTarget( target )        

        print ' conformed library \'%s\' <-- dll \'%s\'', ( libname, dllname )
        
        return


################################################################################
class DspFile:
    """Process and reformat dsp files as in Visual Studio 6."""

    def __init__( self, app, filename ):

        self.app = app
        self.filename = filename
        self.filetitle = os.path.basename( filename )

        self.lines = []
        self.n = 0
        self.storedOptions = []
        self.lastGroupFound = '' # for debug only

        self.isDebugCfg  = []
        self.isStaticCfg = []

        self.PropOutputDirList  = []    # directory for output
        self.PropIntermeDirList = []    # directory for intermediate output
        self.OutputDirOutList   = []    # directory for main output ( it is usually the same as PropOutputDirList, but sometimes we want to /out: somewhereelse )
        self.MainFileTitleList = []     # unused ?
        self.MainFileTitleUnique = ''
        self.outputExt = ''

        self.PropOutputDir  = ''
        self.PropIntermeDir = ''
        self.OutputDirOut   = ''

        self.appType = enumAppTypeNone

        self.trueProjectName = ''
        self.projectName = ''
        self.configName = ''
        self.addKind = enum_ADD_NONE

        self.origStr = ''
        self.copyStr = ''

    def reset( self ):
        self.lines = []
        self.n = 0
        self.storedOptions = []
        self.lastGroupFound = '' # for debug only

        self.isDebugCfg  = []
        self.isStaticCfg = []

        self.PropOutputDirList  = []    # directory for output
        self.PropIntermeDirList = []    # directory for intermediate output
        self.OutputDirOutList   = []    # directory for main output ( it is usually the same as PropOutputDirList, but sometimes we want to /out: somewhereelse )
        self.MainFileTitleList = []     # unused ?
        self.MainFileTitleUnique = ''
        self.outputExt = ''

        self.PropOutputDir  = ''
        self.PropIntermeDir = ''
        self.OutputDirOut   = ''

        self.appType = enumAppTypeNone

        self.trueProjectName = ''
        self.projectName = ''
        self.configName = ''
        self.addKind = enum_ADD_NONE

        self.origStr = ''
        self.copyStr = ''

    def setTrueProjectName( self, trueProjectName ):
        self.trueProjectName = trueProjectName

    def getTrueProjectName( self ):
        return self.trueProjectName

    def reformat( self ):
        self.readlines()
        self.process()
        if ( app.options.modifyVc6 ):
            self.saveFile()

    def duplicateVc( self, origStr, copyStr ):
        self.reset()
        dsp.origStr = origStr
        dsp.copyStr = copyStr
        dsp.readlines()
        dsp.replaceConfig( origStr, copyStr, True )
        filename = dsp.getDuplicateVcFilename( dsp.origStr, dsp.copyStr )
        dsp.saveFile( filename )
        if ( 1 < app.options.verbose ):
            if ( not app.options.modifyVc6 or 2 < app.options.verbose ): # 1 level more if we modifyVc6
                print 'duplicating: ' + filename

    def readlines(self):
        fs = file( self.filename, 'r' );

        # Get the new lines
        self.lines = fs.readlines()
        fs.close

    def saveFile( self, dest = '' ):
        destination = dest
        if ( not destination ):
            destination = self.filename

        tmpFilename = destination + '.$x$y$'
        #print 'tmpFilename ' + tmpFilename
        if ( os.path.exists( tmpFilename ) ) :
            os.remove( tmpFilename );
            
        fd = file( tmpFilename, 'w' );
        fd.writelines( self.lines )
        fd.close()

        if ( not os.path.exists( tmpFilename ) ) :
            raise Exception( 'saveFile() - the temporary file \'%s\' had not been created !' % source )

        self.replaceFile( tmpFilename, self.filename )
            
        return

    def replaceFile( self, source, destination ):

        if ( not os.path.exists( source ) ) :
            raise Exception( 'replaceFile() - the source file \'%s\' does not exist!' % source )
        
        if ( os.path.exists( destination ) ) :
            if ( not filecmp.cmp( source, destination ) ):
                # some changes
                os.remove( destination )
                os.rename( source, destination )
                app.changedFiles += 1
            else:
                # no changes
                os.remove( source )
                app.unchangedFiles += 1
                
            #if ( False ):
            #    shutil.copyfile( source, destination )
            #    if ( os.path.exists( source ) ) :
            #        os.remove( source ) # ' OSError: [Errno 13] Permission denied ' Why ???
        else:
            app.createdFiles += 1
            os.rename( source, destination )

        return

    def replaceConfig( self, origStr, copyStr, onlyInsideConfig ):
        insideCfg = False
        self.nCfg = -1

        sep = FileUtils.getNormSep( self.options.unixStyle )
        origStrUndrscor = '_' + origStr
        lenStrUndrscor = len( origStrUndrscor )
        copyStrUndrscor = '_' + copyStr

        origStrSubdir = origStr + sep
        lenStrSubdir = len( origStrSubdir )
        copyStrSubdir = copyStr + sep

        insideCfg = False
        if ( not onlyInsideConfig ):
            insideCfg = True

        for n in range( len(self.lines) ):
            line = self.lines[n]
            self.n = n

            #* exit after end of CFG section
            if ( line.find( '# Begin Target' ) != -1 ):
                insideCfg = False
                break

            if ( onlyInsideConfig ):
                if ( line[0] == '!' ):
                    m = re_configuration.search( line )
                    if ( m ):
                        insideCfg = True

            if ( insideCfg ):
                changed = False
                i = 0
                while ( i != -1 ):
                    i = line.find( origStrUndrscor )
                    if ( i != -1 ):
                        line = line[:i] + copyStrUndrscor + line[i+lenStrUndrscor:]
                        changed = True
                i = 0
                while ( i != -1 ):
                    i = line.find( origStrSubdir )
                    if ( i != -1 ):
                        line = line[:i] + copyStrSubdir + line[i+lenStrSubdir:]
                        changed = True

                if ( changed ):
                    self.lines[n] = line # apply changes

        return


    def readTarget( self ):
        # skips all the configuration lines and copy the all the target body into a string
            
        target = ''
        state = 0
        for n in range( len(self.lines) ):
            line = self.lines[n]
            self.n = n

            # skips the configurations body    
            if ( state == 0 and re.match( '# Begin Target', line ) ):
                state = 1
                break
        
            elif ( state == 1 and re.match( '# Begin Group', line ) ):
                state = 2
                
            elif ( state == 2 ):
                if ( re.match( '# End Target', line ) ):
                    state = 3
                else:
                    target += line
                
            elif ( state == 3 and re.match( '# End Project', line ) ):
                target += line
                state = 4
            
            else:
                pass
        
        if ( state != 4 ):
            raise Exception( 'wrong final state: [%d]. Read %d lines in \'%s\'' % ( state, self.n, self.filename ) )
        
        return target

    def readOutsideTarget( self ):
        # skips all the configuration lines and copy the all the target body into a string
            
        preTarget = ''
        postTarget = ''
        state = 0
        for n in range( len(self.lines) ):
            line = self.lines[n]
            self.n = n

            # skips the configurations body    
            if ( state == 0 ):
                preTarget += line
                if ( re.match( '# Begin Target', line ) ):
                    state = 1
        
            elif ( state == 1 ):
                # the part with the application names is still very specific of this project so we copy this one part too
                preTarget += line
                if ( re.match( '# Begin Group', line ) ):
                    state = 2                
                
            elif ( state == 2 ):
                if ( re.match( '# End Target', line ) ):
                    postTarget += line
                    state = 3
                
            elif ( state == 3 ):
                postTarget += line
                if ( re.match( '# End Project', line ) ):
                    state = 4
                                
            else:
                pass
        
        if ( state != 4 ):
            raise Exception( 'wrong final state: [%d]. Read %d lines in \'%s\'' % ( state, self.n, self.filename ) )
        
        return ( preTarget, postTarget )
    
    def replaceTarget( self, preTarget, target, postTarget ):
        tmpFilename = self.filename + '.$x$y$'
        
        #print 'tmpFilename ' + tmpFilename
        if ( os.path.exists( tmpFilename ) ) :
            os.remove( tmpFilename );
            
        fd = file( tmpFilename, 'w' );
        fd.writelines( preTarget )
        fd.writelines( target )
        fd.writelines( postTarget )
        fd.close()

        if ( not os.path.exists( tmpFilename ) ) :
            raise Exception( 'replaceTarget() - the temporary file \'%s\' had not been created !' % source )

        replaceFile( self, tmpFilename, self.filename )
        
        return    
    
    def getDuplicateVcFilename( self, origStr, copyStr ):
        # if the filename is under a origStr/ subdirectory then it is copied into a copyStr/ subdirectory
        # otherwise is copied into a _copyStr file in the same directory

        filename = self.filename
        filename = FileUtils.normPathOS( filename, app.options.unixStyle )
        fn = filename.lower()

        sep = FileUtils.getNormSep( app.options.unixStyle )
        sd = origStr.lower() + sep
        if ( app.options.enableVcfSpecific ):
            if ( origStr == compilerVc6 ):
                sd = origStr.lower() + '0' + sep
        i = fn.find( sd )
        if ( i != -1 ):
            # copied into a copyStr/ subdirectory
            lsd = len( sd )
            filename = filename[:i] + copyStr + sep + filename[i+lsd:]

            fn = os.path.dirname( filename )
            if ( not os.path.exists(fn) ):
                os.makedirs( fn )
        else:
            # copied into a _copyStr file in the same directory
            replaced = False
            ( basename, ext ) = os.path.splitext( filename )
            bn = basename.lower()
            su = '_' + origStr.lower() # compilerVc70
            i = bn.find( su )
            if ( i != -1 ):
                lsu = len( su )
                basename = basename[:i] + '_' + copyStr + basename[i+lsu:]
                replaced = True

            if ( replaced ):
                filename = basename + ext
            else:
                filename = basename + '_' + copyStr + ext

        return filename

    def process(self):
        self.removeLinesUnwanted()

        self.getOutputTypeAndDir()
        self.modifyLines()

    def removeLinesUnwanted( self ):
        if ( app.options.deleteLines ):
            self.removeLines( False )

    def removeLines( self, ignorecase ):
        deleteLineString = app.options.deleteLineString
        if ( app.options.deleteLines ):
            if ( ignorecase ):
                deleteLineString = deleteLineString.lower()
            for i in range( len(self.lines)-1, -1, -1 ):
                if ( ignorecase ):
                    line = self.lines[i].lower()
                else:
                    line = self.lines[i]
                if ( line.find( deleteLineString ) == 0 ) :
                # removes line i
                    self.lines[i:i+1] = []
                    continue

    def getOutputTypeAndDir( self ):
        insideCfg = False
        self.nCfg = -1
        self.projecName = ''
        self.configName = ''

        for n in range( len(self.lines) ):
            line = self.lines[n]
            self.n = n

            #* exit after end of CFG section
            if ( line.find( '# Begin Target' ) != -1 ):
                insideCfg = False
                break

            if ( self.n < 3 ):
                m = re_trueproject.match( line )
                if ( m ):
                    self.trueProjectName = m.group('trueProjectName')
                    self.setTrueProjectName( self.trueProjectName )
                    continue

            #!IF  "$(CFG)" == "ApplicationKit - Win32 Release"
            if ( line[0] == '!' ) :
                m = re_configuration.search( line )
                if ( m ):
                    insideCfg = True
                    self.nCfg += 1
                    self.OutputDirOutList  .append( '')
                    self.PropOutputDirList .append( '')
                    self.PropIntermeDirList.append( '')
                    self.MainFileTitleList .append( '') # unused ?
                    self.projectName = m.group('projectName')
                    self.platform    = m.group('platform').rstrip() # we don't really need it
                    self.configName  = m.group('configName')
                    continue

            #* Modify 'PROP Intermediate_Dir "vc6/ReleaseDLL\obj"' and set intermediateDir
            if ( 0 <= self.nCfg ):
                #if ( self.appType == enumAppTypeNone ):
                #isStaticlib = False
                if ( re_PROP.search( line ) ):
                    if ( re_output_or_intermed_dir.match( line ) ):
                    #* Fix bug 'Debug' word in 'Release' CFG:
                        if ( self.configName == 'Release' ) :
                            line = line.replace( 'Debug', 'Release' )
                            self.lines[n] = line

                        self.extractOutputIntermDir( line )
                        continue

                elif ( re_ADD.search( line ) ):
                    # try for dll or exe
                    if ( re_ADD_LINK32.match( line ) ):
                        if ( line.find( r'/dll' ) != -1 ):
                            self.appType = enumAppTypeDll
                            self.outputExt = '.dll'
                        self.extractMainOutDir( line )
                        continue

                    # try for lib
                    elif ( re_ADD_LIB32.match( line ) ):
                        #isStaticlib = True
                        self.appType = enumAppTypeLib
                        self.outputExt = '.lib'
                        self.extractMainOutDir( line )
                        continue

                #if ( re_LIB32_static.match( line ) ):
                #    self.appType = enumAppTypeLib
                #    self.outputExt = '.lib'
                #    isStaticlib = True
                #    continue


        pass # end for

        if ( self.appType == enumAppTypeNone ):
            self.appType = enumAppTypeExe
            self.outputExt = '.exe'

        return

    def modifyLines( self ):
        self.nCfg = -1
        insideCfg = False
        self.isDebugCfg  = []
        self.isStaticCfg = []
        self.projecName = ''
        self.configName = ''

        for n in range( len(self.lines) ):
            line = self.lines[n]
            self.n = n

            if ( line.find( '# Begin Target' ) != -1 ):
                insideCfg = False
                break

            #!IF  "$(CFG)" == "ApplicationKit - Win32 Release"
            if ( line[0] == '!' ):
                m = re_configuration.search( line )
                if ( m ):
                    insideCfg = True
                    self.nCfg += 1
                    self.projectName = m.group('projectName')
                    self.platform    = m.group('platform').rstrip() # we don't really need it
                    self.configName  = m.group('configName')

                    configName  = self.configName.lower()
                    self.isDebugCfg .append( configName.find( 'debug'  ) != -1 )
                    self.isStaticCfg.append( configName.find( 'static' ) != -1 )

                    #if ( self.MainFileTitleUnique != '' ):
                    #    fileTitle = self.MainFileTitleUnique
                    #else:
                    #    fileTitle = projectName

                    self.PropOutputDir  = self.PropOutputDirList [self.nCfg]
                    self.PropIntermeDir = self.PropIntermeDirList[self.nCfg]
                    self.OutputDirOut   = self.OutputDirOutList  [self.nCfg]
                    #mainCurrOutpDir = self.MainCurrOutpDir
                    continue

            #* Modify 'PROP Intermediate_Dir "vc6/ReleaseDLL\obj"' and set intermediateDir
            if ( 0 <= self.nCfg ):
                changed = False
                if ( re_PROP.search( line ) ):
                    if ( app.options.reformatOutputIntermediateDirs == 1 ):
                        m = re_output_or_intermed_dir.match( line )
                        if ( m ):
                            subdir = m.group('subdir')
                            line = self.addReformatOutputIntermediateDirs( line, subdir )
                            changed = True

                else:
                    if ( re_ADD_CPP.match( line ) ):
                        self.addKind = enum_ADD_CPP
                        line = self.changeOptionsCpp( line )
                        changed = True

                    elif ( re_SUBTRACT_CPP.match( line ) ):
                        self.addKind = enum_SUBTRACT_CPP
                        line = self.changeOptionsCpp( line )
                        changed = True

                    elif ( re_ADD_LINK32.match( line ) ):
                        self.addKind = enum_ADD_LINK32
                        line = self.changeOptionsLnk( line )
                        changed = True
                        
                    elif ( re_SUBTRACT_LINK32.match( line ) ):
                        self.addKind = enum_SUBTRACT_LINK32
                        line = self.changeOptionsLnk( line )
                        changed = True

                    elif ( re_ADD_LIB32.match( line ) ):
                        self.addKind = enum_ADD_LIB32
                        line = self.changeOptionsLib( line )
                        changed = True

                    elif ( re_SUBTRACT_LIB32.match( line ) ):
                        self.addKind = enum_SUBTRACT_LIB32
                        line = self.changeOptionsLib( line )
                        changed = True

                    elif ( re_ADD_BSC32.match( line ) ):
                        self.addKind = enum_ADD_BSC32
                        line = self.changeOptionsBsc( line )
                        changed = True

                if ( changed ):
                    line = StringUtils.stripSpacesInExcess( line )
                    self.lines[n] = line
        return

    def getPostFixIndex( self, filename ):
        basetitle = filename
        i = basetitle.rfind( '_' )
        if ( i != -1 ):
            name = basetitle[:i]
            postfix = basetitle[i+1:]
            if ( postfix == 'd' or postfix == 's' or postfix == 'sd' or postfix == compilerVc6 ):
                basetitle = name
                #j = filename.rfind( '_', i-1 )  # the start index specification DOESN'T WORK AT ALL
                j = basetitle.rfind( '_' )
                if ( j != -1 ):
                    name = basetitle[:j]
                    postfix = filename[j+1:i]
                    if ( postfix == compilerVc6 ):
                        basetitle = name
                    else:
                        j = i
                i = j
            else:
                i = len( basetitle )
        return ( i, basetitle )

    def getPostFix( self ):
        postfix = '_' + compilerVc6
        if ( self.appType == enumAppTypeDll ):
            if ( self.isDebugCfg[self.nCfg] ):
                postfix += '_d'
        elif ( self.appType == enumAppTypeLib ):
            if ( self.isDebugCfg[self.nCfg] ):
                postfix += '_sd'
            else:
                postfix += '_s'
        return postfix

    def reformatDir( self, path ):
        # adds '_compiler/' to the path and removes a possible '/obj'
        path = FileUtils.normDirOS( path, app.options.unixStyle )
        c = FileUtils.getNormSep( app.options.unixStyle )
        if ( path.find( compilerVc6 + c ) == -1 ):
            # add '_compiler' unless is a relative path
            #rec = re.compile( '[\\/.]*' )
            #m = rec.match( path )
            #if ( m ): predir = m.group()
            if ( path[0] != c and ( path.find( ".." ) > 0 ) ):  # > 0 i.e. != -1 and != 0
                path = compilerVc6 + c + path[:]
        # eliminates '/obj' because at this point it is annoying
        path = StringUtils.replace( path, c + 'obj', '' )
        return path

    def extractOutputIntermDir( self, line ) :
        m = re_output_or_intermed_dir.match( line )
        if ( m ):
            subdir = m.group('subdir')
            dirname = self.reformatDir( subdir )
            if ( re_intermed_dir.match( line ) ):
                self.PropIntermeDirList[self.nCfg] = dirname
            else:
                self.PropOutputDirList[self.nCfg] = dirname
        return

    def extractMainOutDir( self, line ) :
        #if ( line.find( r'/out:' ) != -1 ):
        m = re_option_out_dir.search( line )
        if ( m ):
            outdir = m.group( 'subdir' )
            outdir = FileUtils.normPathOS( outdir, app.options.unixStyle )

            # Lib
            dirname = os.path.dirname( outdir )
            dirname =  FileUtils.normDirOS( dirname, app.options.unixStyle )
            self.OutputDirOutList[self.nCfg] = dirname

            basetitle = os.path.basename( outdir )
            (basetitle,ext) = os.path.splitext( basetitle )
            (ipf, basetitle) = self.getPostFixIndex( basetitle )
            if ( len( basetitle ) ):
                self.MainFileTitleList[self.nCfg] = basetitle
                self.MainFileTitleUnique          = basetitle
        else:
            msg = 'WARNING: the file \'%s\' has no \'/out:\' option in the configuration \'%s\'' % ( self.filename, self.configName )
            print msg

        return

    def addReformatOutputIntermediateDirs( self, line, subdir ):
        # reformat a line for Intermediate/Output directory - never remove it !
        changeSomething = ( app.options.reformatOutputIntermediateDirs == 1 )

        if ( changeSomething ):
            dirname = self.reformatDir( subdir ) # for debug
            if ( re_intermed_dir.match( line ) ):
                if ( self.PropIntermeDir != dirname ):
                    raise Exception( 'self.PropIntermeDir != dirname i.e. %s != %s' % ( self.PropIntermeDir, dirname) )
            else:
                if ( self.PropOutputDir != dirname ):
                    raise Exception( 'self.PropOutputDir != dirname i.e. %s != %s' % ( self.PropOutputDir, dirname) )
            line = StringUtils.replace( line, subdir, dirname )
        return line


    def changeOptionsCpp( self, line ):
        self.storedOptions = []

        changeSomething =   ( app.options.reformatOptionOutput != 0 ) or \
                            ( app.options.reformatOptionPdb != 0 ) or \
                            ( app.options.reformatOptionBrowse != 0 )
        if ( changeSomething ):
            if ( self.addKind == enum_ADD_CPP ):
                # the order of the following calls counts
                line = self.storeRemoveOptionOutputDir( line )
                line = self.storeRemoveOptionPdb( line )
                line = self.storeRemoveOptionBrowse( line )
                optionsList = [ '/D' ]
                index = self.findLastIndexInList( optionsList, line, True )
                if ( index == -1 ):
                    raise Exception( 'ADD CPP line without any /D option. Please improve the code or check the line.' )
            elif ( self.addKind == enum_SUBTRACT_CPP ):
                # the order of the following calls counts
                line = self.storeRemoveOptionBrowse( line )
                optionsList = [ '/Wx' ]
                index = self.findLastIndexInList( optionsList, line, True )
                
            line = self.addStoredOptions( line, index )

        return line

    def changeOptionsLnk( self, line ):
        self.storedOptions = []

        changeSomething =   ( app.options.reformatOptionOutput == 1 ) or \
                            ( app.options.reformatOptionPdb != 0 )

        if ( changeSomething ):
            if ( self.addKind == enum_ADD_LINK32 ):
                # the order of the following calls counts
                line = self.storeRemoveOptionOutputDir( line )
                line = self.storeRemoveOptionPdb( line )
                optionsList = [ '/nologo', '/debug', '/dll', '/entry:', '/subsystem:', '/machine:' ]
                index = self.findLastIndexInList( optionsList, line, True )
                if ( index == -1 ):
                    raise Exception( 'ADD LINK32 line without any option between %s. Please improve the code or check the line.' % optionsList )
            elif ( self.addKind == enum_SUBTRACT_LINK32 ):
                 # the order of the following calls counts
                line = self.storeRemoveOptionPdb( line )
                optionsList = [ '/incremental:', '/map', '/pdb:' ]
                index = self.findLastIndexInList( optionsList, line, True )
                
            line = self.addStoredOptions( line, index )

        return line

    def changeOptionsLib( self, line ):
        self.storedOptions = []

        changeSomething =   ( app.options.reformatOptionOutput == 1 )

        if ( changeSomething ):
            # the order of the following calls counts
            line = self.storeRemoveOptionOutputDir( line )
            optionsList = [ '/nologo' ]
            index = self.findLastIndexInList( optionsList, line, True )
            if ( index == -1 ):
                raise Exception( 'ADD LIB32 line without any option between %s. Please improve the code or check the line.' % optionsList )
            line = self.addStoredOptions( line, index )

        return line

    def changeOptionsBsc( self, line ):
        self.storedOptions = []

        changeSomething =   ( app.options.reformatOptionBrowse == 1 )

        if ( changeSomething ):
            # the order of the following calls counts
            line = self.storeRemoveOptionBrowse( line )
            optionsList = [ '/nologo' ] # '# ADD BSC32' would give error: unbalanced parenthesis in the regexpr of findIndexCloseToOption()
            index = self.findLastIndexInList( optionsList, line, True )
            if ( index == -1 ):
                raise Exception( 'ADD BSC32 line without any option between %s. Please improve the code or check the line.' % optionsList )
            line = self.addStoredOptions( line, index )

        return line

    def findLastIndexInList( self, optionsList, line, ignorecase ):
        before = False
        index = -1
        self.lastGroupFound = '' # for debug only
        for i in range( len(optionsList)-1, -1, -1 ):
            option = optionsList[i]
            if ( ignorecase ):
                option = option.lower()
            idx = self.findIndexCloseToOption( line, option, ignorecase, before, True  )
            if ( index < idx ):
                index = idx

        return index

    def storeRemoveOptionOutputDir( self, line ):
        # reformat a line for output filename option ( /Fo /out: )
        # always convenient to specify the output dir for the object files, so never remove it !
        changeSomething = ( app.options.reformatOptionOutput != 0 )
        if ( self.addKind == enum_ADD_CPP ):
            # (*) the reason why we always remove the '/Fo' option in a ADD CPP line is that vc6 always does it ( or at least when the value is the the same as Intermediate_Dir )
            addDir  = False
            addFile = False
            line = self.storeRemoveOption( line, '/Fo', self.PropIntermeDir, '', False, changeSomething, addDir, addFile )
        else:
            # this option should always be there ( we always want dir and filename specified for the linker output )
            addDir  = +1 # never remove it
            addFile = +1
            if ( self.MainFileTitleUnique != self.MainFileTitleList[self.nCfg] ): raise Exception( '*** self.MainFileTitleUnique != self.MainFileTitleList[self.nCfg] ( %s != %s )' % ( self.MainFileTitleUnique, self.MainFileTitleList[self.nCfg] ) )
            line = self.storeRemoveOption( line, '/out:', self.OutputDirOut, self.MainFileTitleUnique + self.outputExt, False, changeSomething, addDir, addFile )

        return line

    def storeRemoveOptionPdb( self, line ):
        # reformat a line for ProgramDatabase option ( /Fd /pdb: )
        changeSomething = ( app.options.reformatOptionPdb != 0 )
        if ( self.addKind == enum_ADD_CPP ):
            # (*) the reason why we always remove the '/Fd' option in a ADD CPP line is that vc6 always does it ( or at least when the value is the the same as the output project aside the extension )
            addDir  = False
            addFile = False # we usually want both in the same way
            if ( self.appType == enumAppTypeExe ):
                line = self.storeRemoveOption( line, '/Fd', self.OutputDirOut, '', False, changeSomething, addDir, addFile )
            else:
                # for DLL's and Lib's also the filename is specified (and the link option '/pdb:' does not exist)
                if ( self.MainFileTitleUnique != self.MainFileTitleList[self.nCfg] ): raise Exception( '*** self.MainFileTitleUnique != self.MainFileTitleList[self.nCfg] ( %s != %s )' % ( self.MainFileTitleUnique, self.MainFileTitleList[self.nCfg] ) )
                line = self.storeRemoveOption( line, '/Fd', self.OutputDirOut, self.MainFileTitleUnique + '.pdb', False, changeSomething, addDir, addFile )
        elif ( self.addKind == enum_ADD_LINK32 or self.addKind == enum_ADD_LIB32 ):
            # (*) the reason why we always remove the '/pdb' option in a ADD LINK32 line is that vc6 always does it ( or at least when the value is the the same as the output project aside the extension )
            addDir  = False
            addFile = False # we usually want both in the same way
            if ( self.MainFileTitleUnique != self.MainFileTitleList[self.nCfg] ): raise Exception( '*** self.MainFileTitleUnique != self.MainFileTitleList[self.nCfg] ( %s != %s )' % ( self.MainFileTitleUnique, self.MainFileTitleList[self.nCfg] ) )
            line = self.storeRemoveOption( line, '/pdb:', self.OutputDirOut, self.MainFileTitleUnique + '.pdb', False, changeSomething, addDir, addFile )
            
            if ( self.addKind == enum_ADD_LINK32 ):
                addDir  = app.options.reformatOptionPdb
                addFile = addDir # we usually want both in the same way
                line = self.storeRemoveOption( line, '/debug', '', '', False, changeSomething, addDir, addFile )
        elif ( self.addKind == enum_SUBTRACT_LINK32 ):
            # '/debug' in # SUBTRACT LINK32 disable the pdb option
            addDir  = -(app.options.reformatOptionPdb) # /debug in the SUBTRACT line has opposite meaning
            addFile = addDir # we usually want both in the same way
            line = self.storeRemoveOption( line, '/debug', '', '', False, changeSomething, addDir, addFile )
        return line

    def storeRemoveOptionBrowse( self, line ):
        # reformat a line for Browse database option ( /FR /Fr /o: )
        changeSomething = ( app.options.reformatOptionBrowse != 0 )
        addDir  = app.options.reformatOptionBrowse
        addFile = addDir # we usually want both in the same way
        if ( self.isDebugCfg[self.nCfg] ):  # to add this option it makes sense only for debug mode
            if ( self.addKind == enum_ADD_CPP ):
                line = self.storeRemoveOption( line, '/FR', self.PropIntermeDir, '', True, changeSomething, addDir, addFile )
            elif ( self.addKind == enum_ADD_LINK32 or self.addKind == enum_ADD_LIB32 ):
                # the bsc file will be placed in the same dir of the main output
                if ( self.MainFileTitleUnique != self.MainFileTitleList[self.nCfg] ): raise Exception( '*** self.MainFileTitleUnique != self.MainFileTitleList[self.nCfg] ( %s != %s )' % ( self.MainFileTitleUnique, self.MainFileTitleList[self.nCfg] ) )
                line = self.storeRemoveOption( line, '/o', self.OutputDirOut, self.MainFileTitleUnique + '.bsc', False, changeSomething, addDir, addFile )
            elif ( self.addKind == enum_SUBTRACT_CPP ):
                # /Fr' in # SUBTRACT CPP disable the pdb option
                addDir  = -(app.options.reformatOptionBrowse) # /debug in the SUBTRACT line has opposite meaning
                addFile = addDir # we usually want both in the same way
                line = self.storeRemoveOption( line, '/FR', '', '', True, changeSomething, addDir, addFile )

        return line

    def storeRemoveOption( self, line, option, directory, filename, ignorecase, changeSomething, addDir, addFile ):
        # addDir and addFile with value: = +1 => add and with = -1 => remove
        # if ( directory and filename == empty ) then the option alone is added /removed

        fn = ''
        if ( addFile and filename ):
            fn = filename
            if ( fn ):
                (fn,ext) = os.path.splitext( fn )
                (ipf, basetitle) = self.getPostFixIndex( fn )
                if ( ipf != -1 ):
                    fn = fn[:ipf]
                fn += self.getPostFix()
                fn += ext

        dr = ''
        if ( addDir and directory ):
            dr = directory

        if ( addDir == +1 or addFile == +1 ):
            if ( dr or fn ):
                replac = ( option + '\"' + dr + fn + '\"' + ' ' )
            else:
                # we meant to just add/remove the opion alone
                replac = option
        else:
            replac = ''

        # first remove the option ( so it will go in a 'standard' position
        #(?P<fulloption> /Fo(\s*?)"(?P<optionarg>[a-zA-Z0-9_ $\(\)\\/.]*)") | (?P<optionalone> /Fo(\s+?))
        reOption = re.VERBOSE
        if ( ignorecase ): reOption += re.IGNORECASE
        if ( option and option[ len(option) -1 ] == ':' ):
            # (/Fd:"vc6\Debug\Beautiful Actions_vc6.pdb") or /machine:i386 ( but no spaces )
            rec = re.compile( r'(?P<fulloption> %s(\s*?)"(?P<optionarg>[a-zA-Z0-9_ $\(\)\\/.]*)") | (?P<fulloption2> %s(?P<optionarg2>[a-zA-Z0-9_$\(\)\\/.]*))' % (option,option), reOption )
        else:
            # (/Fd "vc6\Debug\Beautiful Actions_vc6.pdb") or /FR ) ( isolated option with no argument )
            rec = re.compile( r'(?P<fulloption> %s(\s*?)"(?P<optionarg>[a-zA-Z0-9_ $\(\)\\/.]*)") | (?P<optionalone> %s(\s+?))' % (option,option), reOption )

        # remove the option and store it
        s = ''
        m = rec.search( line )
        if ( m ):
            # option found; remove it
            # Remark: line = rec.sub( replac, line ) # this doesn't work right !
            s = m.group()
            if ( s ):
                i = line.find( s )
                ls = len(s)
                c = s[-1]
                if ( c == '\r' or c == '\n' ):
                    s = s[:-1]
                    ls -= 1
                #if ( replacing ):
                #    c = line[i+ls:]
                #    if ( c == ' ' or c == '\t' or c == '\r' or c == '\n' ):
                #        replac = replac[:-1]    # get rid of the last space
                #    line = line[:i] + replac + line[i+ls:]
                line = line[:i] + line[i+ls:]  # remove
        self.lastGroupFound = s

        if ( changeSomething ):
            # because not to append is like to remove
            self.storedOptions.append( replac )
        else:
            # when some s or when the list is empty
            if ( s or len(self.storedOptions) == 0 ):
                self.storedOptions.append( s )

        return line

    def addStoredOptions( self, line, index ):
        addString = ' ' # this space make sure the added options are separated from the previous one
        for fullOption in self.storedOptions:
            addString += fullOption + ' '

        i = index
        if ( i != -1 ):
            #inserting
            #if ( 0 < i and line[i-1] != ' ' and line[i-1] != '\t' ):
            #    addString = ' ' + addString[:]
            if ( i == len( line ) ):
                # safety measure
                ( i, crlf ) = StringUtils.getEol( line )
            line = line[:i] + addString + line[i:]
        else:
            #appending ( before the eol ( crlf ) )
            ( i, crlf ) = StringUtils.getEol( line )
            #if ( 0 < ln and line[i-1] != ' ' and line[i-1] != '\t' ):
            #    addString = ' ' + addString[:]
            line = line[:i] + addString + crlf

        #self.storedOptions = []

        return line

    def findIndexCloseToOption( self, line, option, ignorecase, before, repeat ):
        backward = False

        if ( ignorecase ):
            line   = line.lower()
            option = option.lower()

        # This accepts:
        # /D "BUILD_APPKIT_LIB" /FR /Yu"ApplicationKit.h"
        # but also
        # /D "BUILD_APPKIT_LIB" /FR"vc6\DebugDLL\" /Yu"ApplicationKit.h"
        reOption = re.VERBOSE
        if ( ignorecase ): reOption += re.IGNORECASE
        if ( option and option[ len(option) -1 ] == ':' ):
            # (/Fd:"vc6\Debug\Beautiful Actions_vc6.pdb") or /machine:i386 ( but no spaces )
            rec = re.compile( r'(?P<fulloption> %s(\s*?)"(?P<optionarg>[a-zA-Z0-9_ $\(\)\\/.]*)") | (?P<fulloption2> %s(?P<optionarg2>[a-zA-Z0-9_$\(\)\\/.]*))' % (option,option), reOption )
        else:
            # (/Fd "vc6\Debug\Beautiful Actions_vc6.pdb") or /FR ) ( isolated option with no argument )
            rec = re.compile( r'(?P<fulloption> %s(\s*?)"(?P<optionarg>[a-zA-Z0-9_ $\(\)\\/.]*)") | (?P<optionalone> %s(\s+?))' % (option,option), reOption )
        index =  -1

        s = ''
        if ( backward ):
            raise Exception( 'please replace backward with other options combinations. A Regex is necessary.' )
            #index = line.rfind( option )
            #if ( index != -1 ):
            #    lin = line[ index:]
            #    m = rec.search( lin )
            #    if ( m ):
            #        s = m.group()
        else:
            m = rec.search( line )
            if ( m ):
                s = m.group()
                c = s[-1]
                if ( c == '\r' or c == '\n' ):
                    s = s[:-1]
                self.lastGroupFound = s

        if ( s ):
            index = line.find( s )
            if ( not before ):
                ls = len( s )
                index += ls

            if ( before ):
                if ( 0 < index and index < len(line) ):
                    c = line[index-1]
                    if ( c == ' ' or c == '\t' ):
                        index -= 1
            else:
                if ( index != -1 and index < len(line) ):
                    c = line[index]
                    if ( c == ' ' or c == '\t' ):
                        index += 1

            if ( repeat and index != -1 ):
                if ( repeat ):
                    if ( backward != before ):
                        raise Exception( 'findIndexCloseToOption( line, %s, %d, %d, %d ): repeat wants backward == before otehrwise infinite loop ( backward == %s )!' % ( option, ignorecase, before, repeat, backward ) )
                idx = index
                if ( backward ):
                    lin = line[:idx]
                else:
                    lin = line[idx:]
                while ( True ):
                    # recursion
                    idx = self.findIndexCloseToOption( lin, option, ignorecase, before, False )
                    if ( idx == -1 ):
                        break
                    else:
                        if ( backward ):
                            lin = lin[:idx]
                            index = idx
                        else:
                            index += idx
                            lin = lin[idx:]
                    continue

        return index


class Walker:
    """Directory Walker class
    This class is introduced only in order to prevent that the variables in __main__ be seen as global
    which is leading to errors difficult to find
    """
    def __init__(self):
        pass

    def walk_files( self, root, recursive=False ):
        # non recursive implementation at all
        #def walk_files(top):
        #    names = os.listdir(top)
        #    for name in names:
        #        if os.path.isfile(name):
        #            yield name
        for path, dirs, files in os.walk(root):
            for fn in files:
                yield os.path.join(path, fn)
            if not recursive:
                break
        pass

    def walk( self ):
        if ( app.options.prompt ):
            raw_input( '\n  Press enter to continue ( Ctrl+C to exit ) ... ')

        os.chdir( app.currentdir )

        sep = FileUtils.getNormSep( app.options.unixStyle )

        singleFile = ( app.options.filename != '' )

        if ( not singleFile and app.options.createWorkspace ):
            workspaceName = FileUtils.absolutePath( app.currentdir, app.options.workspaceName, app.options.unixStyle )
            workspace = Workspace( workspaceName )

        #testRegex()

        app.changedFiles = 0
        app.unchangedFiles = 0
        app.createdFiles = 0
        nFiles = 0
        for filename in self.walk_files( root, app.options.recurse ):
            if ( len(filename) > 4 and filename[-4:] == '.dsp' ):
                # skip filenames like: file_vc70.dsp or file_vc71.dsp
                filename = FileUtils.normPathOS( filename, app.options.unixStyle )
                if ( 3 < app.options.verbose ):
                    print 'File: ' + filename

                if ( app.options.enableVcfSpecific ):
                    fn = filename.lower()
                    if ( ( fn.find( '_' + compilerVc70 ) != -1 ) or ( fn.find( '_' + compilerVc71 ) != -1 ) ):
                        continue
                    if ( ( fn.find( compilerVc70 + sep ) != -1 ) or ( fn.find( compilerVc71 + sep ) != -1 ) ):
                        continue

                doIt = app.checkAllowedDir( filename )
                if ( doIt and singleFile ):
                    doIt = ( filename.lower().find( app.options.filename.lower() ) != -1 )


                if ( doIt ):
                    nFiles += 1

                    fullname = os.path.join( root, filename )
                    fullname = FileUtils.normPathOS( fullname, app.options.unixStyle )

                    if ( backupFiles ):
                        FileUtils.backup( fullname )
                    if ( 0 < app.options.verbose ):
                        print FileUtils.relativePath( app.currentdir, fullname, True, app.options.unixStyle )
                    dsp = DspFile( app, fullname )
                    dsp.reformat()

                    if ( app.options.createWorkspace ):
                        prjName = dsp.getTrueProjectName()
                        # workspaceDir = os.path.dirname( app.options.workspaceName ) + '/'
                        # prjPath = FileUtils.relativePath( workspaceDir, root + sep + fullname, True, app.options.unixStyle ): it wouldn't work if app.currentdir != getCwd
                        prjPath = FileUtils.absolutePath( app.currentdir, root + sep + fullname, app.options.unixStyle )
                        workspace.addProject( prjName, prjPath )

                    if ( app.options.enableVcfSpecific ):
                        # note: we duplicate only what is allowed
                        if ( app.options.copyToVc70 or app.options.copyToVc71 ):
                            dspdup = DspFile( app, fullname )
                            dspdup.duplicateVc( compilerVc6, compilerVc70 )
                            dspdup.duplicateVc( compilerVc6, compilerVc71 )

        if ( nFiles ):
            if ( app.options.createWorkspace ):
                workspace.create()
            if ( False and app.options.conformLibsToDlls ):
                workspace.conformLibsToDlls()

        if ( 0 < app.options.verbose ):
            print ' %s dsp files processed. [changed: %s, unchanged: %s, created: %s]' % (nFiles, app.changedFiles, app.unchangedFiles, app.createdFiles)

    pass



if __name__ == '__main__':
    root = '.'

    app = DspApp()

    walker = Walker()
    walker.walk()

    pass


#######################################################################################################################
"""
Notes:
    1) The modified files in the safest way for the originals
        First is created a temporary file and then, if everything is ok, it is renamed into the original one
        
    2) The order of the options is mantained: but if the vc6 options are in the wrong order 
        and th this script's option is not null, then the order is changed in a 'standard' way

Limitations:
    1) A program database option is mosly enabled/disabled by the /debug option ( generate debug info ) 
        which is present or in the #ADD LINK32 line or in the #SUBTRACT LINK32 line
        But this program doesn't affect (create) any SUBTRACT line if it doesn't exist yet
"""
