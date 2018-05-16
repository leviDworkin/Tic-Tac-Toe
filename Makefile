CXX = clang++-5.0
CXXFLAGS = -std=c++17
a.out: main.o Board.o DummyPlayers.o
	$(CXX) $(CXXFLAGS) main.o Board.o DummyPlayers.o -o a.out
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c Board.cpp
DummyPlayers.o: DummyPlayers.cpp DummyPlayers.h
	$(CXX) $(CXXFLAGS) -c DummyPlayers.cpp
clean:
	rm *.o a.out
