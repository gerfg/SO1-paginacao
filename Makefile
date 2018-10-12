COMP = g++
FLAGS = -O3 -Wall -fpic

all:
	$(COMP) *.cpp *.hpp $(FLAGS) -o exec

clean:
	rm *.o *.h.gch exec