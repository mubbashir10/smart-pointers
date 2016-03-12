class Copied {

public:

	Copied();  //default constructor
	~Copied();                //destructor; would delete the allocated buffer
	Copied(const Copied&);              //constructor for shallow copying
	Copied(char*, int);   //constructor to convert a char*
	char charAt(int) const;   //returns the character at the passed index
	int length() const;                            //returns the length of the buffer
	void reserve(int);                             //allocates memory for the string, according to the passed character length
	void append(char);                          //appends a single character at the end

private:

	char* _strbuf;                                   //buffer to store the original string
	int _length;                                       //length of the string
	int capacity;

};