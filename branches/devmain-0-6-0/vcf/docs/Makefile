#make file

VERSION = 0.6.0

HTMLHELP_COMPILER = "D:/Program Files/HTML Help Workshop/hhc.exe"

RAW_CHM_FILENAME = vcf_docs.chm
VERSIONED_CHM_FILENAME = VCFDocs.$(VERSION).chm
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




docs :  $(VCF_DOCS)
	xsltproc --catalogs --docbook vcf.xsl vcf_docbook.sgml

hh : htmlhelp.hhp docs
	$(HTMLHELP_COMPILER) htmlhelp.hhp
	mv $(RAW_CHM_FILENAME) $(VERSIONED_CHM_FILENAME)

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
	rm *.html
	rm $(HTML_TAR_FILENAME).gz
	rm *.hhp
	rm *.hhc
	rm *.hhk
	rm *.chm
