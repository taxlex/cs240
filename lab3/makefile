PROJ = lab3
DEBUG = g
SOURCE = Ant.cpp AntHill.cpp lab2.cpp
OBJECTS = AntHill.o Ant.o lab3.o

all: AntHill.o Ant.o lab3.o
	g++ $(OBJECTS) -g -o $(PROJ)
	
AntHill.o: AntHill.cpp
	g++ -c AntHill.cpp -g -o AntHill.o
Ant.o: Ant.cpp
	g++ -c Ant.cpp -g -o Ant.o

lab3.o: lab3.cpp
	g++ -c lab3.cpp -g -o lab3.o

run: all
	./$(PROJ)
	
checkmem: all
	valgrind ./lab3 -$(DEBUG)
	
clean: 
	rm $(OBJECTS) $(PROJ)
