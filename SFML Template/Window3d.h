#pragma once
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Rectangle3d.h"

class Window3d
{
public:
	Window3d();
	//Free memory
	virtual ~Window3d();

	void run();
	void render();
	void update();
	void updateDt();
	void updateSFMLEvents();
private:
	void initWindow();

	sf::Clock dtClock, timeClock;
	double dt;

	sf::Window* window;
	sf::Event event;

	float xPos, yPos, zPos;
	float xRot, yRot, zRot;

	glm::mat4 view;

	//Camera
	glm::vec3 cameraPos;
	glm::vec3 cameraTarget;
	glm::vec3 cameraDirection;

	glm::vec3 cameraFront;
	glm::vec3 cameraUp;

	float lastX, lastY, yaw, pitch;
	bool firstMouse;

	Rectangle3d rect[25];
};

