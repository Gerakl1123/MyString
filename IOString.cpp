
#include "IOString.h"

std::ostream& IO::print(std::ostream& os, MyString& item)
{
    os << item.ch;

    return os;
}

std::istream& IO::read(std::istream& is, MyString& item)
{
    char buffer[255]; // массив символов можно добавить еще 

    is.getline(buffer, sizeof(buffer));// читаем строку
    // выдяляем
    item.SizeA = strlen(buffer) + 1; // установка размера для объекта
    item.ch = new char[item.SizeA]; // для нашего объекта выделяем новую память
    // копируем
    strcpy_s(item.ch, item.SizeA, buffer);

    return is;
}