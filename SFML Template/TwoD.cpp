#include "TwoD.h"
#include <iostream>
#include <stdexcept>

TwoD::TwoD(const int _VertexCount)
{
    vertexCount = _VertexCount;

    verticies.reset(new Vertex[_VertexCount]);
}


TwoD::~TwoD()
{
}


void TwoD::setVertex(const int _It, const Vertex _Vertex)
{
    *(verticies.get() + _It) = _Vertex;
}

void TwoD::setColor(const Color3f _Color)
{
    for (int i = 0; i < vertexCount; i++)
        getVertex(i).color = _Color;
}

void TwoD::setPosition(const Vec2f _Position)
{
    globalBounds.position = _Position;
}

Vertex& TwoD::getVertex(const int _It) const
{
    if (_It > vertexCount)
        throw std::range_error("Error: index bigger than the number of vertexs");
    else if (_It < 0)
        throw std::range_error("Error: index is less than 0");
    else
        return *(verticies.get() + _It);

    Vertex temp;
    return temp;
}

int TwoD::getVertexCount() const
{
    return vertexCount;
}

FloatRect TwoD::getLocalBounds() const
{
    return FloatRect(Vec2f(0, 0), globalBounds.size);
}

FloatRect& TwoD::getGlobalBounds()
{
    return globalBounds;
}