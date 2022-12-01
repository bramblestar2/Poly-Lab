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
	
	/*
	//REFERENCE
	//4 Points (Quad) instead of 6 points (3 per triangle)
	// < 2D Square >
	//float width = 200, height = 100;
	//float posX = 0, posY = 0;
	//glVertex3f(posX,		   posY,		  0); << Top Left Point
	//glVertex3f(posX + width, posY,		  0); << Top Right Point
	//glVertex3f(posX + width, posY + height, 0); << Bottom Right Point
	//glVertex3f(posX		 , posY + height, 0); << Bottom Left Point
	//
	// < 3D Cube >
	//float width = 200, height = 100, length = 200;
	//float posX = 0, posY = 0, posZ = 0;
	// < Front >
	//glVertex3f(posX,		   posY,		  posZ			); << Top Left Point
	//glVertex3f(posX + width, posY,		  posZ			); << Top Right Point
	//glVertex3f(posX + width, posY + height, posZ			); << Bottom Right Point
	//glVertex3f(posX,		   posY + height, posZ			); << Bottom Left Point
	// < Right >
	//glVertex3f(posX + width, posY,		  posZ			); << Top Left Point
	//glVertex3f(posX + width, posY,		  posZ + length	); << Top Right Point
	//glVertex3f(posX + width, posY + height, posZ + length	); << Bottom Right Point
	//glVertex3f(posX + width, posY + height, posZ			); << Bottom Left Point
	*/

	ThreeD::setDimensions(_Dimensions);

	//First triangle
	triangles[0].getVertex(0).position = Vec3f(); // 
	triangles[0].getVertex(1).position = Vec3f(); // 
	triangles[0].getVertex(2).position = Vec3f(); // 

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
