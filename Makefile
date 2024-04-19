CXX := g++
CXXFLAGS := -Wall
LDFLAGS := -s
LDLIBS := -lm

SOURCES:= Queue.cpp Radix.cpp 
EXECUTABLES:= Queue.x Radix.x

OBJECTS := $(SOURCES:.cpp=.o)

.PHONY: all clean make

all: $(EXECUTABLES)

Queue.x: Queue.o ArrayQueue.hpp LinkedQueue.hpp
Stack.x: Stack.o ArrayQueue.hpp LinkedQueue.hpp

%.o: %.cpp ArrayQueue.hpp LinkedQueue.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

make: $(OBJECTS) $(EXECUTABLES)

clean:
	$(RM) $(EXECUTABLES) $(OBJECTS)



