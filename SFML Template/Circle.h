#pragma once
#include "TwoD.h"

class Circle : TwoD
{
public:
	Circle(const float _Radius = 0.f, const Vec2f _Position = Vec2f());
	~Circle();

	void render() override;

private:
	void changeSize(const float _Radius);
};