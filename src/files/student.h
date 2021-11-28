#ifndef STUDENT
#define STUDENT

#include "personal.h"

class Student: Personal
{
private:
    /* data */
public:
    Student(/* args */);
    Student(char *, char *, char *, int, long, char *);
    void writeToFile(fstream &) const;
    void readFromFile(fstream &);
    void readKey();
    int size() const
    {
        return Personal::size() + majorLen;
    }

protected:
    char *major;
    const int majorLen;
    ostream &writeLegibly(ostream &);
    friend ostream &operator<<(ostream &out, Student &sr)
    {
        return sr.writeLegibly(out);
    }
    istream &readFromConsole(istream &);
    friend istream &operator>>(istream &in, Student &sr)
    {
        return sr.readFromConsole(in);
    }
};

#endif