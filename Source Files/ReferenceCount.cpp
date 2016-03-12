#include "ReferenceCount.h"

ReferenceCount::ReferenceCount(){
	this->_refcount = new int;
	this->_length = 0;
	this->capacity = 0; 
	this->_refcount[0] = 1;
	this->_strbuf = nullptr;
}

ReferenceCount::~ReferenceCount(){
	if(this->refcount() == 1){
		delete[] this->_strbuf;
		delete _refcount;
	}
	else{

		this->_refcount[0]--;
		this->_refcount = nullptr;
		this->_strbuf = nullptr;
	}
}

ReferenceCount::ReferenceCount(const ReferenceCount& buff){
	this->_strbuf = buff._strbuf;
	this->_length = buff._length;
	this->capacity = buff.capacity;
	this->_refcount = buff._refcount;
	this->_refcount[0]++;
}

ReferenceCount::ReferenceCount(char * str, int len){
	this->_refcount = new int;
	this->_refcount[0] = 1;
	this->_length = len;
	this->capacity = len;

	this->_strbuf = new char[len];

	for (int i = 0; i < len; i++){
		this->_strbuf[i] = str[i];
	}
}

void ReferenceCount::reserve(int s){
	this->capacity = s;

	if (this->_strbuf == nullptr){
		this->_strbuf = new char[s];
		if (this->refcount() != 1){
			this->_refcount[0]--;
			this->_refcount = new int;
			this->_refcount[0] = 1;
		}
	}
	else{
		char * str = this->_strbuf;
		this->_strbuf = new char[s];

		for (int i = 0; i < this->_length; i++){
			this->_strbuf[i] = str[i];
		}

		if (this->refcount() != 1){
			this->_refcount[0]--;
			this->_refcount = new int;
			this->_refcount[0] = 1;
		}
		else
			delete[] str;
	}
}

void ReferenceCount::append(char c){
	if (this->capacity > this->_length){
		if (this->refcount() != 1){
			this->_refcount[0]--;
			this->_refcount = new int;
			this->_refcount[0] = 1;

			char * str = this->_strbuf;
			this->_strbuf = new char[this->capacity];

			for (int i = 0; i < this->_length; i++){
				this->_strbuf[i] = str[i];
			}
		}
		
		this->_strbuf[(this->_length)++] = c;
	}
	else{
		if (this->_length == 0){
			if (this->refcount() != 1){
				this->_refcount[0]--;
				this->_refcount = new int;
				this->_refcount[0] = 1;
			}
			this->_strbuf = new char[2];
			this->capacity = 2;
			this->_strbuf[(this->_length)++] = c;
		}
		else{
			char * temp = this->_strbuf;
			this->capacity = 2 * this->_length;
			this->_strbuf = new char[this->capacity];

			for (int i = 0; i < this->_length; i++){
				this->_strbuf[i] = temp[i];
			}

			if (this->refcount() != 1){
				this->_refcount[0]--;
				this->_refcount = new int;
				this->_refcount[0] = 1;
			}
			else
				delete[] temp;
			this->_strbuf[(this->_length)++] = c;
		}
	}
}

char ReferenceCount::charAt(int index) const{
	if (index < this->_length)
		return this->_strbuf[index];
	return (char)0;
}

int ReferenceCount::length() const{
	return this->_length;
}

int ReferenceCount::refcount(){
	return *_refcount;
}
