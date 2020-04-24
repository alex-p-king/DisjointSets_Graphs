CXX = g++
CPP_SRCS = $(wildcard *.cpp)
OBJ_SRCS = $(CPP_SRCS:.cpp=.o)
DEPS = $(CPP_SRCS:cpp=.d=o)
FLAGS = -std=c++11 -g -Wall 

all:
	make dg

dg: $(OBJ_SRCS)
	$(CXX) $(FLAGS) -o $@ $(OBJ_SRCS)

main.o: main.cpp
	$(CXX) $(FLAGS) -c -o $@ $<
	
%.o: %.cpp %.h
	$(CXX) $(FLAGS) -c -o $@ $<

.PHONY:
	all

clean:
	rm *.o heap
