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

// #include "zmq.h"

#include "src/AppConfigure.h"

// #include <boost/boost/lexical_case.hpp>
#include <yaml-cpp/yaml.h>

// std::string yaml = "/Users/taoyali/taoyali/project/C++/cmake/src/res/log.yml";

#include "config/filePathConfig.h"
// 相对路径
YAML::Node node = YAML::LoadFile(Config::yamlConfigFile);

struct Box
{
    int a;
    int b;
};

void yamlmap() {
    std::cout << node << std::endl;

    std::cout << "mainkey = " << node["key"]["mainkey"].as<std::string>()
              << std::endl;
    std::cout << "subkey = " << node["key"]["subkey"].as<std::string>() << std::endl;

    //std::cout << "name = " << node["logs"]["name"].as<std::string>() << std::endl;
}

int main() {

  yamlmap();
  return 0;

          // // allocate a char array
          // char *buffer = new char[sizeof(Box) * 5];
          // // cast a Box array pointer
          // Box *p = reinterpret_cast<Box *>(buffer);

          // // free the pointer? is it bad?
          // // delete p;
          // // delete[] p;

          // cout << p << endl;

          // return 0;

          // Database<Personal>().run();
          // return 0;

          std::cout
      << "操作文件开始 <-------------" << std::endl;

  FileOperation fo;
  // fo.operation("/Users/taoyali/Desktop/codecs.txt");
  fo.operation("res/resource.txt");

  std::cout << "操作文件结束 ------------>" << std::endl;

  std::cout << "hello CMake" << std::endl;
  std::cout << Mymake_VERSION_MAJOR << " - " << Mymake_VERSION_MINOR
            << std::endl;
#ifdef USE_MYMATH
    std::cout << "my math " << sqrt(10) << std::endl;
#else
    std::cout << "std math " << sqrt(10) << std::endl;
#endif

    std::cout << "end" << std::endl;

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
