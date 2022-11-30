#include "Rectangle.h"
#include <iostream>

RectangleGL::RectangleGL(const FloatRect _Rect) : TwoD(4)
{
	TwoD::getVertex(0).position = Vec2f(_Rect.left(), _Rect.top()); //Top left
	TwoD::getVertex(1).position = Vec2f(_Rect.right(), _Rect.top()); //Top right
	TwoD::getVertex(2).position = Vec2f(_Rect.right(), _Rect.bottom()); //Bottom right
	TwoD::getVertex(3).position = Vec2f(_Rect.left(), _Rect.bottom()); //Bottom left
}

RectangleGL::~RectangleGL()
{
}

void RectangleGL::render()
{
	glBegin(GL_QUADS);
	for (int i = 0; i < TwoD::getVertexCount(); i++)
	{
		Vertex v = TwoD::getVertex(i);
		Color3f perc = v.color.toPercentage();
		glColor3f(perc.r, perc.g, perc.b);
		glVertex2f(v.position.x, v.position.y);
	}
	glEnd();
}
