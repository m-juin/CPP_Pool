
#include <Point.hpp>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
	const Point a(0, 0);
	const Point b(10, 0);
	const Point c(0, 10);

	const Point point1(0, 0);
	const Point point2(1, 5);
	const Point point3(5, 4);

	std::cout << "Point1 (" << point1.GetX() << " , " << point1.GetY() << ") is " << std::boolalpha << bsp(a, b, c, point1) << std::endl;
	std::cout << "Point2 (" << point2.GetX() << " , " << point2.GetY() << ") is " << std::boolalpha << bsp(a, b, c, point2) << std::endl;
	std::cout << "Point3 (" << point3.GetX() << " , " << point3.GetY() << ") is " << std::boolalpha << bsp(a, b, c, point3) << std::endl;
}