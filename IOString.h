
﻿#pragma once
#include"StringClass.h"

class MyString;

class IO
{
public:
	std::ostream& print(std::ostream& os, MyString& item);
	std::istream& read(std::istream& is, MyString& item);

}