#include "executive.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <ctime>

using namespace std;

Executive::Executive(string filename)
{
  minHeap = new MinHeap();
  maxHeap = new MaxHeap();

  string curInput;

  ifstream infile;
  infile.open(filename);

  while (getline(infile, curInput, ','))
  {
    minHeap->insert(stoi(curInput));
    maxHeap->insert(stoi(curInput));
  }

  run();
}
Executive::~Executive()
{
  delete minHeap;
  delete maxHeap;
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
    cin >> choice;

    maxHeap->buildHeap();
    minHeap->buildHeap();

    int num;
    clock_t start;
    double duration;
    switch (choice)
    {
    case 1: //Insert
      cout << "Enter a number to add: ";
      cin >> num;

      if (minHeap->contains(num))
      {
        cout << num << " already in min heap\n";
      }
      else
      {
        minHeap->insert(num);
        cout << num << " was inserted in min heap successfully\n";
      }

      if (maxHeap->contains(num))
      {
        cout << num << " already in max heap\n";
      }
      else
      {
        maxHeap->insert(num);
        cout << num << " was inserted in max Heap successfully\n";
      }

      break;
    case 2: //Delete
      num = minHeap->removeMin();
      if (num == -1)
      {
        cout << "Min heap size is 0";
      }
      else
      {
        cout << num << " delete from min heap successfully\n";
      }

      num = maxHeap->removeMax();
      if (num == -1)
      {
        cout << "Max heap size is 0";
      }
      else
      {
        cout << num << " delete from max heap successfully\n";
      }
      break;
    case 3: //pq high
      num = minHeap->findMin();
      if(num == -1)
      {
        cout<<"Heap size is 0";
        break;
      }
      cout << "MinHeap min value: " << num << endl;
      num = maxHeap->findMax();
      cout << "MaxHeap max value: " << num << endl;
      break;
    case 4: //pq low
      num = minHeap->findMax();
      cout << "MinHeap max value: " << num << endl;
      num = maxHeap->findMin();
      cout << "MaxHeap min value: " << num << endl;
      break;
    case 5: //level order
      cout << "\nMinHeap levelorder\n";
      minHeap->levelorder();
      cout << "\nMaxHeap levelorder\n";
      maxHeap->levelorder();
      break;
    case 6: //time lowest
      start = clock();

      minHeap->findMax();

      duration = (clock() - start) / (double)CLOCKS_PER_SEC;
      cout << duration << " sec\n";
      break;
    case 7: //exit
      cout << "Exiting...\n";
      break;
    default:
      cout << "Invalid choice\n";
    }
    cout << "\n\n";
  } while (choice != 7);
}
