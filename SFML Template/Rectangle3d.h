#pragma once
#include "Shape.h"
#include "Color.h"
#include <memory>
#include <SFML/OpenGL.hpp>

class Rectangle3d : public Shape
{
public:
	Rectangle3d(const Vec3f _Dimensions = Vec3f(), const Vec3f _Position = Vec3f());
	~Rectangle3d();

	Vec3f getSize() const;
	Vec3f getPosition() const;

	void setColor(const float _R, const float _G, const float _B, const float _A);
	void setColor(const Color4f _Color);
	void setPosition(const float _X, const float _Y, const float _Z);
	void setPosition(const Vec3f _Position);
	void setSize(const float _X, const float _Y, const float _Z);
	void setSize(const Vec3f _Dimensions);

	void render() override;
private:
	void updateVertices();

	std::unique_ptr<GLfloat[]> vertices;
	//GLfloat* vertices;

	Vec3f dimensions;
	Vec3f position;
	Vec3f rotation;
	Color4f color;
};