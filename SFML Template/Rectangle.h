#pragma once
#include "TwoD.h"
#include "Color.h"

class RectangleGL : public TwoD
{
public:
	RectangleGL(const FloatRect _Rect = FloatRect());
	~RectangleGL();

	void render() override;

	virtual void setSize(const Vec2f _Size);
	
private:
};

