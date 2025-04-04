
#include "IOString.h"

std::ostream& IO::print(std::ostream& os, MyString& item)
{
    os << item.ch;

    return os;
}

std::istream& IO::read(std::istream& is, MyString& item)
{
    char buffer[255]; // ������ �������� ����� �������� ��� 

    is.getline(buffer, sizeof(buffer));// ������ ������
    // ��������
    item.SizeA = strlen(buffer) + 1; // ��������� ������� ��� �������
    item.ch = new char[item.SizeA]; // ��� ������ ������� �������� ����� ������
    // ��������
    strcpy_s(item.ch, item.SizeA, buffer);

    return is;
}