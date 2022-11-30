#pragma once
//#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "../View2d.h"
#include "../Circle.h"

class Window
{
public:
	Window();
	//Free memory
	virtual ~Window();

	void run();
	void render();
	void update();
	void updateDt();
	void updateSFMLEvents();
private:
	void initWindow();

	sf::Clock dtClock;
	double dt;

	sf::Window* window;
	sf::Event event;

	View2d v1;

	Circle c;
};

