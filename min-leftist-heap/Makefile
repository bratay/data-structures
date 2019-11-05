labeight: main.o executive.o minLeftistHeap.o
	g++ -std=c++11 -g -Wall main.o executive.o minLeftistHeap.o -o labeight

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

minLeftistHeap.o: minLeftistHeap.cpp minLeftistHeap.h
	g++ -std=c++11 -g -Wall -c minLeftistHeap.cpp

clean:
	rm *.o labeight
