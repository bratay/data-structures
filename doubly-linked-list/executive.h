#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "list.h"
#include "node.h"
#include <string>

using namespace std;

class Executive{

	private:
		string charList = "";
		List<int>* myList;

	public:
		Executive(string filename);
		~Executive();
   		void navigateTo(string url);

		void runMenu();

		bool isListEmpty();
		void insert();
		void deleteNode();
		void smallest();
		void largest();
		void average();
		void merge();
		void reverse();
   		void print();
   		int mergeHelp();
};
#endif
