#include "Window.h"

Window::Window()
{
	initWindow();
	
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

	for (int i = 0; i < 20; i++)
	{
		triangles[i].render();
		circles[i].render();
		rectangles[i].render();
		squares[i].render();
	}

	window->display();
}


void Window::update()
{
	randCircles();
	randTriangles();
	randSquares();
	randRectangles();
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

void Window::randTriangles()
{
	if (tClock.getElapsedTime() > sf::seconds(3))
	{
		for (int i = 0; i < 20; i++)
		{
			triangles[i] = Triangle(Vec2f(rand() % 100 + 5, rand() % 100 + 5));
			triangles[i].setPosition(Vec2f(rand() % window->getSize().x, rand() % window->getSize().y));
			triangles[i].setColor(Color3f(rand() % 255, rand() % 255, rand() % 255));
		}

		tClock.restart();
	}
}

void Window::randCircles()
{
	if (cClock.getElapsedTime() > sf::seconds(2))
	{
		for (int i = 0; i < 20; i++)
		{
			circles[i] = Circle(rand()%90 + 10);
			circles[i].setPosition(Vec2f(rand() % window->getSize().x, rand() % window->getSize().y));
			circles[i].setColor(Color3f(rand()%255, rand() % 255, rand() % 255));
		}

		cClock.restart();
	}
}

void Window::randRectangles()
{
	if (rClock.getElapsedTime() > sf::seconds(1))
	{
		for (int i = 0; i < 20; i++)
		{
			rectangles[i] = RectangleGL(FloatRect(Vec2f(), Vec2f(rand() % 100 + 5, rand() % 100 + 5)));
			rectangles[i].setPosition(Vec2f(rand() % window->getSize().x, rand() % window->getSize().y));
			rectangles[i].setColor(Color3f(rand() % 255, rand() % 255, rand() % 255));
		}

		rClock.restart();
	}
}

void Window::randSquares()
{
	if (sClock.getElapsedTime() > sf::seconds(0.5))
	{
		for (int i = 0; i < 20; i++)
		{
			squares[i] = Square(rand()%90+10);
			squares[i].setPosition(Vec2f(rand() % window->getSize().x, rand() % window->getSize().y));
			squares[i].setColor(Color3f(rand() % 255, rand() % 255, rand() % 255));
		}

		sClock.restart();
	}
}
