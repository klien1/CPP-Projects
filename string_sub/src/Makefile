all: main.o BufferedFile.o StringSub.o
	g++ -pedantic -o stringsub main.o BufferedFile.o StringSub.o

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

BufferedFile.o: TrackingDeque.h BufferedFile.h BufferedFile.cpp
	g++ -std=c++11 -g -Wall -c BufferedFile.cpp

StringSub.o: TrackingDeque.h BufferedFile.h StringSub.h StringSub.cpp
	g++ -std=c++11 -g -Wall -c StringSub.cpp

clean:
	rm stringsub *.o