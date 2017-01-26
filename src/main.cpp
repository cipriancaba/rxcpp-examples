#include <iostream>
#include <rxcpp/rx.hpp>
#include "SimpleOperators.h"

namespace Rx {
  using namespace rxcpp;
  using namespace rxcpp::sources;
  using namespace rxcpp::operators;
  using namespace rxcpp::util;
}
using namespace Rx;

int main() {
  std::cout << "Hello, RxCpp!" << std::endl;

  string j = "{ \"happy\": true, \"pi\": 3.141 }";

  auto o = new SimpleOperators();

  auto l$ = from(j) |
            o->convertFromStringToJson();

  auto handler_next = [=](json j) { cout << "is object" << j.is_object() << endl; };
  auto handler_error = [=](std::exception_ptr e) {
    try { rethrow_exception(e); }
    catch (const exception &ex) {
      cerr << ex.what() << endl;
    }
  };
  auto handler_completed = [=] { cout << "on completed" << endl; };

  l$.subscribe(handler_next,
               handler_error,
               handler_completed
  );

  return 0;
}