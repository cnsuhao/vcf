#make file

VERSION = 0.6.0
VCFB_VERSION = 1.0.4

HTMLHELP_COMPILER = "c:/Program Files/HTML Help Workshop/hhc.exe"

XSL_HTMLHELP_IMPORT = "D:/code/docbook-xsl-1.60.1/htmlhelp/htmlhelp.xsl"

RAW_CHM_FILENAME = vcf_docs.chm
RAW_VCF_BUILDER_CHM_FILENAME = vcfbuilder_docs.chm

VERSIONED_CHM_FILENAME = VCFDocs.$(VERSION).chm
VERSIONED_VCFBUILDER_CHM_FILENAME = VCFBuilderDocs.$(VCFB_VERSION).chm
VERSIONED_SRC_CHM_FILENAME = VCFSrcDocs.$(VERSION).chm
HTML_TAR_FILENAME = VCFDocs.$(VERSION).tar


VCF_DOCS = corelib_FAQ.sgml \
corelib_applicationKit.sgml \
corelib_componentAuthoring.sgml \
corelib_foundationKit.sgml \
corelib_graphicsKit.sgml \
corelib_networkKit.sgml \
corelib_remoteObjectKit.sgml \
general.sgml \
getting_started.sgml \
tutorials.sgml \
vcf_docbook.sgml \
vcf_intro.sgml \
vcf.css \
vcf.dsl \
vcf.xsl


VCF_BUILDER_DOCS = vcfbuilder_docbook.sgml \
vcf.css \
vcf.xsl \
vcfbuilder.xsl


docs :  $(VCF_DOCS) test_tools
	xsltproc --catalogs --docbook vcf.xsl vcf_docbook.sgml

vcf_builder_docs : $(VCF_BUILDER_DOCS) test_tools
	xsltproc --catalogs --docbook vcfbuilder.xsl vcfbuilder_docbook.sgml

test_tools : 
	if ( test -f $(HTMLHELP_COMPILER) )\
	then\
		echo HTML Help compiler found;\
	else\
		echo Html Help compiler not found;\
		exit 1;\
	fi

	if ( test -f $(XSL_HTMLHELP_IMPORT) )\
	then\
		echo stylesheet found;\
	else\
		echo XSL style sheet $(XSL_HTMLHELP_IMPORT) not found;\
		exit 1;\
	fi



hh : htmlhelp.hhp docs
	$(HTMLHELP_COMPILER) htmlhelp.hhp
	mv $(RAW_CHM_FILENAME) $(VERSIONED_CHM_FILENAME)

vcf_builder_hh : vcf_builder_docs htmlhelp.hhp 
	$(HTMLHELP_COMPILER) htmlhelp.hhp
	mv $(RAW_VCF_BUILDER_CHM_FILENAME) $(VERSIONED_VCFBUILDER_CHM_FILENAME)

doxy : 
	cp Doxyfile Doxyfile.bak
	sed "s?VERSION-NUMBER?$(VERSION)?g" Doxyfile > Doxyfile.tmp
	mv Doxyfile.tmp Doxyfile
	doxygen
	mv Doxyfile.bak Doxyfile
	cp -r gfx/ doxy_html/

doxy_hh : doxy_html/index.hhp
	$(HTMLHELP_COMPILER) doxy_html/index.hhp
	mv doxy_html/index.chm ./$(VERSIONED_SRC_CHM_FILENAME)

dist : docs hh 
	find *.html > files.out
	find gfx/ -type f -name '*' > images.out
	cat files.out images.out > all.out
	echo Creating tar file...
	tar -cf $(HTML_TAR_FILENAME) -T all.out
	gzip $(HTML_TAR_FILENAME)
	echo HTML files tarred and compressed as $(HTML_TAR_FILENAME).gz		
	rm all.out
	rm files.out
	rm images.out
	
	
clean :
	rm -f *.html
	rm -f $(HTML_TAR_FILENAME).gz
	rm -f $(VERSIONED_SRC_CHM_FILENAME)
	rm -f $(VERSIONED_CHM_FILENAME)
	rm -f *.hhp
	rm -f *.hhc
	rm -f *.hhk
	rm -rf doxy_html/
