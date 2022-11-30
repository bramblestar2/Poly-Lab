#include "Triangle.h"

Triangle::Triangle(const Vec2f _Size, const Vec2f _Position) : TwoD(3)
{
	TwoD::getGlobalBounds() = FloatRect(_Position, _Size);

	TwoD::getVertex(0).position = Vec2f(_Position.x + (_Size.x/2), _Position.y); // Top center point
	TwoD::getVertex(1).position = Vec2f(_Position.x, _Position.y + _Size.y); // Bottom left
	TwoD::getVertex(2).position = Vec2f(_Position.x + _Size.x, _Position.y + _Size.y); // Bottom right
}

Triangle::~Triangle()
{
}

void Triangle::render()
{
	glBegin(GL_TRIANGLES);
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
