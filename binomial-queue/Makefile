labten: main.o executive.o BinomialQueue.o 
	g++ -std=c++11 -g -Wall main.o executive.o BinomialQueue.o -o labten

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

binomialQueue.o: BinomialQueue.cpp BinomialQueue.h
	g++ -std=c++11 -g -Wall -c BinomialQueue.cpp

clean:
	rm *.o labten
