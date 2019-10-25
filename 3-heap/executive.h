#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include "maxHeap.h"
#include "minHeap.h"

using namespace std;

class Executive
{

private:
	MinHeap *min = nullptr;
	MaxHeap *max = nullptr;

public:
	Executive(string filename);
	~Executive();

	void run();
};
#endif
