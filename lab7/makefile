PROJ = lab7
SOURCE1 = BSTree
#SOURCE2 =
#SOURCE3 = 
OBJECTS = $(PROJ).o $(SOURCE1).o
DEBUG = -g

all: $(OBJECTS)
	g++ $(OBJECTS) $(DEBUG) -o $(PROJ)
$(PROJ).o: $(PROJ).cpp
	g++ -c $(PROJ).cpp $(DEBUG) -o $(PROJ).o
$(SOURCE1).o: $(SOURCE1).cpp
	g++ -c $(SOURCE1).cpp $(DEBUG) -o $(SOURCE1).o
#$(SOURCE2).o: $(SOURCE2).cpp
	#g++ -c $(SOURCE2).cpp $(DEBUG) -o $(SOURCE2).o
#$(SOURCE3).o: $(SOURCE3).cpp
	#g++ -c $(SOURCE3).cpp $(DEBUG) -o $(SOURCE3).o

run: all
	./$(PROJ)
	
checkmem: all
	valgrind ./$(PROJ)
	
clean: 
	rm $(OBJECTS) $(PROJ)
