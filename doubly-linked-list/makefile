labone: main.o executive.o
	g++ -std=c++11 -g -Wall main.o executive.o -o labone

main.o: main.cpp executive.h node.h
	g++ -std=c++11 -g -Wall -c main.cpp
	
executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp
	
clean: 
	rm *.o labone
