#include "View3d.h"

View3d::View3d(const FloatRect _Rect)
{
}

View3d::~View3d()
{
}

void View3d::move(const Vec3f)
{
}

void View3d::rotate(const Vec3f)
{
}

void View3d::setPosition(const Vec3f)
{
}

void View3d::setRotationAxis(const Vec3f _Axis)
{
    rotationAxis.x = _Axis.x;
    rotationAxis.y = _Axis.y;
    rotationAxis.z = _Axis.z;
}

void View3d::setRotationSpeed(const float _Speed)
{
    rotationSpeed = _Speed;
}

Vec2f View3d::getSize() const
{
    return bounds.size;
}

Vec2f View3d::getPosition() const
{
    return bounds.position;
}

void View3d::setView()
{
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 proj = glm::mat4(1.0f);

    view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
    proj = glm::perspective(glm::radians(45.0f), (float)(bounds.size.x / bounds.size.y), 0.1f, 100.f);
}
