PROJ = program1
SOURCE1 = Ant
SOURCE2 = AntHill
SOURCE3 = LinkedList
OBJECTS = AntHill.o Ant.o LinkedList.o $(PROJ).o
DEBUG = -g

all: $(OBJECTS)
	g++ $(OBJECTS) $(DEBUG) -o $(PROJ)
	
$(SOURCE2).o: $(SOURCE2).cpp
	g++ -c $(SOURCE2).cpp $(DEBUG) -o $(SOURCE2).o
$(SOURCE1).o: $(SOURCE1).cpp
	g++ -c $(SOURCE1).cpp $(DEBUG) -o $(SOURCE1).o
$(SOURCE3).o: $(SOURCE3).cpp
	g++ -c $(SOURCE3).cpp $(DEBUG) -o $(SOURCE3).o
$(PROJ).o: $(PROJ).cpp
	g++ -c $(PROJ).cpp $(DEBUG) -o $(PROJ).o

run: all
	./$(PROJ)
	
checkmem: all
	valgrind ./$(PROJ)
	
clean: 
	rm $(OBJECTS) $(PROJ)
