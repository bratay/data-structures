#ifndef _BINARY_NODE
#define _BINARY_NODE

template<class ItemType>
class BinaryNode{
	private:
	   ItemType              item;           // Data portion
	   BinaryNode<ItemType>* leftChildPtr;   // Pointer to left child
	   BinaryNode<ItemType>* rightChildPtr;  // Pointer to right child

	public:
		BinaryNode(ItemType anItem);
		BinaryNode(ItemType& anItem,
		        BinaryNode<ItemType>* leftPtr,
		        BinaryNode<ItemType>* rightPtr);
		//~BinaryNode();

		void setItem(ItemType anItem);
		ItemType getItem() const;

		bool isLeaf() const;

		BinaryNode<ItemType>* getLeftChildPtr() const;
		BinaryNode<ItemType>* getRightChildPtr() const;

		void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);
		void setRightChildPtr(BinaryNode<ItemType>* rightPtr);
		BinaryNode* operator=(BinaryNode<ItemType>* rightHandSide);
		bool operator ==(BinaryNode<ItemType>* rhs);
		bool operator <(BinaryNode<ItemType>* rhs);
		bool operator >(BinaryNode<ItemType>* rhs);
}; // end BinaryNode
#include "binaryNode.cpp"
#endif
