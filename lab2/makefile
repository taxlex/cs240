PROJ = lab2
DEBUG = g
SOURCE = AntHill.cpp lab2.cpp
OBJECTS = AntHill.o lab2.o

all: AntHill.o lab2.o
	g++ $(OBJECTS) -o $(PROJ)
	
AntHill.o: AntHill.cpp
	g++ -c AntHill.cpp -o AntHill.o

lab2.o: lab2.cpp
	g++ -c lab2.cpp -o lab2.o

run: all
	./$(PROJ)
	
checkmem: all
	valgrind ./lab2 -$(DEBUG)
	
clean: 
	rm $(OBJECTS) $(PROJ)
