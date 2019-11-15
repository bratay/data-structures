labeight: main.o executive.o MinLeftistHeap.o LeftistNode.o 
	g++ -std=c++11 -g -Wall main.o executive.o MinLeftistHeap.o LeftistNode.o -o labeight

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

minLeftistHeap.o: MinLeftistHeap.cpp MinLeftistHeap.h
	g++ -std=c++11 -g -Wall -c MinLeftistHeap.cpp

leftistNode.o: LeftistNode.cpp LeftistNode.h
	g++ -std=c++11 -g -Wall -c LeftistNode.cpp

clean:
	rm *.o labeight
