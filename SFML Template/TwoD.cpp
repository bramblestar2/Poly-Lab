#include "TwoD.h"
#include <iostream>
#include <stdexcept>

TwoD::TwoD(const int _VertexCount)
{
    vertexCount = _VertexCount;
    vertexs = new Vertex[_VertexCount];
}


TwoD::~TwoD()
{
    if (vertexs != nullptr)
        delete[] vertexs;
}


void TwoD::setVertex(const int _It, const Vertex _Vertex)
{
    vertexs[_It] = _Vertex;
}


Vertex TwoD::getVertex(const int _It) const
{
    if (_It > vertexCount)
        throw std::range_error("Error: index bigger than the number of vertexs");
    else
        return vertexs[_It];

    return Vertex();
}

int TwoD::getVertexCount() const
{
    return vertexCount;
}