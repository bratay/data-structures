#include <iostream>
#include <fstream>
#include "BinomialQueue.h"
#include "Queue.h"

using namespace std;
int getChoice()
{
    int choice = 0;

    cout << "Pick a command:\n";
    cout << "1 - insert\n"
              << "2 - deletemin\n"
              << "3 - levelorder\n"
              << "4 - exit\n"
              << "  ->  ";

    cin >> choice;
    cout<< "\n\n";
    return choice;
}

void insertItem(BinomialQueue &bQueue)
{
    cout << "Choose a number to be added to the heap\n";
    int number;
    cin >> number;
    bQueue.insert(number);
}

void deletemin(BinomialQueue &bQueue)
{
    bQueue.deleteMin();
}

void printLevelOrder(BinomialQueue &bQueue)
{
    cout << "Level Order:\n";
    bQueue.levelOrderDisplay();
    cout << endl;
}

void menuLoop(BinomialQueue &bQueue)
{
    int choice = 0;

    while (choice != 4)
    {
        choice = getChoice();

        switch (choice)
        {
        case 3:
            printLevelOrder(bQueue);
            break;
        case 2:
            deletemin(bQueue);
            break;
        case 1:
            insertItem(bQueue);
            break;
        case 4:
        default:
            if (choice != 4)
            {
                cout << "Enter a valid choice (1-4)\n";
            }
            break;
        }
    }
}


int main()
{
    int anInteger;
    ifstream fileReader("data.txt");

    if (fileReader.is_open())
    {
        BinomialQueue bQueue;

        while (fileReader >> anInteger)
        {
            bQueue.insert(anInteger);
        }

        menuLoop(bQueue);
        fileReader.close();
    }
    else
    {
        cout << "Error reading file\n";
    }

    return 0;
}
