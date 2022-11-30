#include "Circle.h"
#include <math.h>
#include <iostream>

Circle::Circle(const float _Radius, const int _Segments, const Vec2f _Position) : TwoD(_Segments)
{
	changeSize(_Radius);

	TwoD::getGlobalBounds().size = Vec2f(_Radius*2, _Radius*2);
	TwoD::getGlobalBounds().position = _Position;
}

Circle::~Circle()
{
}

void Circle::render()
{
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < TwoD::getVertexCount(); i++)
	{
		Vertex v = TwoD::getVertex(i);
		Color3f perc = v.color.toPercentage();
		FloatRect bounds = TwoD::getGlobalBounds();
		glColor3f(perc.r, perc.g, perc.b);
		glVertex2f(v.position.x + (bounds.left() + (bounds.size.x / 2)),
				   v.position.y + (bounds.top() + (bounds.size.y / 2)));
	}
	glEnd();
}

void Circle::changeSize(const float _Radius)
{
	for (int ii = 0; ii < TwoD::getVertexCount(); ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(TwoD::getVertexCount());//get the current angle

		float x = _Radius * cosf(theta);//calculate the x component
		float y = _Radius * sinf(theta);//calculate the y component

		TwoD::getVertex(ii).position = Vec2f(x, y);

		//glVertex2f(x + cx, y + cy);//output vertex

	}
}
