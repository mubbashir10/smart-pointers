#include "ReferenceLink.h"
#include <iostream>

using namespace std;

void testRefCountDec()
{
	ReferenceLink * x = new ReferenceLink();
	cout << endl << "Testing Ref Count (RL)" << endl;
	x->reserve(2);
	x->append('1');
	ReferenceLink * y = new ReferenceLink(*x);
	cout << y->neighbours->size() << endl;
	delete x;
	x = nullptr;
	cout << y->neighbours->size() << endl;

	if (y->neighbours->size() == 1)
		cout << "Test Passed";
	else
		cout << "Test Failed";
}
