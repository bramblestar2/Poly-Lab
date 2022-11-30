#include "TwoD.h"
#include <iostream>
#include <stdexcept>

TwoD::TwoD(const int _VertexCount)
{
    vertexCount = _VertexCount;
    //verticies.reset(new Vertex[_VertexCount]);
    verticies = new Vertex[_VertexCount];
}


TwoD::~TwoD()
{
    //An error happens here
    //if (verticies != nullptr)
    //    delete[] verticies;
}


void TwoD::setVertex(const int _It, const Vertex _Vertex)
{
    *(verticies+_It) = _Vertex;
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
        return *(verticies + _It);

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

//TwoD& TwoD::operator=(const TwoD& right)
//{
//    vertexCount = right.vertexCount;
//    //verticies.reset(new Vertex[right.vertexCount]);
//
//    globalBounds = FloatRect();
//    return *this;
//}
