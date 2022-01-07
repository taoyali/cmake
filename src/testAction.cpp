#include "testAction.h"
//#include "learn/RAII.h"


extern void testRAII();
extern void testContainerRAII();
extern void testRangeBase();

void TestAction::testActionRAII() {
  // testRAII();
  testContainerRAII();
}

void TestAction::testConst() {
    constexpr int x = 5;
    std::cout << "test const x = " << *(&x) << std::endl;
    std::cout << "test const x address = " << &x << std::endl;
    
    *(int *)(&x) = 6;

    std::cout << "test const x = " << x << std::endl;
    std::cout << "test const x = " << *(&x) << std::endl;
    std::cout << "test const x address = " << &x << std::endl;
}

void TestAction::testForEach() { 
    testRangeBase();
}