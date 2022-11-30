#include "View2d.h"
#include <iostream>

View2d::View2d(const FloatRect rect)
{
	setSize(rect.size);
	setPosition(rect.position);
}

View2d::View2d()
{
	setSize(Vec2f());
	setPosition(Vec2f());
}

View2d::~View2d()
{
}

void View2d::setSize(const Vec2f _Size)
{
	size = _Size;
}

void View2d::setPosition(const Vec2f _Position)
{
	position = _Position;
}

void View2d::setView()
{
	glViewport(position.x, position.y, size.x, size.y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, size.x, size.y, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void View2d::move(const Vec2f _Vector)
{
	position += _Vector;
	setView();
}
