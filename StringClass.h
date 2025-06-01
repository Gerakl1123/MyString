
#pragma once
#include <iostream>
#include <cstring>
#include"IOString.h"

// Method



class IO;

class MyString {
    friend class IO;
public:
    friend std::ostream& operator << (std::ostream& os, const MyString& other);
    friend std::istream& operator >>(std::istream& os, MyString& other);

    // Constructor;
	MyString() : ch(nullptr), SizeA(0) {};
	MyString(const char* str)
	{	
		SizeA = strlen(str) + 1;
		ch = new char[SizeA];
		strcpy_s(ch, SizeA,str);

	};
    // Reboot operator              
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    MyString& operator+=(const MyString& other);
    char& operator[](const int index);
    bool operator==(const MyString& other);
    bool operator!=(const MyString& other);
    bool operator<(const MyString& other);
    bool operator>(const MyString& other);

    //Methods
    const char* getCh() const { return ch; }
       void setCh(const char* temp) {
       delete[] ch;
       SizeA = strlen(temp) + 1;
       ch = new char[SizeA];
       strcpy_s(ch, SizeA, temp);
   }
    //Destryctor
    ~MyString()
    {
		delete[] ch;
    }

   
private:
	 mutable char* ch;
	 unsigned SizeA;
};
