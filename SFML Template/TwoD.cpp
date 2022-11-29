#include "TwoD.h"
#include <iostream>
#include <stdexcept>

TwoD::TwoD(const int _Point_Count)
{
    pointCount = _Point_Count;
    points = new Vec2f[pointCount];
}

TwoD::~TwoD()
{
    if (points != nullptr)
        delete[] points;
}

void TwoD::setPoint(const int _Point, const Vec2f _Position)
{

}

void TwoD::getPoints() const
{
}

void TwoD::render()
{
}

Vec2f& TwoD::operator[](const int right)
{
    if (right > pointCount)
        throw std::range_error("Error: index bigger than the number of points");
    else
    {
        return points[right];
    }

   
    Vec2f temp;
    return temp;
}