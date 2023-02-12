#include <iostream>
#include "Fraction.hpp"
#include "Complex.hpp"
#include "Flat.hpp"
#include "Overcoat.hpp"
#include "SString.hpp"
#include "Array.hpp"
#include "Data.hpp"

int main() {

// //   Встреча №6
// //   Задание    1.
//    Fraction frac(2, 5);
//    Fraction fr(2, 3);
//    frac -= fr;
//    frac.print();
//  //  Задание    2.
//    Complex com(3, 5);
//    Complex c(3, 6);
//    com *= c;
//    com.Print();

////Встреча №7
////Задание 1
//    Overcoat over("shorts", 1500);
//    Overcoat ov("bloos", 4500);
//    over.printOvercoat();
//    ov.printOvercoat();
//    //over=ov;
//    if (ov == over) {
//        std::cout << "true";
//    } else {
//        std::cout << "false";
//    }
//    std::cout << std::endl;
//    if (ov > over) {
//        std::cout << "true";
//    } else {
//        std::cout << "false";
//    }

////Задание 2.
//    Flat flat(41.1, 2155000);
//    Flat f(45.5, 2500000);
//    if (flat == f) {
//        std::cout << "true";
//    } else {
//        std::cout << "false";
//    }
//    std::cout << std::endl;
//    flat.printFlat();
//    if (flat > f) {
//        std::cout << "true";
//    } else {
//        std::cout << "false";
//    }

//
//    Array<int> array{1, 2, 5, 64, 9, 4, 13, 15, 56};
//    std::cout << array;
//    Array<int> ar{1, 12, 3};
//    std::cout << ar;
//    ar = array;
//    ar.Add(65);
//    ar.Remove(3);
//    std::cout << ar;


//    SString s("vecher");
//    std::cout << s[3];
//    std::cout<<(int)s;
    Data data{23, 5, 1990};
    std::cout << data;
    Data d{23, 10, 3};
    data -= d;
    std::cout << (data);
}
