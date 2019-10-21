labfive: main.o executive.o biSearchTree.o
	g++ -std=c++11 -g -Wall main.o executive.o biSearchTree.o -o labfive

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

biSearchTree.o: biSearchTree.cpp biSearchTree.h
	g++ -std=c++11 -g -Wall -c biSearchTree.cpp

clean:
	rm *.o labfive
