
#include "StringClass.h"


MyString::MyString(const MyString& other)
{
    if (ch!= nullptr)
    {
        delete[] ch;
    }
    SizeA = other.SizeA;
    ch = new char[SizeA];
    strcpy_s(ch, SizeA, other.ch);
}

MyString& MyString::operator=(const MyString& other)
{
    if (ch != nullptr)
    {
        delete[] ch;
    }

    SizeA = other.SizeA;
    ch = new char[SizeA];
    strcpy_s(ch, SizeA, other.ch);

    return *this;
}

MyString& MyString::operator+=(const MyString& other)
{
    if (this == &other) {
        return *this;
    }
    if (other.SizeA <= 1)
    {
        return *this;
    }
    unsigned newSize = SizeA + other.SizeA - 1;
    char* Temp = new char[newSize];

    ch ? strcpy_s(Temp, newSize, ch)
        : Temp[0] = '\0';

    strcat_s(Temp, newSize, other.ch);

    delete[] ch;
    ch = Temp;
    SizeA = newSize;
    return *this;

}

char& MyString::operator[](const int index)
{
    if (index < 0 || index >= SizeA)
    {
        std::cerr<<" Error ";
    }
    return ch[index];
}

bool MyString::operator==(const MyString& other)
{
    if (SizeA != other.SizeA)
    {
        return false;
    }
    return strcmp(ch, other.ch) == 0;
}

bool MyString::operator!=(const MyString& other)
{
    return SizeA != other.SizeA;
}

bool MyString::operator<(const MyString& other)
{
    if (SizeA < other.SizeA) return true;
    if (SizeA > other.SizeA) return false;

    return strcmp(ch, other.ch) < 0;
}

bool MyString::operator>(const MyString& other)
{
    if (SizeA < other.SizeA) return true;
    if (SizeA > other.SizeA) return false;

    return strcmp(ch, other.ch) > 0;
}


std::ostream& operator<<(std::ostream& os, const MyString& other)
è
    return os << other.ch;
}

std::istream& operator>>(std::istream& is, MyString& other)
{
    return is >> other.ch;   
}
