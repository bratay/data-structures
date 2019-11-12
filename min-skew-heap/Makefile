labNine: main.o executive.o MinSkewHeap.o SkewNode.o
	g++ -std=c++11 -g -Wall main.o executive.o MinSkewHeap.o SkewNode.o -o labNine

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

minSkewtHeap.o: MinSkewHeap.cpp MinSkewHeap.h
	g++ -std=c++11 -g -Wall -c MinSkewHeap.cpp

SkewNode.o: SkewNode.cpp SkewNode.h
	g++ -std=c++11 -g -Wall -c SkewNode.cpp

clean:
	rm *.o labNine
