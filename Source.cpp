#include"StringClass.h"
#include "IOString.h" // ��� ���� � StringClass.h 

 IO* ptr;// ����� ��������� ptr ������������ � �������

int main()
{
	MyString Str("Hello World");
	Str[10] = 97;
	std::cout << Str[10];
	std::cout << Str;

	//ptr->print and read
	return 0;
}