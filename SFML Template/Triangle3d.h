#pragma once
#include "ThreeD.h"

class Triangle3d : public ThreeD
{
public:
	Triangle3d(const Vec3f _PointOne = Vec3f(),
			   const Vec3f _PointTwo = Vec3f(),
			   const Vec3f _PointThree = Vec3f());
	~Triangle3d();

	void render() override;
};

