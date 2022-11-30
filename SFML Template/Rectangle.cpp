#include "Rectangle.h"

RectangleGL::RectangleGL(const Vec2f _Size) : TwoD(4)
{
	Color3f color(255, 255, 255);
	TwoD::setVertex(0, Vertex(Vec2f(_Rect.position), color)); // Top Left
	TwoD::setVertex(1, Vertex(Vec2f(_Rect.position.x + _Rect.size.x, _Rect.position.y),
									color)); // Top Right
	TwoD::setVertex(2, Vertex(Vec2f(_Rect.position.x + _Rect.size.x, 
									_Rect.position.y + _Rect.size.y), color)); // Bottom Right
	TwoD::setVertex(3, Vertex(Vec2f(_Rect.position.x, _Rect.position.y + _Rect.size.y), 
									color)); // Bottom Left
}

RectangleGL::RectangleGL() : TwoD(4)
{
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
