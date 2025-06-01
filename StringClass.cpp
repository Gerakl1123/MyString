
#include "StringClass.h"

MyString MyString::operator+(const MyString& other)
{
    MyString CatSTR;
    int len = strlen(ch) + strlen(other.ch) + 1;
    CatSTR.ch = new char[len];

    strcpy_s(CatSTR.ch, len, ch);
    strcat_s(CatSTR.ch,len,other.ch);


    return CatSTR;

}

MyString MyString::operator-(const MyString& other)
{
 
    if (strlen(ch) < strlen(other.ch))
    {
        std::cerr << "ERROR: Source string is shorter than other string." << std::endl;
        return MyString(" ");
    }

    
    char* UnCat = new char[strlen(ch) + 1];
    size_t j = 0;

    for (size_t i = 0; i < strlen(ch); i++)
    {
        bool found = false;
        for (size_t c = 0; c < strlen(other.ch); c++)
        {
            if (ch[i] == other.ch[c])
            {
                found = true; // Если символ найден в other.ch, помечаем его
                break;
            }
        }
        if (!found) {
            UnCat[j++] = ch[i];
        }
    }

    UnCat[j] = '\0'; // Завершаем строку нулевым символом


    MyString result(UnCat);
    delete[] UnCat;
    return result;
}

MyString::MyString(const MyString& other)
{
   
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
        std::cerr << " Error ";
        exit(-1);
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
    if (SizeA > other.SizeA) return true;
    if (SizeA < other.SizeA) return false;

    return strcmp(ch, other.ch) > 0;
}

bool MyString::operator<=(const MyString& other)
{
    if (SizeA < other.SizeA) return true;
    if (SizeA > other.SizeA) return false;

    return strcmp(ch, other.ch) <= 0;
}

bool MyString::operator>=(const MyString& other)
{
    if (SizeA > other.SizeA) return true;
    if (SizeA < other.SizeA) return false;

    return strcmp(ch,other.ch) >= 0;
}

std::ostream& operator<<(std::ostream& os, const MyString& other)
{
    if (other.ch)
    {
        os << other.ch;
    }
    else
    {
        std::cout << "empty\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, MyString& other)
{
    char buffer[254];
    is >> buffer;
    delete[] other.ch;

    other.SizeA = strlen(buffer) + 1;
    other.ch = new char [other.SizeA];

    strcpy_s(other.ch, other.SizeA, buffer);
    return is;
}

