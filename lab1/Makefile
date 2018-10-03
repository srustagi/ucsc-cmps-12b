# ------------
# My Makefile
# ------------

# Macros
JAVAFILES = HelloUser.java HelloUser2.java
# SOURCES = README Makefile $(JAVASRC)
MAINCLASS = HelloUser2
CLASSES = HelloUser.class HelloUser2.class
JarFile = Hello

all: $(JARFILE)

$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(CLASSES)
	rm Manifest
	chmod +x $(JARFILE)

$(CLASSES): $(JAVAFILES)
	javac -Xlint $(JAVAFILES)

clean:
	rm $(CLASSES)
