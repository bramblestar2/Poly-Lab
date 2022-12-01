#include "ThreeD.h"

ThreeD::ThreeD(const int _Vertex_Count)
{
	verticies.reset(new Vertex3d[_Vertex_Count]);
	vertexCount = _Vertex_Count;
}

ThreeD::~ThreeD()
{
}

void ThreeD::setVertex(const int _It, const Vertex3d _Vertex)
{
	verticies[_It] = _Vertex;
}

void ThreeD::setColor(const Color3f _Color)
{
	for (int i = 0; i < vertexCount; i++)
	{
		verticies[i].color = _Color;
	}
}

void ThreeD::setPosition(const Vec3f _Position)
{
	position = _Position;
}

Vertex3d& ThreeD::getVertex(const int _It) const
{
	return verticies[_It];
}

int ThreeD::getVertexCount() const
{
	return vertexCount;
}

Vec3f ThreeD::getDimensions() const
{
	return dimensions;
}

Vec3f& ThreeD::getPosition()
{
	return position;
}

void ThreeD::setDimensions(const Vec3f _Dimensions)
{
	dimensions = _Dimensions;
}
