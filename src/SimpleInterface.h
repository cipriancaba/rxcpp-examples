//
// Created by Ciprian Caba on 26/01/2017.
//

#ifndef RXCPP_EXAMPLES_SIMPLEINTERFACE_H
#define RXCPP_EXAMPLES_SIMPLEINTERFACE_H

#include <iostream>

using namespace std;

class SimpleInterface {
 public:
  virtual string whatsMyId() = 0;
};

class SimpleImplementation1: public SimpleInterface {
 public:
  virtual string whatsMyId() {
    return "1";
  }
};

class SimpleImplementation2: public SimpleInterface {
 public:
  virtual string whatsMyId() {
    return "2";
  }
};


#endif //RXCPP_EXAMPLES_SIMPLEINTERFACE_H
