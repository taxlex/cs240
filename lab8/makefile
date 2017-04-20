PROJ = lab8
SOURCE1 = Hash
OBJECTS = $(PROJ).o $(SOURCE1).o 
DEBUG = -g

all: $(OBJECTS)
	g++ $(OBJECTS) $(DEBUG) -o $(PROJ)
$(PROJ).o: $(PROJ).cpp
	g++ -c $(PROJ).cpp $(DEBUG) -o $(PROJ).o
$(SOURCE1).o: $(SOURCE1).cpp
	g++ -c $(SOURCE1).cpp $(DEBUG) -o $(SOURCE1).o


run: all
	./$(PROJ)
	
checkmem: all
	valgrind ./$(PROJ)
	
clean: 
	rm $(OBJECTS) $(PROJ)
