









#include "Point.hpp"







int main(){
    
     Point a(0, 0);
     Point b(0,20);
     Point c(10, 20);
     
     Point p1(3,10 );
     Point p2(0,10);
    
     // ---------- Test the triangle ---------//
     std::cout << "the reuslt of the p1(3,10) :" << (bsp(a,b,c,p1) ? "Inside" : "Outside") <<std::endl;
     std::cout << "The result of the p2(0 , 10) :" << (bsp(a , b, c, p2) ? "inside" : "Outside") << std::endl;
     return 0;
}
