# File: Makefile
# Name: Shivansh Rustagi
# CruzID: 1651034
# Class: CMPS 12B
# Desc: Makefile for Assignment 2

TESTING = main
UTILITIES = listUtil
FUNCTIONS = list
OBJECTS = $(TESTING).o $(FUNCTIONS).o $(UTILITIES).o
SOURCES = $(TESTING).c $(FUNCTIONS).c $(UTILITIES).c
INCLUDES = $(FUNCTIONS).h $(UTILITIES).h
FLAGS = -Wall -std=c99
EXEBIN = $(TESTING)

all : $(EXEBIN)

$(EXEBIN) : $(OBJECTS) $(INCLUDES)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)

run :
	./main