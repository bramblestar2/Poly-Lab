#pragma once
#include <memory>
#include "Shape.h"
#include "Vec.h"
#include "Vertex.h"

class ThreeD : public Shape
{
public:
	ThreeD(const int _Vertex_Count);
	~ThreeD();

	void setVertex(const int _It, const Vertex3d _Vertex);
	virtual void setColor(const Color3f _Color);
	void setPosition(const Vec3f _Position);

	Vertex3d& getVertex(const int _It) const;
	int getVertexCount() const;
	Vec3f getDimensions() const;
	Vec3f& getPosition();

protected:
	void setDimensions(const Vec3f _Dimensions);

private:
	std::shared_ptr<Vertex3d[]> verticies;
	int vertexCount;

	Vec3f dimensions;
	Vec3f position;
};

