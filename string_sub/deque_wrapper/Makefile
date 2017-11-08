all: TrackingDeque.o main.o
	g++ -pedantic -o main main.o TrackingDeque.o

main.o: TrackingDeque.h main.cpp
	g++ -Wall -pedantic -std=c++11 -c main.cpp

TrackingDeque.o: TrackingDeque.h TrackingDeque.cpp
	g++ -Wall -pedantic -std=c++11 -c TrackingDeque.cpp

clean:
	rm *.o main