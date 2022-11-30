#include "Window.h"
#include "../Rectangle.h"

Window::Window()
{
	initWindow();
	
	//glOrtho(0, window->getSize().x, window->getSize().y, 0, -1, 1);

	//v1 = View(FloatRect(Vec2f(0, 0), Vec2f(window->getSize().x, window->getSize().y)));
	v1.setSize(Vec2f(window->getSize().x, window->getSize().y));
	v1.setPosition(Vec2f(0,0));

	v1.setView();
}


Window::~Window()
{
	delete window;
}


void Window::run()
{
	while (window->isOpen())
	{
		update();
		updateDt();
		updateSFMLEvents();
		render();
	}
}


void Window::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	RectangleGL a(FloatRect(Vec2f(0, 0), Vec2f(100,100)));
	//a.render();

	window->display();
}


void Window::update()
{
}


void Window::updateDt()
{
	dt = dtClock.restart().asSeconds();
}


void Window::updateSFMLEvents()
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
			v1.setView();
		}
	}
}


void Window::initWindow()
{
	window = new sf::Window(sf::VideoMode(500, 400), "Poly Lab", sf::Style::Default, sf::ContextSettings());
	window->setVerticalSyncEnabled(true);
	window->setFramerateLimit(60);
	window->setActive(true);
}
