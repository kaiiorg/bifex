PROGRAM_NAME = bifex
OBJECTS = key_types.o bif_entry.o key_entry.o key.o
CPP_VERSION = -std=c++17

all: clean $(OBJECTS) main

main: $(OBJECTS)
	g++ -c $(CPP_VERSION) -o main.o main.cpp
	g++ $(CPP_VERSION) -o $(PROGRAM_NAME) main.cpp $(OBJECTS)

key_types.o:
	g++ -c $(CPP_VERSION) -o key_types.o key_types.cpp

bif_entry.o:
	g++ -c $(CPP_VERSION) -o bif_entry.o bif_entry.cpp

key_entry.o:
	g++ -c $(CPP_VERSION) -o key_entry.o key_entry.cpp

key.o:
	g++ -c $(CPP_VERSION) -o key.o key.cpp

clean:
	rm -f *.o
