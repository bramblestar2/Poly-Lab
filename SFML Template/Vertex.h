#pragma once
#include "Color.h"
#include "Vec.h"

struct Vertex3d
{
	Vertex3d(const Vec3f _Position = Vec3f(), const Color3f _Color = Color3f(255,255,255));

	Vec3f position;
	Color3f color;
	
	Color3f toPercentage();

private:
	void init(const Vec3f _Position = Vec3f(), const Color3f _Color = Color3f(255, 255, 255));
};

struct Vertex
{
	Vertex(const Vec2f _Position = Vec2f(), const Color3f _Color = Color3f(255,255,255));

	Vec2f position;
	Color3f color;

	Color3f toPercentage();

private:
	void init(const Vec2f _Position = Vec2f(), const Color3f _Color = Color3f(255,255,255));
};