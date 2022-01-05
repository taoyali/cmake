
#include "personal.h"
#include <iostream>

// using namespace std;

Personal::Personal() : nameLen(10), cityLen(10) {
    name = new char[nameLen + 1];
    city = new char[cityLen + 1];
}

Personal::Personal(char *ssn, char *n, char *c, int y, long s) : nameLen(10), cityLen(10) {
    name = new char[nameLen + 1];
    city = new char[cityLen + 1];
    strcpy(SSN, ssn);
    strcpy(name, n);
    strcpy(city, c);
    year = y;
    salary = s;
}


void Personal::writeToFile(fstream& out) const {
    out.write(SSN, 9);
    out.write(name, nameLen);
    out.write(city, cityLen);
    out.write(reinterpret_cast<const char*>(&year), sizeof(int));
    out.write(reinterpret_cast<const char*>(&salary), sizeof(int));
}

void Personal::readFromFile(fstream& in) {
    cout << "person readFromFile start" << endl;
    in.read(SSN, 9);
    in.read(name, nameLen);
    in.read(city, cityLen);
    in.read(reinterpret_cast<char*>(&year), sizeof(int));
    in.read(reinterpret_cast<char *>(&salary), sizeof(int));

    writeLegibly(std::cout);
    std::cout << std::endl;

    cout << "person readFromFile end" << endl;
}

void Personal::readKey() {
    char s[80];
    cout << "Enter SSN: ";
    cin.getline(s, 80);
    strncpy(SSN, s, 9);
    cout << "copy ssn end" << endl;
}

ostream& Personal::writeLegibly(ostream& out) {
    SSN[9] = name[nameLen] = city[cityLen] = '\0';
    out << "writeLegibly " << "SSN = " << SSN << ", name = " << name << ", city = " << city << ", year = " << year << ", salary = " << salary;
    return out;
}

istream& Personal::readFromConsole(istream& in) {
    SSN[9] = name[nameLen] = city[cityLen] = '\0';
    char s[80];
    cout << "SSN: ";
    in.getline(s, 80);
    strncpy(SSN, s, 9);

    cout << "name: ";
    in.getline(s, 80);
    strncpy(name, s, nameLen);

    cout << "city: ";
    in.getline(s, 80);
    strncpy(city, s, cityLen);

    cout << "Birthyear: ";
    in >> year;

    cout << "salary: ";
    in >> salary;

    in.ignore();

    return in;
}