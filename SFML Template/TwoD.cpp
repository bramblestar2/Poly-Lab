#include "TwoD.h"
#include <iostream>
#include <stdexcept>

TwoD::TwoD(const int _VertexCount)
{
    vertexCount = _VertexCount;
    verticies = new Vertex[_VertexCount];
}


TwoD::~TwoD()
{
    if (verticies != nullptr)
        delete[] verticies;
}


void TwoD::setVertex(const int _It, const Vertex _Vertex)
{
    verticies[_It] = _Vertex;
}

void TwoD::setColor(const Color3f _Color)
{
    for (int i = 0; i < 4; i++)
        getVertex(i).color = _Color;
}

Vertex& TwoD::getVertex(const int _It) const
{
    if (_It > vertexCount)
        throw std::range_error("Error: index bigger than the number of vertexs");
    else if (_It < 0)
        throw std::range_error("Error: index is less than 0");
    else
        return verticies[_It];

    Vertex temp;
    return temp;
}

int TwoD::getVertexCount() const
{
    return vertexCount;
}