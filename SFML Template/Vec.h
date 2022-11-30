#pragma once

template<typename T>
struct Vec3
{
	Vec3(T _X = 0, T _Y = 0, T _Z = 0) { x = _X; y = _Y; z = _Z; }
	T x, y, z;
};

typedef Vec3<float> Vec3f;
typedef Vec3<double> Vec3d;
typedef Vec3<int> Vec3i;


template<typename T>
struct Vec2
{
	Vec2(T _X = 0, T _Y = 0) { x = _X; y = _Y; }
	T x, y;

	Vec2<T>& operator+=(const Vec2<T>& right)
	{
		this->x += right.x;
		this->y += right.y;
		return *this;
	}
};

typedef Vec2<float> Vec2f;
typedef Vec2<double> Vec2d;
typedef Vec2<int> Vec2i;