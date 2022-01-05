#include "RAII.h"
#include <iostream>
#include <string>
#include <map>

MyPort::MyPort() {
    m_text = 10;
}

MyPort::~MyPort() {

}

void MyPort::doSomething() {
    std::cout << " server1 :  80" << std::endl;
}

void testRAII() {
  std::shared_ptr<MyPort> port1(new MyPort);
  std::cout << "port count = " << port1.use_count() << std::endl;
  std::shared_ptr<MyPort> port2 = port1;
  std::cout << "port count = " << port2.use_count() << std::endl;
  std::shared_ptr<MyPort> port3 = port2;
  std::cout << "port count = " << port3.use_count() << std::endl;

  std::cout << "port count = " << port2.use_count() << std::endl;
  std::cout << "port count = " << port1.use_count() << std::endl;
}

void testContainerRAII() { 
    std::map<std::string, MyPort> portMap;
    
    MyPort *port = new MyPort;
    portMap["port"] = *port;

    std::cout << " m_test = " << port->m_text << std::endl;

    std::cout << "testContainerRAII" << std::endl;
}