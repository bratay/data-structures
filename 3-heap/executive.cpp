#include "executive.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Executive::Executive(string filename)
{
  minHeap = new MinHeap();
  maxHeap = new MaxHeap();

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
    cout << "1. Insert\n"
         << "2. Delete\n"
         << "3. PQ_Highest\n"
         << "4. PQ_Lowest\n"
         << "5. Levelorder\n"
         << "6. Time_LowestPQ\n"
         << "7. Exit\n";
    cout << ": ";
    std::cin >> choice;

    int num;
    switch (choice)
    {
    case 1: //Insert
      //start timer

      //stop timer
      break;
    case 2: //Delete
      num = minHeap->removeMin();
      std::cout << num << " was delete from MinHeap\n";
      num = maxHeap->removeMax();
      std::cout << num << " was delete from MaxHeap\n";
      break;
    case 3: //pq high
      num = minHeap->findMin();
      std::cout << "MinHeap min value: " << num << std::endl;
      num = maxHeap->findMin();
      std::cout << "MaxHeap min value: " << num << std::endl;
      break;
    case 4: //pq low
      num = minHeap->findMax();
      std::cout << "MinHeap max value: " << num << std::endl;
      num = maxHeap->findMax();
      std::cout << "MaxHeap max value: " << num << std::endl;
      break;
    case 5: //level order
      std::cout << "Deleting max from MinHeap\n";
      minHeap->removeMax();
      minHeap->levelorder();
      std::cout << "Deleting max from MaxHeap\n";
      maxHeap->removeMax();
      maxHeap->levelorder();
      break;
    case 6: //time lowest
      std::cout << "MinHeap levelorder\n";
      minHeap->levelorder();
      std::cout << "MaxHeap levelorder\n";
      maxHeap->levelorder();
      break;
    case 7: //exit
      std::cout << "Exiting...\n";
      break;
    default:
      std::cout << "Invalid choice\n";
    }
  } while (choice != 7);
}
