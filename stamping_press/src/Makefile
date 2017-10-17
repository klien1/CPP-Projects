CXX = g++
CXXFLAGS = -Wall -W -Werror -pedantic -c -g -std=c++11

all: main.o stampbuf.o stampstream.o stamp.o row.o
	$(CXX) -pedantic -o main main.o stampbuf.o stampstream.o stamp.o row.o

main.o: stampbuf.h main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

stampbuf.o: stampbuf.h stampbuf.cpp
	$(CXX) $(CXXFLAGS) stampbuf.cpp

stampstream.o: stampstream.h stampstream.cpp
	$(CXX) $(CXXFLAGS) stampstream.cpp

stamp.o: stamp.h stamp.cpp
	$(CXX) $(CXXFLAGS) stamp.cpp

row.o: row.h row.cpp
	$(CXX) $(CXXFLAGS) row.cpp

clean:
	rm *.o main