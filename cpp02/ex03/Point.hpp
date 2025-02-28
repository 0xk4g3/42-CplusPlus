#ifndef POINT_HPP
#define  POINT_HPP
#include "Fixed.hpp"

class  Point { 


             private:
                Fixed const y;
                Fixed const x;
            public: 
              
            // START OF THE ORTHODOCS    
            Point();
            Point(const Point &src);
            Point& operator=(const Point &src); 
            Point(const float x_val ,const float y_val);
            ~Point();
            
            // FINISH OF THE ORTHOD
           
            // FUNCTIONS 
            Fixed getY() const;
            Fixed getX() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
