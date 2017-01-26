//
// Created by Ciprian Caba on 26/01/2017.
//

#ifndef RXCPP_EXAMPLES_SIMPLEOPERATORS_H
#define RXCPP_EXAMPLES_SIMPLEOPERATORS_H

#include <json/json.hpp>
#include <rxcpp/rx.hpp>
#include "SimpleInterface.h"

using namespace std;
using json = nlohmann::json;

namespace Rx {
  using namespace rxcpp;
  using namespace rxcpp::sources;
  using namespace rxcpp::operators;
  using namespace rxcpp::util;
}
using namespace Rx;



class SimpleOperators {
 public:
  function<observable<json>(observable<string>)> convertFromStringToJson();
  template <class T> function<observable<T>(observable<T>)> validateImplementation(SimpleInterface component);
};


#endif //RXCPP_EXAMPLES_SIMPLEOPERATORS_H
