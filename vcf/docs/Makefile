#make file

VERSION = 0.6.0
VCFB_VERSION = 1.0.4
XMAKE_VERSION = 1.0.4

HTMLHELP_COMPILER = "c:/Program Files/HTML Help Workshop/hhc.exe"

XSL_HTMLHELP_IMPORT = "D:/code/docbook-xsl-1.60.1/htmlhelp/htmlhelp.xsl"

RAW_CHM_FILENAME = vcf_docs.chm
RAW_VCF_BUILDER_CHM_FILENAME = vcfbuilder_docs.chm

VERSIONED_CHM_FILENAME = VCFDocs.$(VERSION).chm
VERSIONED_VCFBUILDER_CHM_FILENAME = VCFBuilderDocs.$(VCFB_VERSION).chm
VERSIONED_XMAKE_CHM_FILENAME = XMakeDocs.$(XMAKE_VERSION).chm
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


VCF_BUILDER_DOCS = vcf.css vcfbuilder.xsl \
vcfbuilder_docbook.sgml \
vcfbuilder_ui.sgml \
vcfbuilder_building.sgml \
vcfbuilder_faq.sgml \
vcfbuilder_versionctrl.sgml \
vcfbuilder_debug.sgml \
vcfbuilder_ide.sgml \
vcfbuilder_wspprj.sgml \
vcfbuilder_design.sgml \
vcfbuilder_intro.sgml \
vcfbuilder_designer.sgml \
vcfbuilder_quicktut.sgml 


XMAKE_DOCS = vcf.css xmake_book.sgml xmake_docbook.sgml




docs :  $(VCF_DOCS) test_tools
	xsltproc --catalogs --docbook vcf.xsl vcf_docbook.sgml
	
online_docs :  $(VCF_DOCS) test_tools 
	xsltproc --catalogs --docbook vcf_online.xsl vcf_docbook.sgml	
	
strip_online_docs :  online_docs stripper
	for file in *.html;\
	do\
		echo post processing $$file with stripper...;\
		./stripper $$file;\
	done

vcf_builder_docs : $(VCF_BUILDER_DOCS) test_tools
	xsltproc --catalogs --docbook vcfbuilder.xsl vcfbuilder_docbook.sgml

xmake_docs : $(XMAKE_DOCS) test_tools
	xsltproc --catalogs vcf.xsl xmake_docbook.sgml

xmake_hh : htmlhelp.hhp xmake_docs
	$(HTMLHELP_COMPILER) htmlhelp.hhp
	mv $(RAW_CHM_FILENAME) $(VERSIONED_XMAKE_CHM_FILENAME)

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



stripper.o : stripper.cpp
	g++ -c -O2 stripper.cpp

stripper : stripper.o
	g++ -o stripper stripper.o




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

dist_online : online_docs strip_online_docs
	find *.html > files.out
	find gfx/ -type f -name '*' > images.out
	cat files.out images.out > all.out
	echo Creating tar file...
	tar -cf $(HTML_TAR_FILENAME) -T all.out
	rm -f $(HTML_TAR_FILENAME).gz
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
	rm -f stripper stripper.o
