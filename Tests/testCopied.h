#include "Copied.h"
#include <iostream>

using namespace std;

void testCharToCopied()
{

	char * x = new char[2];
	x[0] = 'a';
	x[1] = 'b';
	cout<< endl << "Testing char to Copied Pointer" << endl;
	Copied * y = new Copied(x, 2);
	cout << y->charAt(1) <<endl;

	if (y->charAt(1) == 'b')
		cout << "Test Passed";
	else
		cout << "Test Failed";

	delete y;
}
