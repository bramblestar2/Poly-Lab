#pragma once
#include <SFML/OpenGL.hpp>
#include "Shape.h"
#include "Color.h"
#include "Rect.h"
#include "Vertex.h"

class TwoD : public Shape
{
public:
	TwoD(const int _VertexCount);
	~TwoD();

	void setVertex(const int _It, const Vertex _Vertex);
	void setColor(const Color3f _Color);

	Vertex& getVertex(const int _It) const;
	int getVertexCount() const;

	//void render() override;
private:
	int vertexCount;
	Vertex* verticies;
};

