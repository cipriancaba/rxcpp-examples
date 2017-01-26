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

  auto l1$ = from(j) |
            o->convertFromStringToJson();

  auto handler_next = [=](json j) { cout << "is object" << j.is_object() << endl; };
  auto handler_error = [=](std::exception_ptr e) {
    try { rethrow_exception(e); }
    catch (const exception &ex) {
      cerr << ex.what() << endl;
    }
  };
  auto handler_completed = [=] { cout << "on completed" << endl; };

  l1$.subscribe(handler_next,
               handler_error,
               handler_completed
  );

//  auto s1 = new SimpleImplementation1();
//  auto s2 = new SimpleImplementation2();
//
//  auto l2$ = from(j) |
//             o->validateImplementation(s1) |
//             o->convertFromStringToJson();
//
//  auto handler_next2 = [=](json j) { cout << "is object" << j.is_object() << endl; };
//  auto handler_error2 = [=](std::exception_ptr e) {
//    try { rethrow_exception(e); }
//    catch (const exception &ex) {
//      cerr << ex.what() << endl;
//    }
//  };
//  auto handler_completed2 = [=] { cout << "on completed" << endl; };
//
//  l2$.subscribe(handler_next2,
//                handler_error2,
//                handler_completed2
//  );
//
//  auto l3$ = from(j) |
//             o->validateImplementation(s2) |
//             o->convertFromStringToJson();
//
//  auto handler_next3 = [=](json j) { cout << "is object" << j.is_object() << endl; };
//  auto handler_error3 = [=](std::exception_ptr e) {
//    try { rethrow_exception(e); }
//    catch (const exception &ex) {
//      cerr << ex.what() << endl;
//    }
//  };
//  auto handler_completed3 = [=] { cout << "on completed" << endl; };
//
//  l3$.subscribe(handler_next3,
//                handler_error3,
//                handler_completed3
//  );

  return 0;
}