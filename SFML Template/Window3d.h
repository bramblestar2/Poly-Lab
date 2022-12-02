#pragma once
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

	float centerX, centerY, centerZ;
	float camX, camY, camZ;

	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;

	float yaw, pitch;

	float lastX, lastY;
	bool firstMouse;

	glm::vec3 direction;
};

