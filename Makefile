COMP = g++
FLAGS = -O3

all:
	$(COMP) *.cpp *.hpp $(FLAGS) -o exec

clean:
	rm *.o *.h.gch exec