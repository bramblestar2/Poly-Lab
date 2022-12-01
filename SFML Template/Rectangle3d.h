#pragma once
#include "Triangle3d.h"

class Rectangle3d : public ThreeD
{
public:
	Rectangle3d(const Vec3f _Dimensions = Vec3f(), const Vec3f _Position = Vec3f());
	~Rectangle3d();

	void render();

	void setSize(const Vec3f _Dimensions);
	void setPosition(const Vec3f _Position);
	int getTriangleCount() const;
	Triangle3d& getTriangle(const int _It) const;

private:
	std::shared_ptr<Triangle3d[]> triangles;
	int triangleCount;
};