#pragma once
#include <SFML/OpenGL.hpp>
#include <memory>
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
	void setPosition(const Vec2f _Position);

	Vertex& getVertex(const int _It) const;
	int getVertexCount() const;
	FloatRect getLocalBounds() const;
	FloatRect& getGlobalBounds();
private:
	int vertexCount;
	std::shared_ptr<Vertex[]> verticies;

	FloatRect globalBounds;
};

