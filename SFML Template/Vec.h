#pragma once

template<typename T>
struct Vec3
{
	Vec3() { x = 0; y = 0; }
	Vec3(T _X, T _Y) { x = _X; y = _Y; }
	T x, y;
};

typedef Vec3<float> Vec3f;
typedef Vec3<double> Vec3d;
typedef Vec3<int> Vec3i;


template<typename T>
struct Vec2
{
	Vec2() { x = 0; y = 0; }
	Vec2(T _X, T _Y) { x = _X; y = _Y; }
	T x, y;
};

typedef Vec2<float> Vec2f;
typedef Vec2<double> Vec2d;
typedef Vec2<int> Vec2i;