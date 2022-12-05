#include "Rectangle3d.h"
#include <iostream>

Rectangle3d::Rectangle3d(const Vec3f _Dimensions, const Vec3f _Position)
{
	vertices = nullptr;

	setSize(_Dimensions);
	setPosition(_Position);
}

Rectangle3d::~Rectangle3d()
{
}

Vec3f Rectangle3d::getSize() const
{
	return dimensions;
}

Vec3f Rectangle3d::getPosition() const
{
	return position;
}

void Rectangle3d::setColor(const float _R, const float _G, const float _B, const float _A)
{
	setColor(Color4f(_R, _G, _B, _A));
}

void Rectangle3d::setColor(const Color4f _Color)
{
	color = _Color;

	updateVertices();
}

void Rectangle3d::setPosition(const float _X, const float _Y, const float _Z)
{
	setPosition(Vec3f(_X, _Y, _Z));
}

void Rectangle3d::setPosition(const Vec3f _Position)
{
	position = _Position;

	updateVertices();
}

void Rectangle3d::setSize(const float _X, const float _Y, const float _Z)
{
	setSize(Vec3f(_X, _Y, _Z));
}

void Rectangle3d::setSize(const Vec3f _Dimensions)
{
	dimensions = _Dimensions;

	updateVertices();
}

void Rectangle3d::render()
{
	Vec3f total;
	total.x = position.x + dimensions.x;
	total.y = position.y + dimensions.y;
	total.z = position.z + dimensions.z;

	Color4f rectColor = color.toPercentage();

	glBegin(GL_TRIANGLES);
	glColor4f(rectColor.r, rectColor.g, rectColor.b, rectColor.a);
	//Face 1
	glVertex3f(position.x, position.y, position.z);
	glVertex3f(position.x, total.y, position.z);
	glVertex3f(position.x, position.y, total.z);
	glVertex3f(position.x, position.y, total.z);
	glVertex3f(position.x, total.y, position.z);
	glVertex3f(position.x, total.y, total.z);

	glColor4f(rectColor.r - 0.1f, rectColor.g - 0.1f, rectColor.b - 0.1f, rectColor.a);
	//Face 2
	glVertex3f(total.x, position.y, position.z); 
	glVertex3f(total.x, total.y, position.z);	 
	glVertex3f(total.x, position.y, total.z);	 
	glVertex3f(total.x, position.y, total.z); 
	glVertex3f(total.x, total.y, position.z); 
	glVertex3f(total.x, total.y, total.z);
	
	glColor4f(rectColor.r - 0.2f, rectColor.g - 0.2f, rectColor.b - 0.2f, rectColor.a);
	//Face 3
	glVertex3f(position.x, position.y, position.z);
	glVertex3f(total.x, position.y, position.z);
	glVertex3f(position.x, position.y, total.z);
	glVertex3f(position.x, position.y, total.z); 
	glVertex3f(total.x, position.y, position.z);
	glVertex3f(total.x, position.y, total.z);
	
	glColor4f(rectColor.r - 0.3f, rectColor.g - 0.3f, rectColor.b - 0.3f, rectColor.a);
	//Face 4
	glVertex3f(position.x, total.y, position.z); 
	glVertex3f(total.x, total.y, position.z);	 
	glVertex3f(position.x, total.y, total.z);	 
	glVertex3f(position.x, total.y, total.z);	 
	glVertex3f(total.x, total.y, position.z);	 
	glVertex3f(total.x, total.y, total.z);
	
	glColor4f(rectColor.r - 0.4f, rectColor.g - 0.4f, rectColor.b - 0.4f, rectColor.a);
	//Face 5
	glVertex3f(position.x, position.y, position.z);
	glVertex3f(total.x, position.y, position.z); 
	glVertex3f(position.x, total.y, position.z); 
	glVertex3f(position.x, total.y, position.z); 
	glVertex3f(total.x, position.y, position.z); 
	glVertex3f(total.x, total.y, position.z);
	
	glColor4f(rectColor.r - 0.5f, rectColor.g - 0.5f, rectColor.b - 0.5f, rectColor.a);
	//Face 6
	glVertex3f(position.x, position.y, total.z);
	glVertex3f(total.x, position.y, total.z);	 
	glVertex3f(position.x, total.y, total.z);	 
	glVertex3f(position.x, total.y, total.z);	 
	glVertex3f(total.x, position.y, total.z);	 
	glVertex3f(total.x, total.y, total.z);

	glEnd();

	//glDrawArrays(GL_TRIANGLES, 0, 36);
}

//This is completely useless now since i gave up trying to use
//an array to draw stuff
void Rectangle3d::updateVertices()
{
	

	/*
	Vec3f total;
	total.x = position.x + dimensions.x;
	total.y = position.y + dimensions.y;
	total.z = position.z + dimensions.z;

	Color4f rectColor = color.toPercentage();

	//Each face has 3 triangles
	//6 rows, 7 columns, 6 faces
	vertices.reset(new GLfloat[6 * 7 * 6]
	{
		//Positions							Colors
		//Face 1
		position.x, position.y, position.z, rectColor.r, rectColor.g, rectColor.b, rectColor.a,
		position.x, total.y, position.z,	rectColor.r, rectColor.g, rectColor.b, rectColor.a,
		position.x, position.y, total.z,	rectColor.r, rectColor.g, rectColor.b, rectColor.a,
		position.x, position.y, total.z,	rectColor.r, rectColor.g, rectColor.b, rectColor.a,
		position.x, total.y, position.z,	rectColor.r, rectColor.g, rectColor.b, rectColor.a,
		position.x, total.y, total.z,		rectColor.r, rectColor.g, rectColor.b, rectColor.a,

		//Face 2
		total.x, position.y, position.z, rectColor.r - 0.1f, rectColor.g - 0.1f, rectColor.b - 0.1f, rectColor.a,
		total.x, total.y, position.z,	 rectColor.r - 0.1f, rectColor.g - 0.1f, rectColor.b - 0.1f, rectColor.a,
		total.x, position.y, total.z,	 rectColor.r - 0.1f, rectColor.g - 0.1f, rectColor.b - 0.1f, rectColor.a,
		total.x, position.y, total.z,	 rectColor.r - 0.1f, rectColor.g - 0.1f, rectColor.b - 0.1f, rectColor.a,
		total.x, total.y, position.z,	 rectColor.r - 0.1f, rectColor.g - 0.1f, rectColor.b - 0.1f, rectColor.a,
		total.x, total.y, total.z,		 rectColor.r - 0.1f, rectColor.g - 0.1f, rectColor.b - 0.1f, rectColor.a,

		//Face 3
		position.x, position.y, position.z, rectColor.r - 0.2f, rectColor.g - 0.2f, rectColor.b - 0.2f, rectColor.a,
		total.x, position.y, position.z,    rectColor.r - 0.2f, rectColor.g - 0.2f, rectColor.b - 0.2f, rectColor.a,
		position.x, position.y, total.z,    rectColor.r - 0.2f, rectColor.g - 0.2f, rectColor.b - 0.2f, rectColor.a,
		position.x, position.y, total.z,    rectColor.r - 0.2f, rectColor.g - 0.2f, rectColor.b - 0.2f, rectColor.a,
		total.x, position.y, position.z,    rectColor.r - 0.2f, rectColor.g - 0.2f, rectColor.b - 0.2f, rectColor.a,
		total.x, position.y, total.z,	    rectColor.r - 0.2f, rectColor.g - 0.2f, rectColor.b - 0.2f, rectColor.a,

		//Face 4
		position.x, total.y, position.z, rectColor.r - 0.3f, rectColor.g - 0.3f, rectColor.b - 0.3f, rectColor.a,
		total.x, total.y, position.z,	 rectColor.r - 0.3f, rectColor.g - 0.3f, rectColor.b - 0.3f, rectColor.a,
		position.x, total.y, total.z,	 rectColor.r - 0.3f, rectColor.g - 0.3f, rectColor.b - 0.3f, rectColor.a,
		position.x, total.y, total.z,	 rectColor.r - 0.3f, rectColor.g - 0.3f, rectColor.b - 0.3f, rectColor.a,
		total.x, total.y, position.z,	 rectColor.r - 0.3f, rectColor.g - 0.3f, rectColor.b - 0.3f, rectColor.a,
		total.x, total.y, total.z,		 rectColor.r - 0.3f, rectColor.g - 0.3f, rectColor.b - 0.3f, rectColor.a,

		//Face 5
		position.x, position.y, position.z, rectColor.r - 0.4f, rectColor.g - 0.4f, rectColor.b - 0.4f, rectColor.a,
		total.x, position.y, position.z,    rectColor.r - 0.4f, rectColor.g - 0.4f, rectColor.b - 0.4f, rectColor.a,
		position.x, total.y, position.z,    rectColor.r - 0.4f, rectColor.g - 0.4f, rectColor.b - 0.4f, rectColor.a,
		position.x, total.y, position.z,    rectColor.r - 0.4f, rectColor.g - 0.4f, rectColor.b - 0.4f, rectColor.a,
		total.x, position.y, position.z,    rectColor.r - 0.4f, rectColor.g - 0.4f, rectColor.b - 0.4f, rectColor.a,
		total.x, total.y, position.z,	    rectColor.r - 0.4f, rectColor.g - 0.4f, rectColor.b - 0.4f, rectColor.a,

		//Face 6
		position.x, position.y, total.z, rectColor.r - 0.5f, rectColor.g - 0.5f, rectColor.b - 0.5f, rectColor.a,
		total.x, position.y, total.z,	 rectColor.r - 0.5f, rectColor.g - 0.5f, rectColor.b - 0.5f, rectColor.a,
		position.x, total.y, total.z,	 rectColor.r - 0.5f, rectColor.g - 0.5f, rectColor.b - 0.5f, rectColor.a,
		position.x, total.y, total.z,	 rectColor.r - 0.5f, rectColor.g - 0.5f, rectColor.b - 0.5f, rectColor.a,
		total.x, position.y, total.z,	 rectColor.r - 0.5f, rectColor.g - 0.5f, rectColor.b - 0.5f, rectColor.a,
		total.x, total.y, total.z,		 rectColor.r - 0.5f, rectColor.g - 0.5f, rectColor.b - 0.5f, rectColor.a,
	});

	// Enable position and color vertex components
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 7 * sizeof(GLfloat), vertices.get());
	glColorPointer(4, GL_FLOAT, 7 * sizeof(GLfloat), vertices.get() + 3);

	// Disable normal and texture coordinates vertex components
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	*/
}
