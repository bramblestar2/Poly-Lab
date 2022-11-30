#pragma once
#include <SFML/OpenGL.hpp>
#include "Shape.h"
#include "Color.h"
#include "Rect.h"

struct Vertex
{
	Vertex(const Vec2f _Position, const Color3f _Color)
	{
		position = _Position;
		color = _Color;
	}
	Vertex(const Vec2f _Position) 
	{
		position = _Position;
		color = Color3f();
	}
	Vertex()
	{
		position = Vec2f();
		color = Color3f();
	}

	Vec2f position;
	Color3f color;
};

class TwoD : public Shape
{
public:
	TwoD(const int _VertexCount);
	~TwoD();

	void setVertex(const int _It, const Vertex _Vertex);

	Vertex getVertex(const int _It) const;
	int getVertexCount() const;

	//void render() override;
private:
	int vertexCount;
	Vertex* vertexs;
};

