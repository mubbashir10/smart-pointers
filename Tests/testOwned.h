#include "Owned.h"
#include <iostream>

using namespace std;

void testShallowCopy()
{
	Owned * x = new Owned();

	cout << endl << "Testing Shallow Copy" << endl;
	x->reserve(2);
	x->append('1');
	Owned * y = new Owned(*x);
	cout << x->length() << endl;

	if (x->length() == 0)
		cout << "Test Passed";
	else
		cout << "Test Failed";
}
