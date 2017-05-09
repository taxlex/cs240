PROJ = program3
SOURCE1 = Map
SOURCE2 = City

OBJECTS = $(PROJ).o $(SOURCE1).o $(SOURCE2).o 
DEBUG = -g

all: $(OBJECTS)
	g++ $(OBJECTS) $(DEBUG) -o $(PROJ)
$(PROJ).o: $(PROJ).cpp
	g++ -c $(PROJ).cpp $(DEBUG) -std=c++14 -o $(PROJ).o
$(SOURCE1).o: $(SOURCE1).cpp
	g++ -c $(SOURCE1).cpp $(DEBUG) -o $(SOURCE1).o
$(SOURCE2).o: $(SOURCE2).cpp
	g++ -c $(SOURCE2).cpp $(DEBUG) -o $(SOURCE2).o

run: all
	./$(PROJ)
	
checkmem: all
	valgrind ./$(PROJ)
	
clean: 
	rm $(OBJECTS) $(PROJ)
