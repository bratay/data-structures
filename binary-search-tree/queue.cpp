#include "queue.h"
#include <string>
#include "binaryNode.h"
#include <stdexcept>

using namespace std;

template <typename T>
Queue<T>:: Queue(){
	length =0;
	head = nullptr;
}

template <typename T>
Queue<T>:: ~Queue(){
	while(isEmpty() == false){
		dequeue();
	}
}

//add to the back
//only using left pointer of binary node disregard the right child ptr
template <typename T>
void Queue<T>:: enqueue(T newEntry){

	if(length ==0){
		BinaryNode<T>* newNode= new BinaryNode<T>(newEntry);
		head=newNode;
	}else{
		BinaryNode<T>* tempNode=head;// a temp node to get to the back
		BinaryNode<T>* newNode= new BinaryNode<T>(newEntry);

		while(tempNode->getLeftChildPtr() != nullptr){
			tempNode =tempNode->getLeftChildPtr();
		}

		tempNode->setLeftChildPtr(newNode);
		tempNode= nullptr;
	}

	length +=1;
}

template <typename T>
bool Queue<T>:: isEmpty() const{
	if(head ==nullptr){
		return(true);
	}else{
		return(false);
	}
}

//remove from front
template <typename T>
void Queue<T>:: dequeue(){
	if(isEmpty() ==false){
		BinaryNode<T>* temp =head;
		head = head->getLeftChildPtr();
		temp->setLeftChildPtr(nullptr);
		delete temp;
		length -=1;
	}else{
		throw runtime_error("\nERROR_Queue is empty in dequeue");
	}
}

template <typename T>
T Queue<T>:: peekFront() const{
	if(isEmpty() == false){
		return(head->getItem());
	}else{
		throw runtime_error("ERROR_Queue is empty in peek front");
	}
}

template <typename T>
int Queue<T>:: getLength(){
	return(length);
}
