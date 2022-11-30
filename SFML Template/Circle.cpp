#include "Circle.h"
#include <math.h>
#include <iostream>

Circle::Circle(const float _Radius, const Vec2f _Position) : TwoD(36)
{
	changeSize(_Radius);
	std::cout << TwoD::getVertex(5).position.x << " - " << TwoD::getVertex(5).position.y << std::endl;
}

Circle::~Circle()
{
}

void Circle::render()
{
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < TwoD::getVertexCount(); i++)
	{
		Vertex v = TwoD::getVertex(i);
		Color3f perc = v.color.toPercentage();
		glColor3f(perc.r, perc.g, perc.b);
		glVertex2f(v.position.x, v.position.y);
	}
	glEnd();
}

void Circle::changeSize(const float _Radius)
{
	for (int i = 0; i < TwoD::getVertexCount(); i++)
	{
		Vec2f pos;
		pos.x = cos(i * TwoD::getVertexCount()) * _Radius;
		pos.y = sin(i * TwoD::getVertexCount()) * _Radius;

		TwoD::getVertex(i).position = pos;
	}
}
