#include <fstream>
#include <iostream>
using namespace std;

#include "FileOperation.h"

FileOperation::FileOperation() {}

void FileOperation::operation(string filePath) {

  char ifsData[100];
  ifstream ifs;
  ifs.open("/res/resource.txt");
  ifs >> ifsData;
  cout << "res/res.txt data = " << ifsData << endl;

  // 以写的模式打开文件
  ofstream outfile;
  outfile.open(filePath);

  cout << "输入用户名：" << endl;
  char data[100];
  cin.getline(data, 100);

  // 向文件写入数据
  outfile << data << endl;

  cout << "输入年龄：" << endl;
  cin >> data;
  cin.ignore();

  outfile << data << endl;

  outfile.close();

  // 以读的模式打开文件
  ifstream infile;
  infile.open(filePath, ios::out | ios::in);
  cout << "从 " << filePath << " 读取数据" << endl;
  char newData[100] = {};
  infile >> newData;
  // 读取的输出数据，此处cout是屏幕
  cout << newData << endl;

  infile.close();
}