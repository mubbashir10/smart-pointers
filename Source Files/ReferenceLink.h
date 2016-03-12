#include <stdlib.h>
#include <vector>

using namespace std;

class ReferenceLink {

public:

	ReferenceLink();  //default constructor
	~ReferenceLink();                //destructor; would delete the allocated buffer
	ReferenceLink(const ReferenceLink&);              //constructor for shallow copying
	ReferenceLink(char*, int);   //constructor to convert a char*
	char charAt(int) const;   //returns the character at the passed index
	int length() const;                            //returns the length of the buffer
	void reserve(int);                             //allocates memory for the string, according to the passed character length
	void append(char);                          //appends a single character at the end
	vector<ReferenceLink*> * neighbours;

private:

	char* _strbuf;                                   //buffer to store the original string
	int _length;                                       //length of the string
	int capacity;
};
