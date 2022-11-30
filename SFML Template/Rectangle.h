#pragma once
#include "TwoD.h"
#include "Color.h"

class RectangleGL : public TwoD
{
public:
	RectangleGL(const FloatRect _Size = FloatRect());
	~RectangleGL();

	void render() override;

private:
};

