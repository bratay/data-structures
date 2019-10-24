#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include "maxHeap.h"
#include "minHeap.h"

using namespace std;

class Executive
{

private:
	minHeap *min = nullptr;
	maxHeap *max = nullptr;

public:
	Executive(string filename);
	~Executive();

	void run();
#endif
