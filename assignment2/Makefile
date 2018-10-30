# File: Makefile
# Name: Shivansh Rustagi
# CruzID: 1651034
# Class: CMPS 12B
# Desc: Makefile for Assignment 2

TESTING = main
UTILITIES = listUtil
FUNCTIONS = list
OBJECTS = $(TESTING).o $(UTILITIES).o $(FUNCTIONS).o
SOURCES = $(TESTING).c $(UTILITIES).c $(UTILITIES).h $(FUNCTIONS).c $(FUNCTIONS).h
FLAGS = -Wall -std=c99
EXEBIN = $(TESTING)

all : $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS) $(UTILITIES).h.gch $(FUNCTIONS).h.gch