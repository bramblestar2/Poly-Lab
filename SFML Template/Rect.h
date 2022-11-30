#pragma once
#include "Vec.h"

template <typename T>
struct Rect
{
	Rect(const Vec2<T> _Position = Vec2<T>(), const Vec2<T> _Size = Vec2<T>())
	{
		position = _Position;
		size = _Size;
	}

	bool contains(const Vec2<T> _Point) { return false; }
	bool intersects(const Rect<T> _Rect) { return false; }

	T left() const { return (T)(position.x); }
	T right() const { return (T)(position.x + size.x); }
	T top() const { return (T)(position.y); }
	T bottom() const { return (T)(position.y + size.y); }
	Vec2<T> center() const { return Vec2<T>(left() + (size.x / 2), top() + (size.y/2)); }

	Vec2<T> position, size;
};

typedef Rect<float> FloatRect;
typedef Rect<int> IntRect;
typedef Rect<double> DoubleRect;

