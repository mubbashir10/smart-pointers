#include "ReferenceCount.h"
#include <iostream>

using namespace std;


void testRefCountDecrease()
{
	ReferenceCount * x = new ReferenceCount();

	cout << endl << "Testing Ref Count (RC)" << endl;
	x->reserve(2);
	x->append('1');
	ReferenceCount * y = new ReferenceCount(*x);
	cout << y->refcount() << endl;
	delete x;
	x = nullptr;
	cout << y->refcount() << endl;
	if (y->refcount() == 1)
		cout << "Test Passed";
	else
		cout << "Test Failed";
}
