#include <iostream>
#include "AppConfigure.h"
#include <math.h>

#ifdef USE_MYMATH
// #include "MathFunctions.h"
#include "math.h"
#endif


#include "FileOperation.h"

#include "files/myDatabase.h"
#include "files/personal.h"
#include "files/student.h"

#include <filesystem>
#include <stdio.h>


#include "testAction.h"

// #include "zmq.h"

#include "src/AppConfigure.h"

// #include <boost/boost/lexical_case.hpp>

#include "config/filePathConfig.h"

struct Box
{
    int a;
    int b;
};



void openFile() {
  char* filePath = "/res/resource.txt";
  // char* filePath = "/Users/tyl/Desktop/file.txt";
  ifstream ifs(filePath, ios::in);
  if (ifs) {
    char data[1000];
    ifs >> data;
    cout << data << endl;
    } else {
      cout << "文件打开失败" << endl;
    }
    
    

    // FILE *file;
    // if (file = fopen(filePath, "r"))
    // {
    //     while (file->read())
    //     {
            
    //     }
        
    //     std::cout 
    // }
    
}

void fileOperation() {
  std::cout << "操作文件开始 <-------------" << std::endl;

  FileOperation fo;
  // fo.operation("/Users/taoyali/Desktop/codecs.txt");
  fo.operation("res/resource.txt");

  std::cout << "操作文件结束 ------------>" << std::endl;
}

void cmakeBuildTest() {
  std::cout << "hello CMake" << std::endl;
  std::cout << Mymake_VERSION_MAJOR << " - " << Mymake_VERSION_MINOR
            << std::endl;
#ifdef USE_MYMATH
  std::cout << "my math " << sqrt(10) << std::endl;
#else
  std::cout << "std math " << sqrt(10) << std::endl;
#endif

  std::cout << "end" << std::endl;
}

void charTest() {
  char a[] = "RUNOOB";
  std::cout << "RUNOOB 字符串的length = " << strlen(a) << std::endl;
  std::cout << a << std::endl;

  char b[10] = "abcde";

  std::cout << "b + a = " << strcat(b, a) << std::endl;

  strcpy(b, a);
  std::cout << b << std::endl;

  std::cout << " a == b ?? " << (strcmp(a, b) ? "是" : "否") << std::endl;

  std::cout << "a 中第一个N的位置 index = " << (strchr(a, 'N')) << std::endl;
}

void dbTest() {
  Database<Personal>().run();
}



int main() {

  std::cout << __FILE__ << std::endl;

  TestAction::testConst();

  TestAction::testActionRAII();

  TestAction::testForEach();


  //  yamlmap();
  //    return 0;

  // openFile();

  // dbTest();

  // fileOperation();

  // cmakeBuildTest();

  // charTest();  
}

// #include <iostream>
// #include <string>
// using namespace std;
// class Base
// { //有虚函数，因此是多态基类

// public:
//     virtual ~Base() {}
// };
// class Derived : public Base
// {
// };
// int main()
// {
//     Base b;
//     Derived d;
//     Derived *pd;
//     pd = reinterpret_cast<Derived *>(&b);
//     if (pd == NULL)
//         //此处pd不会为 NULL。reinterpret_cast不检查安全性，总是进行转换
//         cout << "unsafe reinterpret_cast" << endl; //不会执行
//     pd = dynamic_cast<Derived *>(&b);
//     if (pd == NULL)                             //结果会是NULL，因为 &b 不指向派生类对象，此转换不安全
//         cout << "unsafe dynamic_cast1" << endl; //会执行
//     pd = dynamic_cast<Derived *>(&d);           //安全的转换
//     if (pd == NULL)                             //此处 pd 不会为 NULL
//         cout << "unsafe dynamic_cast2" << endl; //不会执行
//     return 0;
// }
