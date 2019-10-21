labthree: main.o executive.o table.o qpTable.o dhTable.o
	g++ -std=c++11 -g -Wall main.o table.o qpTable.o dhTable.o executive.o -o labthree

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

table.o: table.cpp table.h
	g++ -std=c++11 -g -Wall -c table.cpp

qpTable.o: qpTable.cpp qpTable.h
	g++ -std=c++11 -g -Wall -c qpTable.cpp

dhTable.o: dhTable.cpp dhTable.h
	g++ -std=c++11 -g -Wall -c dhTable.cpp

clean:
	rm *.o labthree
