labten: main.o executive.o BinomialQueue.o PrecondViolatedExcep.o
	g++ -std=c++11 -g -Wall main.o executive.o BinomialQueue.o PrecondViolatedExcep.o -o labten

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp

BinomialQueue.o: BinomialQueue.cpp BinomialQueue.h
	g++ -std=c++11 -g -Wall -c BinomialQueue.cpp

clean:
	rm *.o labten
