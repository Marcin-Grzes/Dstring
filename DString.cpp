#include <iostream>
#include <cstring> // include correct header for strcpy and strcat
#include <cstdlib> // atoi
#include "DString.h"

using namespace std;

DString::DString() {
    sp = new char[1];
    sp[0] = 0;

    cout << "Konstruktor domyslny" << endl;
}

DString::DString(const char* s) {
    if (s) {
        sp = new char[strlen(s) + 1];
        std::strcpy(sp, s);
    } else {
        sp = new char[1];
        sp[0] = 0;
    }
    cout << "Konstruktor 1argumentowy" << endl;
}

DString::DString(const DString& b) {
    if (b.sp) {
        sp = new char[strlen(b.sp) + 1];
        std::strcpy(sp, b.sp);
    } else {
        sp = new char[1];
        sp[0] = 0;
    }
    cout << "Konstruktor kopiujacy" << endl;
}

void DString::copy(const DString& b) {
    if (b.sp) {
        sp = new char[strlen(b.sp) + 1];
        std::strcpy(sp, b.sp);
    } else {
        sp = new char[1];
        sp[0] = 0;
    }
}

DString::~DString() {
    if (sp)
        delete[] sp;

    cout << endl << "Destruktor sprzata po sobie" << endl;
}

ostream& operator<<(ostream& sr, DString& des) {
    if (des.sp)
        sr << des.sp << endl;
    else
        sr << "DString jest pusty" << endl;

    return sr;
}

istream& operator>>(istream& sr, DString& des) {
    char buf[256];

    sr >> buf;

    des = DString(buf); // wersja druga - korzystajaca juz z istniejacych metod

    return sr;
}

DString& DString::operator=(const DString& b) {
    if (this != &b) {
        if (sp)
            delete[] sp;

        copy(b);
    }
    return *this;
}

DString DString::operator+(const DString& b) const {
    char* tmp;

    cout << "jestem w operatorze+ dla DString" << endl;
    tmp = new char[strlen(sp) + strlen(b.sp) + 1];
    std::strcpy(tmp, sp);
    std::strcat(tmp, b.sp);

    return DString(tmp);
}

DString DString::operator+(char* str) const {
    return *this + DString(str);
}

DString& DString::operator+=(const DString& b) {
    *this = *this + b;
    return *this;
}

DString::operator const char* () {
    return sp;
}

int DString::getLen() {
    if (sp)
        return strlen(sp) + 1;
    else
        return 0;
}

char& DString::operator[] (int i) {
    if (sp && (this->getLen() > i)) // znak istnieje w tekscie
        return sp[i];
    else
        return sp[0];
}

int DString::operator==(const DString& other) {
    int result = strcmp(sp, other.sp);
    if (result == 0)
        return 1;
    else
        return 0;
}

int DString::operator!=(const char* other) {
    int result = strcmp(sp, other);
    if (result == 0)
        return 0;
    else
        return 1;
}

DString DString::TrimLeft(int ile) {
    return DString(sp + ile);
}

DString DString::TrimRight(int ile) {
    char buf[256];
    std::strcpy(buf, sp);
    int finish = strlen(sp) - ile; // nowa dlugosc obiektu

    if (finish > 0) {
        buf[finish] = '\0';
    }

    return DString(buf);
}

DString DString::IsString(const char* text) {
    char* tmp;
    tmp = strstr(sp, text);
    return DString(tmp);
}

DString DString::GetString(int pocz, int ile) {
    char buf[256];
    std::strcpy(buf, sp);
    int finish = pocz + ile; // miejsce konca nowego obiektu
    buf[finish] = '\0';

    return DString(buf + pocz);
}

int DString::empty() {
    if (sp)
        delete[] sp;
    sp = new char;
    sp[0] = '\0';

    return 1;
}

int DString::IsEmpty() {
    if (sp == NULL || sp[0] == '\0')
        return 1;
    else
        return 0;
}