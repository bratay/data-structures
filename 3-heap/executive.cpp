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
    double time = 0;
    switch (choice)
    {
    case 1: //Insert
      cout<<"Enter a number to add: ";
      cin>>num;

      if(minHeap->contains(num)){
        cout<<num<<" already in min heap\n";
      }else{
        minHeap->insert(num);
        cout<<num<<" was inserted in min heap successfully\n";
      }

      if(maxHeap->contains(num)){
        cout<<num<<" already in max heap\n";
      }else{
        maxHeap->insert(num);
        cout<<num<<" was inserted in max Heap successfully\n";
      }

      break;
    case 2: //Delete
      num = minHeap->removeMin();
      if(num == -1 ){
        cout<<"Min heap size is 0";
      }else{
        cout<<num<<" delete from min heap successfully\n";
      }

      num = maxHeap->removeMax();
      if(num == -1 ){
        cout<<"Max heap size is 0";
      }else{
        cout<<num<<" delete from max heap successfully\n";
      }
      break;
    case 3: //pq high
      num = minHeap->findMin();
      std::cout << "MinHeap min value: " << num << std::endl;
      num = maxHeap->findMin();
      std::cout << "MaxHeap max value: " << num << std::endl;
      break;
    case 4: //pq low
      num = minHeap->findMax();
      std::cout << "MinHeap min value: " << num << std::endl;
      num = maxHeap->findMax();
      std::cout << "MaxHeap max value: " << num << std::endl;
      break;
    case 5: //level order
      std::cout << "MinHeap levelorder\n";
      minHeap->levelorder();
      std::cout << "MaxHeap levelorder\n";
      maxHeap->levelorder();
      break;
    case 6: //time lowest
      //start time
      num = minHeap->findMax();
      //end time
      cout<<time<<" s\n";
      break;
    case 7: //exit
      std::cout << "Exiting...\n";
      break;
    default:
      std::cout << "Invalid choice\n";
    }
  } while (choice != 7);
}
