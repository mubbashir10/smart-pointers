class ReferenceCount {

public:

	ReferenceCount();  //default constructor
	~ReferenceCount();                //destructor; would delete the allocated buffer
	ReferenceCount(const ReferenceCount&);              //constructor for shallow copying
	ReferenceCount(char*, int);   //constructor to convert a char*
	char charAt(int) const;   //returns the character at the passed index
	int length() const;                            //returns the length of the buffer
	void reserve(int);                             //allocates memory for the string, according to the passed character length
	void append(char);                          //appends a single character at the end
	int refcount();

private:

	int* _refcount;
	char* _strbuf;                                   //buffer to store the original string
	int _length;                                       //length of the string
	int capacity;
};
