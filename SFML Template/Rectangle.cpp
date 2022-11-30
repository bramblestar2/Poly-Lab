#include "Rectangle.h"
#include <iostream>

RectangleGL::RectangleGL(const FloatRect _Rect) : TwoD(4)
{
	setSize(_Rect.size);

	TwoD::getGlobalBounds() = _Rect;
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
		FloatRect bounds = TwoD::getGlobalBounds();
		glColor3f(perc.r, perc.g, perc.b);
		glVertex2f(v.position.x + bounds.left(), v.position.y + bounds.top());
	}
	glEnd();
}

void RectangleGL::setSize(const Vec2f _Size)
{
	TwoD::getVertex(0).position = Vec2f(0, 0); //Top left
	TwoD::getVertex(1).position = Vec2f(_Size.x, 0); //Top right
	TwoD::getVertex(2).position = Vec2f(_Size.x, _Size.y); //Bottom right
	TwoD::getVertex(3).position = Vec2f(0, _Size.y); //Bottom left

	TwoD::getGlobalBounds().size = _Size;
}
