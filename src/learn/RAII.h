#include <iostream>

// extern void testContainerRAII();

class MyPort {
  friend void testContainerRAII();

private:
  /* data */
  int m_text;
  void doSomething();
  int testAge = 1;
  int m_test{0};

public:
  MyPort(/* args */);
  ~MyPort();
};

// 如果在头文件中实现test方法，头文件被多次导入到其它文件中会报testRAII重复定义
// 如果在头文件中定义test方法，在cpp文件中实现test方法，同样会报重复定义
// void testRAII();