#pragma once
#include "ThreeD.h"

class Cube : public ThreeD
{
public:
	Cube(const Vec3f _Dimensions = Vec3f(), const Vec3f _Position = Vec3f());
	~Cube();

	void render() override;

private:
	void changeSize();
};

