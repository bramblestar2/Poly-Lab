#pragma once
#include "Shape.h"

class TwoD : public Shape
{
public:
	TwoD(const int pointCount);
	~TwoD();

	void setPoint(const int _Point, const Vec2f _Position);
	void getPoints() const;

	void render() override;

	Vec2f& operator[](const int right);
private:
	int pointCount;
	Vec2f* points;


};

