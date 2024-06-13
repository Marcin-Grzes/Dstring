#pragma once
#include <iostream>
using namespace std;

class DString 
{
protected:
	char* sp;

    void copy(const DString& b); // kopiowanie tekstu
public:
	DString();
	DString(const DString& b);
	DString(const char* s);
	~DString();
	
	DString& operator=(const DString& b);
	DString operator+(const DString&) const;
	DString operator+(char*) const;
	DString& operator+=(const DString&);
	int operator==(const DString& other);
	int operator!=(const char* other);

	operator const char* ();
	char& operator[] (int i);
	int getLen();
    int empty();
	int IsEmpty();

	DString IsString(const char*);
	DString GetString(int, int);
	DString TrimRight(int);
	DString TrimLeft(int);


	friend ostream& operator<<(ostream& sr, DString& des);
	friend istream& operator>>(istream&, DString&);


};