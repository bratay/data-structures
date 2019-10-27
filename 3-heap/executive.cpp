#include "executive.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Executive::Executive(string filename)
{

  //.myTree = new BiSearchTree();
  // string curInput;

  // ifstream infile;
  // infile.open(filename);

  // while(getline(infile, curInput, ','))
  // {
  //   myTree->insert(curInput);
  // }

  run();
}
Executive::~Executive()
{
}

void Executive::run()
{
  int choice = 0;
  do
  {
    std::cout << "1 - Insert\n"
              << "2 - Delete Min\n"
              << "3 - Find Min\n"
              << "4 - Find Max\n"
              << "5 - Delete Max\n"
              << "6 - Level Order\n"
              << "7 - Exit\n"
              << "choice > ";
    std::cin >> choice;

    int value;
  //   switch (choice)
  //   {
  //   case 1:
  //     std::cout << "Insert value: ";
  //     std::cin >> value;
  //     min.Insert(value);
  //     max.Insert(value);
  //     break;
  //   case 2:
  //     std::cout << "Deleting min from MinHeap\n";
  //     min.DeleteMin();
  //     min.LevelOrder();
  //     std::cout << "Deleting min from MaxHeap\n";
  //     max.DeleteMin();
  //     max.LevelOrder();
  //     break;
  //   case 3:
  //     value = min.FindMin();
  //     std::cout << "MinHeap min value: " << value << std::endl;
  //     value = max.FindMin();
  //     std::cout << "MaxHeap min value: " << value << std::endl;
  //     break;
  //   case 4:
  //     value = min.FindMax();
  //     std::cout << "MinHeap max value: " << value << std::endl;
  //     value = max.FindMax();
  //     std::cout << "MaxHeap max value: " << value << std::endl;
  //     break;
  //   case 5:
  //     std::cout << "Deleting max from MinHeap\n";
  //     min.DeleteMax();
  //     min.LevelOrder();
  //     std::cout << "Deleting max from MaxHeap\n";
  //     max.DeleteMax();
  //     max.LevelOrder();
  //     break;
  //   case 6:
  //     std::cout << "MinHeap LevelOrder\n";
  //     min.LevelOrder();
  //     std::cout << "MaxHeap LevelOrder\n";
  //     max.LevelOrder();
  //     break;
  //   case 7:
  //     std::cout << "Exiting...\n";
  //     break;
  //   default:
  //     std::cout << "Invalid choice\n";
  //   }
  } while (choice != 7);
}
