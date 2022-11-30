#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Rect.h"

class View3d
{
public:
	View3d(const FloatRect _Rect = FloatRect());
	~View3d();

	void move(const Vec3f);
	void rotate(const Vec3f);
	void setPosition(const Vec3f);
	void setRotationAxis(const Vec3f);
	void setRotationSpeed(const float);

	Vec2f getSize() const;
	Vec2f getPosition() const;

	void setView();

private:
	float rotationSpeed;
	glm::vec3 rotationAxis;
	FloatRect bounds;
};

