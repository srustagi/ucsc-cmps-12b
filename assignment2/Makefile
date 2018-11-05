# File: Makefile
# Name: Shivansh Rustagi
# CruzID: 1651034
# Class: CMPS 12B
# Desc: Makefile for Assignment 2

TESTING = main
UTILITIES = listUtil
FUNCTIONS = list
OBJECTS = $(TESTING).o $(UTILITIES).o $(FUNCTIONS).o
SOURCES = $(TESTING).c $(FUNCTIONS).c $(UTILITIES).c
INCLUDES = $(FUNCTIONS).h $(UTILITIES).h
FLAGS = -Wall -std=c99
EXEBIN = $(TESTING)

all : $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(INCLUDES) $(SOURCES)
	gcc -c $(FLAGS) $(INCLUDES) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS) $(UTILITIES).h.gch $(FUNCTIONS).h.gch

run :
	./main