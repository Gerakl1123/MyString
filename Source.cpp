#include"StringClass.h"
#include "IOString.h" // уже есть в StringClass.h 

 IO* ptr;// через указатель ptr обращщаеммся к методам

int main()
{
	MyString Str("Hello World");
	Str[10] = 97;
	std::cout << Str[10];
	std::cout << Str;

	//ptr->print and read
	return 0;
}