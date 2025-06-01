#pragma once
#include "STR.h"
#include <fstream>
#include <string>
class MyString;

class MTSTR {
public:
	inline size_t getSize(MyString& other) const;
	MyString CatLen(MyString& other, MyString& other2);
	char* push_end(MyString& item,char);
	char* push_begin(MyString& item, char);
	char* push_insert(MyString& item, char,short);
	char* erase(MyString& item, short);
	void addToFile(MyString& item, const std::string& fileName);
	std::string readToFile(MyString& item, const std::string& fileName);
	
};

inline size_t MTSTR::getSize(MyString& other) const
{
	return other.SizeA;
}


