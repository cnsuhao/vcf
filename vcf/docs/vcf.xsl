<!--
Copyright (c) 2000-2003, Jim Crafton
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
	Redistributions of source code must retain the above copyright
	notice, this list of conditions and the following disclaimer.

	Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in 
	the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

NB: This software will not save the world.
CVS Log info
$Log$
Revision 1.1.2.3  2003/03/04 04:53:51  ddiego
filled some docs

Revision 1.1.2.2  2003/03/03 22:42:41  ddiego
stuff

Revision 1.1.2.1  2003/03/03 03:39:49  ddiego
initial check-in of docbook vcf documentation, plus neccesary stylsheets
and images

-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	        version="1.0">
 
 <!--
 this uses a local path - may need to be modified for others
 -->
	<xsl:import href="D:/dork/docbook/xsl/htmlhelp/htmlhelp.xsl"/>
	
	<xsl:param name="generate.legalnotice.link" select="1"/>
	<xsl:param name="html.stylesheet" select="'vcf.css'"/>
	<xsl:param name="suppress.navigation" select="0"/>
	<xsl:param name="admon.graphics" select="1"/>
	<xsl:param name="admon.graphics.path">gfx/</xsl:param>
	<xsl:param name="htmlhelp.chm" select="'vcf_docs.chm'"/>
	
	
	<!-- 
	What follows are the header and footer customizations for the vcf docbook
	-->	
	<xsl:template name="user.header.navigation"> 
	  <table width="100%" border="0" cellpadding="0" cellspacing="0">
	 <tr>
	  <td width="250" rowspan="2" valign="top">
	   <table class="headerCellBanner" width="250" border="0" cellpadding="0" cellspacing="0">
	    <tr> 
	     <td width="250" height="125" align="center" valign="middle">
		     <a href="http://vcf.sf.net/" name="top"><img alt="void Visual_Component_Framework::Home(bool GoHome);" border="0" src="gfx/vcflogo.jpg" width="142" height="122"/>
		     </a>
	     </td>
	    </tr>
	   </table>
	  </td>
	  <td width="100%" rowspan="2" valign="top">
	   <table class="headerCell" width="100%" border="0" cellpadding="0" cellspacing="0">
	    <tr> 
	     <td width="100%" height="125" valign="top"> </td>
	    </tr>
	   </table>
	  </td>
	  <td width="500" height="100" valign="top">
	   <table class="headerCell" width="500" border="0" cellpadding="0" cellspacing="0">
	    <tr> 
	     <td width="500" height="100" align="right" valign="middle">VCF Documentation</td>
	    </tr>
	   </table>
	  </td>
	 </tr>
	 <tr> 
	  <td height="25" valign="top">
	   <table class="menuBar" width="500" border="0" cellpadding="0" cellspacing="0">
	    <tr> 
	     <td width="500" height="25" align="right" valign="middle">  </td>
	    </tr>
	   </table>
	  </td>
	 </tr>
	</table>
	<table width="100%" border="0" cellpadding="0" cellspacing="0">
	 <tr> 
	  <td width="100%" height="25" valign="top">
	   <table class="menuBarLow" width="100%" border="0" cellpadding="0" cellspacing="0">
	    <tr> 
	     <td width="100%" height="25" valign="top"></td>
	    </tr>
	   </table>
	  </td>
	  <td width="500" valign="top">
	   <table class="menuBarLow" width="500" border="0" cellpadding="0" cellspacing="0">
	    <tr> 
	     <td width="500" height="25" valign="top"></td>
	    </tr>
	   </table>
	  </td>
	 </tr>
	</table>
	<hr></hr>
	
	</xsl:template>
	
	<xsl:template name="user.footer.navigation">
	
	<hr></hr>
	<table class="footerCell" width="100%" border="0" cellpadding="0" cellspacing="0">
	 <tr> 
	  <td width="100%" height="50" align="center" valign="middle">
		Copyright (c)2003 Jim Crafton, vcf.sourceforge.net<br></br>
		<a class="menu" href="http://vcf.sourceforge.net/contact.php">Contacts</a>  |  
		<a class="menu" href="http://vcf.sourceforge.net/legal.php">Disclaimer</a></td>
	 </tr>
	</table>
	<table class="footerCellAdv" width="100%" border="0" cellpadding="0" cellspacing="0">
	 <tr> 
	  <td width="100%" height="100" align="center" valign="middle">
		  <a href="http://sourceforge.net/" target="_blank">
			  <img border="0" src="gfx/sf_net.png"/></a>   
		  <a href="http://www.vmware.com" target="_blank">
			  <img alt="VCF Sponser" border="0" src="gfx/vmwarelogo.png" width="157" height="37"/></a></td>
	 </tr>
	</table>
	<hr></hr>
	
	<!-- 
	HACK ALLERT!!!!!!
	These stupid image tags are here because the hhc html help compiler does not pick up
	images referenced in the css file. it DOES pick img image references, so we need to 
	create an img tag for each image that the css file needs
	-->
	<img border="0" src="gfx/greybg.jpg" width="0" height="0"/>
	 <img border="0" src="gfx/left-mangle.jpg" width="0" height="0"/>
	</xsl:template>

</xsl:stylesheet>
