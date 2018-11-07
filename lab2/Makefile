# macros to make compilation easier
FLAGS = -std=c99 -Wall
SOURCES = FileReverse.c
OBJECTS = FileReverse.o
EXEBIN = FileReverse

all: $(EXEBIN)

# create executable file
$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

# create object file
$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

# clean utility
clean :
	rm -f $(EXEBIN) $(OBJECTS)