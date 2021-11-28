#ifndef DATABASE
#define DATABASE

#include <fstream>

template<class T>
class Database
{
public:
    Database<T>() { };
    void run();

private:
    fstream db;
    char fName[20];
    ostream& print(ostream&);
    void add(T&);
    bool find(const T&);
    void modify(const T&);
    friend ostream& operator<<(ostream& out, Database& db) {
        return db.print(out);
    }
};

#endif

template <class T>
void Database<T>::add(T& d)
{
    db.open(fName, ios::in | ios::out | ios::binary);
    db.seekp(0, ios::end);
    d.writeToFile(db);
    db.close();
}

template <class T>
void Database<T>::modify(const T& d)
{
    T tmp;
    db.open(fName, ios::in | ios::out | ios::binary);
    if (!db)
    {
        cout << "file: " << fName << "不存在！！！" << endl;
        return;
    }
    
    while (!db.eof())
    {
        cout << "read from in the database \n";
        tmp.readFromFile(db);
        if (tmp == d)
        {
            cin >> tmp;
            db.seekp(-d.size(), ios::cur);
            tmp.writeToFile(db);
            db.close();
            return;
        }
    }
    db.close();
    cout << "the record to be modified is not in the database \n";
}

template <class T>
bool Database<T>::find(const T& d)
{
    T tmp;
    db.open(fName, ios::in | ios::binary);
    while (!db.eof())
    {
        tmp.readFromFile(db);
        if (tmp == d)
        {
            db.close();
            return true;
        }
    }

    db.close();
    return false;
}

template <class T>
ostream &Database<T>::print(ostream &out)
{
    T tmp;
    db.open(fName, ios::in | ios::binary);
    while (true)
    {
        tmp.readFromFile(db);
        if (db.eof())
        {
            break;
        }
        out << tmp << endl;
    }
    db.close();
    return out;
}

template <class T>
void Database<T>::run()
{
    cout << "File name: ";
    cin >> fName;
    char option[5];
    T rec;
    cout << "1. add 2. find 3. modify a record 4. exit \n";
    cout << "Enter an option: ";
    cin.getline(option, 4);
    while (cin.getline(option, 4))
    {
        if (*option == '1')
        {
            cout << "add record " << endl;
            cin >> rec;
            add(rec);
        }
        else if (*option == '2')
        {
            cout << "find record " << endl;
            rec.readKey();
            cout << "The record is " << endl;
            if (find(rec) == false)
            {
                cout << "not " << endl;
            }
            cout << "in the database " << endl;
        }
        else if (*option == '3')
        {
            cout << "modify record " << endl;
            rec.readKey();
            modify(rec);
        }
        else if (*option == '4')
        {
            cout << "Wrong option: " << endl;
        }
        else {
            cout << "return " << endl;
            return;
        }
        cout << "Enter an option: " << endl;
        // cout << *this;
    }
}