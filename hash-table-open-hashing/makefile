labtwo: main.o executive.o table.o binaryNode.o
	g++ -std=c++11 -g -Wall main.o executive.o table.o binaryNode.o -o labtwo

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

table.o: table.cpp table.h
	g++ -std=c++11 -g -Wall -c table.cpp

binaryNode.o: binaryNode.cpp binaryNode.h
	g++ -std=c++11 -g -Wall -c binaryNode.cpp

clean:
	rm *.o labtwo
