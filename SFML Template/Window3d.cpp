#include "Window3d.h"

Window3d::Window3d()
{
	initWindow();

}


Window3d::~Window3d()
{
	delete window;
}


void Window3d::run()
{
	while (window->isOpen())
	{
		update();
		updateDt();
		updateSFMLEvents();
		render();
	}
}


void Window3d::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	window->display();
}


void Window3d::update()
{
}


void Window3d::updateDt()
{
	dt = dtClock.restart().asSeconds();
}


void Window3d::updateSFMLEvents()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
		}

		if (event.type == sf::Event::Resized)
		{
			//v1.setView();
		}
	}
}


void Window3d::initWindow()
{
	window = new sf::Window(sf::VideoMode(500, 400), "Poly Lab", sf::Style::Default, sf::ContextSettings());
	window->setVerticalSyncEnabled(true);
	window->setFramerateLimit(60);
	window->setActive(true);
}
