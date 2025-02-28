


#include "Point.hpp"




Point::Point():y(0), x(0){

}




Point::Point(const float x_val, const float y_val):y(y_val),x(x_val){

}     


Point::Point(const Point &src):y(src.x),x(src.y){
    
}

Point::~Point(){

}


Point& Point::operator=(const Point &src){ 

        (void)src;
        return *this;
}


Fixed Point::getX() const { 
    
    return this->x;

}

Fixed Point::getY() const {
     return this->y;

}
