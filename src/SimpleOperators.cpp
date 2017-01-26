//
// Created by Ciprian Caba on 26/01/2017.
//

#include "SimpleOperators.h"

function<observable<json>(observable<string>)> SimpleOperators::convertFromStringToJson() {
  return [](observable<string> $str) {
    return $str |
      Rx::map([](const string s) {
        return json::parse(s);
      });
  };
}

template <class T> function<observable<T>(observable<T>)> SimpleOperators::validateImplementation(SimpleInterface component) {
  return [&](observable<T> $str) {
    return $str |
           filter([&](const T item) {
             if (component.whatsMyId() == "1") {
               return true;
             } else {
               return false;
             }
            }
           );
  };
}