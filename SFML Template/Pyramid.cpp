#include "Pyramid.h"

Pyramid::Pyramid(const Vec3f _Dimensions, const Vec3f _Position)
{
}

Pyramid::~Pyramid()
{
}

Vec3f Pyramid::getSize() const
{
	return dimensions;
}

Vec3f Pyramid::getPosition() const
{
	return position;
}

void Pyramid::setColor(const float _R, const float _G, const float _B, const float _A)
{
	setColor(Color4f(_R, _G, _B, _A));
}

void Pyramid::setColor(const Color4f _Color)
{
	color = _Color;
}

void Pyramid::setPosition(const float _X, const float _Y, const float _Z)
{
	setPosition(Vec3f(_X, _Y, _Z));
}

void Pyramid::setPosition(const Vec3f _Position)
{
	position = _Position;
}

void Pyramid::setSize(const float _X, const float _Y, const float _Z)
{
	setSize(Vec3f(_X, _Y, _Z));
}

void Pyramid::setSize(const Vec3f _Dimensions)
{
	dimensions = _Dimensions;
}

void Pyramid::render()
{
	Vec3f total;
	total.x = position.x + dimensions.x;
	total.y = position.y + dimensions.y;
	total.z = position.z + dimensions.z;

	Color4f perc = color.toPercentage();

	//Draw 4 Triangles
	glBegin(GL_TRIANGLES);
	//Front face
	glColor4f(perc.r, perc.g, perc.b, perc.a);
	glVertex3f(position.x + (dimensions.x / 2), total.y, position.z + (dimensions.x / 2)); // Top Center point
	glVertex3f(position.x, position.y, position.z); // Bottom left
	glVertex3f(total.x, position.y, position.z); // Bottom right

	//Left face
	glColor4f(perc.r - 0.1f, perc.g - 0.1f, perc.b - 0.1f, perc.a);
	glVertex3f(position.x + (dimensions.x / 2), total.y, position.z + (dimensions.x / 2)); // Top Center point
	glVertex3f(position.x, position.y, position.z); // Bottom left
	glVertex3f(position.x, position.y, total.z); // Bottom right

	//right face
	glColor4f(perc.r - 0.2f, perc.g - 0.2f, perc.b - 0.2f, perc.a);
	glVertex3f(position.x + (dimensions.x / 2), total.y, position.z + (dimensions.x / 2)); // Top Center point
	glVertex3f(total.x, position.y, position.z); // Bottom left
	glVertex3f(total.x, position.y, total.z); // Bottom right

	//Back face
	glColor4f(perc.r - 0.3f, perc.g - 0.3f, perc.b - 0.3f, perc.a);
	glVertex3f(position.x + (dimensions.x / 2), total.y, position.z + (dimensions.x / 2)); // Top Center point
	glVertex3f(position.x, position.y, total.z); // Bottom left
	glVertex3f(total.x, position.y, total.z); // Bottom right
	glEnd();

	//Draw 1 Square
	glBegin(GL_QUADS);
	glColor4f(perc.r - 0.4f, perc.g - 0.4f, perc.b - 0.4f, perc.a);
	glVertex3f(position.x, position.y, position.z);
	glVertex3f(total.x, position.y, position.z);
	glVertex3f(total.x, position.y, total.z);
	glVertex3f(position.x, position.y, total.z);
	glEnd();
}
