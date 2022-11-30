#pragma once
#include "TwoD.h"
#include "Color.h"

class RectangleGL : public TwoD
{
public:
	RectangleGL(const Vec2f _Size);
	RectangleGL();
	~RectangleGL();

	void render() override;


private:
};

