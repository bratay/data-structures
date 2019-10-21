labfour: main.o executive.o tree.o
	g++ -std=c++11 -g -Wall main.o executive.o tree.o -o labfour

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

tree.o: tree.cpp tree.h
	g++ -std=c++11 -g -Wall -c tree.cpp

clean:
	rm *.o labfour
