#include "Triangle3d.h"
#include <SFML/OpenGL.hpp>

Triangle3d::Triangle3d(const Vec3f _PointOne, 
					   const Vec3f _PointTwo, 
					   const Vec3f _PointThree) : ThreeD(3)
{
	ThreeD::getVertex(0).position = _PointOne;
	ThreeD::getVertex(1).position = _PointTwo;
	ThreeD::getVertex(2).position = _PointThree;
}

Triangle3d::~Triangle3d()
{
}

void Triangle3d::render()
{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < ThreeD::getVertexCount(); i++)
	{
		Vec3f position = ThreeD::getVertex(i).position;
		Color3f color = ThreeD::getVertex(i).toPercentage();
		glColor3f(color.r, color.g, color.b);
		glVertex3f(position.x, position.y, position.z);
	}
	glEnd();
}
