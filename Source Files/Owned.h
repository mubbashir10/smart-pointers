#pragma once
class Owned {

public:

	Owned();  //default constructor
	~Owned();                //destructor; would delete the allocated buffer
	Owned(Owned&);              //constructor for shallow copying
	Owned(char**, int);   //constructor to convert a char*
	char charAt(int) const;   //returns the character at the passed index
	int length() const;                            //returns the length of the buffer
	void reserve(int);                             //allocates memory for the string, according to the passed character length
	void append(char);                          //appends a single character at the end

private:

	char* _strbuf;                                   //buffer to store the original string
	int _length;                                       //length of the string
	int capacity;

};