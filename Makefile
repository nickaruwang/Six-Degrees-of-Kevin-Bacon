CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = sixdegrees.o utils.o

all: sixdegrees compare

sixdegrees: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o $@ sixdegrees.o utils.o

sixdegrees.o: sixdegrees.cpp utils.h utils.cpp
	$(CXX) -g $(CXXFLAGS) -c sixdegrees.cpp

utils.o: utils.cpp utils.h
	$(CXX) -g $(CXXFLAGS) -c utils.cpp

compare: comparefiles.o
	$(CXX) -g $(CXXFLAGS) -o $@ comparefiles.o

comparefiles.o: comparefiles.cpp
	$(CXX) -g $(CXXFLAGS) -c comparefiles.cpp

clean:
	rm *.o
	rm sixdegrees