#include "RangeBase.h"
#include <vector>
#include <string>
#include <iostream>

RangeBase::RangeBase(/* args */) {}

RangeBase::~RangeBase() {}

void testRangeBase() {
  std::vector<std::string> v;
  v.push_back("hello");
  v.push_back("nihao");
  v.push_back("你好");

  for (auto i : v)
  //for (auto &&i : v)
  {
      i = "i";
  }
  
  for (auto &&i : v)
  {
    std::cout << i << std::endl;    
  }
}