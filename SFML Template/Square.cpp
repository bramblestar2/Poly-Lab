#include "Square.h"


Square::Square(const float _Size, const Vec2f _Position)
	: RectangleGL(FloatRect(Vec2f(_Position), Vec2f(_Size, _Size)))
{
}

Square::~Square()
{
}
