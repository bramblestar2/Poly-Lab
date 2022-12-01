#include "Rectangle3d.h"

Rectangle3d::Rectangle3d(const Vec3f _Dimensions, const Vec3f _Position) : ThreeD(0)
{
	setSize(_Dimensions);
	setPosition(_Position);
}

Rectangle3d::~Rectangle3d()
{
}

void Rectangle3d::render()
{
	triangles[0].render();
	triangles[1].render();
}

void Rectangle3d::setSize(const Vec3f _Dimensions)
{
	//Dimensions
	//x: Width
	//y: Height
	//z: Length
	

	ThreeD::setDimensions(_Dimensions);

	//First triangle
	triangles[0].getVertex(0).position = Vec3f(); // Top Center Point
	triangles[0].getVertex(1).position = Vec3f(); // Bottom Left Point
	triangles[0].getVertex(2).position = Vec3f(); // Bottom Right Point

	//Second triangle
}

void Rectangle3d::setPosition(const Vec3f _Position)
{
	ThreeD::setPosition(_Position);
}

int Rectangle3d::getTriangleCount() const
{
	return triangleCount;
}

Triangle3d& Rectangle3d::getTriangle(const int _It) const
{
	return triangles[_It];
}
