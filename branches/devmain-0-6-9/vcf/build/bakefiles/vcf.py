
# Returns a string that represents a filename of the given library name.
def getFilename( libName ):
    return '%s$(SUFFIX_SELECTLIB)$(SUFFIX_LIBRARY)' % libName

# Returns a string that represents a filename of the given static library name.
def getLibFilename( libName ):
    return '%s$(SUFFIX_SELECTLIB)$(SUFFIX_STATIC)' % libName

# Returns a string that represents a filename of the given dynamic library name.
def getDllFilename( libName ):
    return '%s$(SUFFIX_SELECTLIB)$(SUFFIX_DYNAMIC)' % libName
