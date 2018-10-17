# -----------------------------------------------------------------------------
# 
# File: Makefile
# 
# Name: Shivansh Rustagi
# 
# CruzID: shrustag
# 
# Class: CMPS 12M
# 
# Desc: The final Makefile written as per the program spec in Lab1: creates and archives both .class files 
# (HelloUser.class and HelloUser2.class) in an executable jar file called Hello that runs function main() 
# from HelloUser2.class. Also has `clean` utility.
# 
# -----------------------------------------------------------------------------

JAVASRC = HelloUser.java HelloUser2.java
SOURCES = README Makefile $(JAVASRC)
MAINCLASS = HelloUser2
CLASSES = HelloUser.class HelloUser2.class
JARFILE = Hello

all: $(JARFILE)

$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(CLASSES)
	rm Manifest
	chmod +x $(JARFILE)

$(CLASSES): $(JAVASRC)
	javac -Xlint $(JAVASRC)

clean:
	rm $(CLASSES)
