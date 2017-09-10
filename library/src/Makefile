CXX = g++
CXXFLAGS = -Wall -W -Werror -pedantic -c -g -std=c++11

main: main.o book.o library.o media.o film.o periodic.o
	$(CXX) -pedantic -o main main.o library.o book.o media.o film.o periodic.o

main.o: library.h main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

library.o: book.h library.cpp
	$(CXX) $(CXXFLAGS) library.cpp

media.o: media.h media.cpp
	$(CXX) $(CXXFLAGS) media.cpp

book.o: media.h book.h book.cpp
	$(CXX) $(CXXFLAGS) book.cpp

film.o: media.h film.h film.cpp
	$(CXX) $(CXXFLAGS) film.cpp

periodic.o: media.h periodic.h periodic.cpp
	$(CXX) $(CXXFLAGS) periodic.cpp

clean:
	rm -rf *.o main
	