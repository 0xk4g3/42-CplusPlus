
#include  "Point.hpp"


static Fixed triangle_area(Point const &a , Point const &b , Point const &c){
        
                return Fixed(0.5f) * 
    (((a.getX() * (b.getY() - c.getY())) +
     (b.getX() * (c.getY() - a.getY())) +
     (c.getX() * (a.getY() - b.getY()))
    ).abs());
}
 

 
bool bsp(Point const a, Point const b, Point const c, Point const point){
        
      
      Fixed Mainarea = triangle_area(a , b , c);
      Fixed areaP1 =  triangle_area(a ,b ,point);
      Fixed areaP2 =  triangle_area(a,point , c) ;
      Fixed areaP3 =  triangle_area(point, b, c) ; 
         
      if(areaP1 == 0 ||areaP2 == 0 || areaP3 == 0)
            return false;
            
    return true;
     
}
