labsix: main.o executive.o minHeap.o maxHeap.o
	g++ -std=c++11 -g -Wall main.o executive.o minHeap.o maxHeap.o -o labsix

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

minHeap.o: minHeap.cpp minHeap.h
	g++ -std=c++11 -g -Wall -c minHeap.cpp

maxHeap.o: maxHeap.cpp maxHeap.h
	g++ -std=c++11 -g -Wall -c maxHeap.cpp

clean:
	rm *.o labsix
