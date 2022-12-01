#pragma once
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
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

};

