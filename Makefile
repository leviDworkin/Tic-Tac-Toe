CXX = clang++-5.0
CXXFLAGS = -std=c++17
a.out: Board.o DummyPlayers.o
	$(CXX) $(CXXFLAGS) Board.o DummyPlayers.o -o a.out
Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c Board.cpp
DummyPlayers.o: DummyPlayers.cpp DummyPlayers.h
	$(CXX) $(CXXFLAGS) -c DummyPlayers.cpp
clean:
	rm *.o a.out
