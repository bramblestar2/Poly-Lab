#include "Vertex.h"

Vertex::Vertex(const Vec2f _Position, const Color3f _Color)
{
	init(_Position, _Color);
}

Color3f Vertex::toPercentage()
{
	Color3f temp;
	
	temp.r = temp.r != 0 ? temp.r / 255 : 0;
	temp.g = temp.g != 0 ? temp.g / 255 : 0;
	temp.b = temp.b != 0 ? temp.b / 255 : 0;

	return temp;
}

void Vertex::init(const Vec2f _Position, const Color3f _Color)
{
	position = _Position;
	color = _Color;
}

Vertex3d::Vertex3d(const Vec3f _Position, const Color3f _Color)
{
	init(_Position, _Color);
}

Color3f Vertex3d::toPercentage()
{
	Color3f temp;

	temp.r = temp.r != 0 ? temp.r / 255 : 0;
	temp.g = temp.g != 0 ? temp.g / 255 : 0;
	temp.b = temp.b != 0 ? temp.b / 255 : 0;

	return temp;
}

void Vertex3d::init(const Vec3f _Position, const Color3f _Color)
{
	position = _Position;
	color = _Color;
}
