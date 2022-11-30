#pragma once
#include "TwoD.h"

class Triangle : public TwoD
{
public:
	Triangle(const Vec2f _Size = Vec2f(), const Vec2f _Position = Vec2f());
	~Triangle();

	void render() override;

};

