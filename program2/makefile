PROJ = program2
SOURCE1 = Player
SOURCE2 = Table
SOURCE3 = Heap
SOURCE4 = Deck
SOURCE5 = Card
OBJECTS = $(PROJ).o $(SOURCE1).o $(SOURCE2).o $(SOURCE3).o $(SOURCE4).o $(SOURCE5).o
DEBUG = -g

all: $(OBJECTS)
	g++ $(OBJECTS) $(DEBUG) -o $(PROJ)
$(PROJ).o: $(PROJ).cpp
	g++ -c $(PROJ).cpp $(DEBUG) -std=c++14 -o $(PROJ).o
$(SOURCE1).o: $(SOURCE1).cpp
	g++ -c $(SOURCE1).cpp $(DEBUG) -o $(SOURCE1).o
$(SOURCE2).o: $(SOURCE2).cpp
	g++ -c $(SOURCE2).cpp $(DEBUG) -o $(SOURCE2).o
$(SOURCE3).o: $(SOURCE3).cpp
	g++ -c $(SOURCE3).cpp $(DEBUG) -o $(SOURCE3).o
$(SOURCE4).o: $(SOURCE4).cpp
	g++ -c $(SOURCE4).cpp $(DEBUG) -o $(SOURCE4).o
$(SOURCE5).o: $(SOURCE5).cpp
	g++ -c $(SOURCE5).cpp $(DEBUG) -o $(SOURCE5).o

run: all
	./$(PROJ)
	
checkmem: all
	valgrind ./$(PROJ)
	
clean: 
	rm $(OBJECTS) $(PROJ)
