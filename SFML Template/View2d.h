#pragma once
#include <SFML/OpenGL.hpp>
#include "Rect.h"

class View2d
{
public:
	View2d(const FloatRect _Position_Size);
	View2d();
	~View2d();

	void setSize(const Vec2f _Size);
	void setPosition(const Vec2f _Position);
	void setView();
	void move(const Vec2f _Vector);

	FloatRect getBounds() const { return FloatRect(position, size); }

private:
	Vec2f position, size;
};

