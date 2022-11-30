#pragma once
#include "Vec.h"

template <typename T>
struct Rect
{
	Rect(const Vec2<T> _Position = Vec2<T>(), const Vec2<T> _Size = Vec2<T>());

	bool contains(const Vec2<T> _Point);
	bool intersects(const Rect<T> _Rect);

	T right();
	T bottom();
	Vec2<T> position, size;
};

typedef Rect<float> FloatRect;
typedef Rect<int> IntRect;
typedef Rect<double> DoubleRect;

