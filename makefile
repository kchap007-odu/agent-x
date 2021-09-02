agent-x: main.o Agent.o Board.o
	g++ main.o Agent.o Board.o -o agent-x
	rm -f *.o

clean:
	rm -f agent-x *.o

main.o: main.cpp
	g++ -c main.cpp

Agent.o: Agent.cpp Agent.h
	g++ -c Agent.cpp

Board.o: Board.cpp Board.h
	g++ -c Board.cpp