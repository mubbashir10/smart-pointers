#include "Owned.h"

Owned::Owned()
{
	this->_length = 0;
	this->capacity = 0;
	this->_strbuf = nullptr;
}

Owned::~Owned()
{
	delete[] this->_strbuf;
}

Owned::Owned(Owned& buff)
{
	if (this->_strbuf != nullptr)
		delete[] this->_strbuf;
	this->_strbuf = buff._strbuf;
	this->_length = buff._length;
	this->capacity = buff.capacity;
	buff._strbuf = nullptr;
	buff._length = 0;
	buff.capacity = 0;
}

Owned::Owned(char ** str, int len)
{
	if (this->_strbuf != nullptr)
		delete this->_strbuf;
	this->_length = len;
	this->capacity = len;

	this->_strbuf = new char[len];

	for (int i = 0; i < len; i++)
	{
		this->_strbuf[i] = (*str)[i];
	}

	(*str) = nullptr;
}


void Owned::reserve(int s)
{
	this->capacity = s;

	if (this->_strbuf == nullptr)
	{
		this->_strbuf = new char[s];
	}
	else
	{
		char * str = this->_strbuf;
		this->_strbuf = new char[s];

		for (int i = 0; i < this->_length; i++)
		{
			this->_strbuf[i] = str[i];
		}

		delete[] str;
	}
}

void Owned::append(char c)
{
	if (this->capacity > this->_length)
	{
		this->_strbuf[(this->_length)++] =c;
	}
	else
	{
		if (this->_length == 0)
		{
			this->_strbuf = new char[2];
			this->capacity = 2;
			this->_strbuf[(this->_length)++] = c;
		}
		else
		{
			char * temp = this->_strbuf;
			this->capacity = 2 * this->_length;
			this->_strbuf = new char[this->capacity];

			for (int i = 0; i < this->_length; i++)
			{
				this->_strbuf[i] = temp[i];
			}

			this->_strbuf[(this->_length)++] =c;
			delete[] temp;
		}
	}
}

char Owned::charAt(int index) const
{
	if (index < this->_length)
		return this->_strbuf[index];
	return (char)0;
}

int Owned::length() const
{
	return this->_length;
}