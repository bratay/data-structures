#include <string>
#include <iostream>
#include "executive.h"

using namespace std;

int main(int argc, char* argv[]){

	if(argc != 2){
		cout<<"You must have 2 arguments\n";
	}else{
		string filename= "";
		filename = argv[1];
		Executive myList(filename);
	}
	
	return (0);
}
