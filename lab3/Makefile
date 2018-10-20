# File: Makefile
# Name: Shivansh Rustagi
# CruzID: 1651034
# Class: CMPS 12M
# Desc: Makefile for the charType program
PROGRAMNAME = charType
FLAGS = -std=c99 -Wall
SOURCES = $(PROGRAMNAME).c
OBJECTS = $(PROGRAMNAME).o
EXEBIN = $(PROGRAMNAME)

all : $(PROGRAMNAME)

# create executable file
$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

# create object file
$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

# clean utility
clean :
	rm -f $(EXEBIN) $(OBJECTS)

check : 
	valgrind --leak-check=full $(PROGRAMNAME) $(PROGRAMNAME).c out