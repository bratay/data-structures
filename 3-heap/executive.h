#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include "maxHeap.h"
#include "minHeap.h"

using namespace std;

class Executive
{

private:
	MinHeap *minHeap = nullptr;
	MaxHeap *maxHeap = nullptr;

public:
	Executive(string filename);
	~Executive();

	void run();
};
#endif
