#include "testCopied.h"
#include "testOwned.h"
#include "testReferenceCount.h"
#include "testReferenceLink.h"

int main()
{
	testCharToCopied();
	testShallowCopy();
	testRefCountDecrease();
	testRefCountDec();

	char a;
	cout << endl << "Press any key to continue\n";
	cin >> a;
	return 0;
}