# set the compiler
 CC=g++
# options
 CFLAGS=-c -Wall

# onject file

OBJECTS=main.o RB_Insert.o RB_Delete.o
EXE=delete
all: $(EXE)

$(EXE): $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

RB_Insert.o: RB_Insert.cpp
	$(CC) $(CFLAGS) RB_Insert.cpp

RB_Delete.o:RB_Delete.cpp
	$(CC) $(CFLAGS) RB_Delete.cpp


clean:
	rm -rf *o 
