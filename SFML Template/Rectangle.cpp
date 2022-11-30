#include "Rectangle.h"

RectangleGL::RectangleGL(const FloatRect _Rect) : TwoD(4)
{
	TwoD::getVertex(0).position = Vec2f(0, 0); //Top left
	TwoD::getVertex(1).position = Vec2f(100, 0); //Top right
	TwoD::getVertex(2).position = Vec2f(100, 100); //Bottom right
	TwoD::getVertex(3).position = Vec2f(0, 100); //Bottom left
}

RectangleGL::~RectangleGL()
{
}

void RectangleGL::render()
{
	glBegin(GL_QUADS);
	for (int i = 0; i < 4; i++)
	{
		Vertex v = TwoD::getVertex(1);
		Color3f perc = v.color.toPercentage();
		glColor3f(perc.r, perc.g, perc.b);
		glVertex2f(v.position.x, v.position.y);
	}
	glEnd();
}
