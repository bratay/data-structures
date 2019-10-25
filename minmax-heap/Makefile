labseven: main.o executive.o minMaxHeap.o
	g++ -std=c++11 -g -Wall main.o executive.o minMaxHeap.o -o labseven

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

minMaxHeap.o: minMaxHeap.cpp minMaxHeap.h
	g++ -std=c++11 -g -Wall -c minMaxHeap.cpp

clean:
	rm *.o labseven
