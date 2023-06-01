#include <Point.hpp>

static float CalculateArea(Point const a, Point const b, Point const c)
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