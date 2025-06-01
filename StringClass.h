#ifndef STR_H
#define STR_H
#pragma once
#include <iostream>
#include <cstring>
#include"IO.h"

class IO;
class MTSTR;

class MyString {
    friend class IO;
    friend class MTSTR;
    friend inline char* CatLen(MyString& other);
public:
    friend std::ostream& operator << (std::ostream& os, const MyString& other);
    friend std::istream& operator >>(std::istream& os, MyString& other);

    // Constructor;
    MyString() : ch(nullptr), SizeA(0) {};
    explicit MyString(const char* str)
    {

        if (str == nullptr) {
            SizeA = 1;
            ch = new char[SizeA];
            ch[0] = '\0';  
        }
        else {
            SizeA = strlen(str) + 1;
            ch = new char[SizeA];
            strcpy_s(ch, SizeA, str);
        }

    };
    // Reboot operator              
    MyString(const MyString& other);
    MyString operator+(const MyString& other);
    MyString operator-(const MyString& other);
    MyString& operator=(const MyString& other);
    MyString& operator+=(const MyString& other);
    char& operator[](const int index);
    bool operator==(const MyString& other);
    bool operator!=(const MyString& other);
    bool operator<(const MyString& other);
    bool operator>(const MyString& other);
    bool operator<=(const MyString& other);
    bool operator>=(const MyString& other);

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
    char* ch;
    unsigned SizeA;
};
#endif STR_H
