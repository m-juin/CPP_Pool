
#include <Point.hpp>

float CalculateArea(Point const a, Point const b, Point const c)
{
	float ret = (a.GetX() - c.GetX()) * (b.GetY() - c.GetY()) - (b.GetX() - c.GetX()) * (a.GetY() - c.GetY());
		return ret < 0 ? ((ret / 2.0f)  * -1) : (ret / 2.0f);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float FullArea;
	float Area1;
	float Area2;
	float Area3;

	FullArea = CalculateArea(a, b, c);
	Area1 = CalculateArea(a, b, point);
	Area2 = CalculateArea(a, c, point);
	Area3 = CalculateArea(b, c, point);

	if (Area1 == 0 || Area2 == 0 || Area3 == 0)
		return (false);
	return (Area1 + Area2 + Area3 == FullArea);
}

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