#pragma once
#include "Vec.h"

template <typename T>
struct Rect
{
	Rect(const Vec2<T> _Position, const Vec2<T> _Size);
	Rect();

	bool contains(const Vec2<T> _Point);
	bool intersects(const Rect<T> _Rect);

	Vec2<T> position, size;
};

typedef Rect<float> FloatRect;
typedef Rect<int> IntRect;
typedef Rect<double> DoubleRect;

