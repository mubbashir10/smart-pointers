#include "ReferenceLink.h"

ReferenceLink::ReferenceLink()
{
	this->neighbours = new vector<ReferenceLink*>();
	this->capacity = 0;
	this->_length = 0;
	this->neighbours->push_back(this);
	this->_strbuf = nullptr;
}

ReferenceLink::~ReferenceLink()
{
	if(this->_strbuf != nullptr)
	{
		if (neighbours->size() != 1)
		{
			for (std::vector<ReferenceLink*>::iterator it = neighbours->begin(); it != neighbours->end(); ++it)
			{
				if ((*it) == this) {
					neighbours->erase(it);
					neighbours = nullptr;
					break;
				}
			}

		}
		else
		{
			neighbours->clear();
			delete[] this->_strbuf;
			this->_strbuf = nullptr;
		}
	}
}

ReferenceLink::ReferenceLink(const ReferenceLink& buff)
{
	this->capacity = buff.capacity;
	this->_length = buff.length();
	this->_strbuf = buff._strbuf;
	this->neighbours = buff.neighbours;
	this->neighbours->push_back(this);
}

ReferenceLink::ReferenceLink(char * str, int len)
{
	this->capacity = len;
	this->_length = len;
	this->_strbuf = new char[len];

	for (int i = 0; i < len; i++) 
	{
		this->_strbuf[i] = str[i];
	}

	this->neighbours = new vector<ReferenceLink*>();
	this->neighbours->push_back(this);
}

void  ReferenceLink::reserve(int s)
{
	this->capacity = s;

	if (this->_strbuf == nullptr)
	{
		this->_strbuf = new char[s];
		if (neighbours->size() != 1)
		{
			for (std::vector<ReferenceLink*>::iterator it = neighbours->begin(); it != neighbours->end(); ++it)
			{
				if ((*it) == this) {
					neighbours->erase(it);
					break;
				}
			}

			neighbours = new vector<ReferenceLink*>();

		}
	}
	else
	{
		char * str = this->_strbuf;
		this->_strbuf = new char[s];

		for (int i = 0; i < this->_length; i++)
		{
			this->_strbuf[i] = str[i];
		}

		if (neighbours->size() != 1)
		{
			for (std::vector<ReferenceLink*>::iterator it = neighbours->begin(); it != neighbours->end(); ++it)
			{
				if ((*it) == this) {
					neighbours->erase(it);
					break;
				}
			}

			neighbours = new vector<ReferenceLink*>();

		}
		else
			delete[] str;
	}
}

void  ReferenceLink::append(char to_append)
{	
	if (this->capacity > this->_length)
	{
		if (neighbours->size() != 1)
		{
			for (std::vector<ReferenceLink*>::iterator it = neighbours->begin(); it != neighbours->end(); ++it)
			{
				if ((*it) == this) {
					neighbours->erase(it);
					break;
				}
			}

			neighbours = new vector<ReferenceLink*>();

			char * str = this->_strbuf;
			this->_strbuf = new char[this->capacity];

			for (int i = 0; i < this->_length; i++)
			{
				this->_strbuf[i] = str[i];
			}

			str = nullptr;
		}
		this->_strbuf[(this->_length)++] = to_append;
	}
	else
	{
		if (this->_length == 0)
		{
			this->_strbuf = new char[2];
			this->capacity = 2;
			this->_strbuf[(this->_length)++] = to_append;
		}
		else
		{
			char * str = this->_strbuf;
			if (neighbours->size() != 1)
			{
				for (std::vector<ReferenceLink*>::iterator it = neighbours->begin(); it != neighbours->end(); ++it)
				{
					if ((*it) == this) {
						neighbours->erase(it);
						break;
					}
				}

				neighbours = new vector<ReferenceLink*>();

				this->capacity = 2 * this->_length;
				this->_strbuf = new char[this->capacity];

				for (int i = 0; i < this->_length; i++)
				{
					this->_strbuf[i] = str[i];
				}

				str = nullptr;
			}
			else
				delete[] str;

			this->_strbuf[(this->_length)++] = to_append;
		}
	}
}


char ReferenceLink::charAt(int index) const
{
	if (index < this->_length)
		return this->_strbuf[index];
	return (char)0;
}

int  ReferenceLink::length() const
{
	return this->_length;
}