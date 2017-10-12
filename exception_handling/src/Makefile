all: main.o Nausea.o
	g++ -g -fno-elide-constructors -pedantic -o main main.o Nausea.o

main.o: orig_stack.h main.cpp Nausea.h
	g++ -fno-elide-constructors -Wall -std=c++11 -g -pedantic -c main.cpp

Nausea.o: Nausea.cpp Nausea.h
	g++ -fno-elide-constructors -Wall -std=c++11 -g -pedantic -c Nausea.cpp

clean:
	rm -rf *.o main