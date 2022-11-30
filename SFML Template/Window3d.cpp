#include "Window3d.h"

Window3d::Window3d()
{
	initWindow();
	
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//
	//glFrustum(0.0f, window->getSize().x, window->getSize().y, 0.0f, 32.0f, 192.0f);
	//
	//
	//glMatrixMode(GL_MODELVIEW);
	//
	//glLoadIdentity();

	glEnable(GL_DEPTH_TEST);
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

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		glRotatef(1, 1, 0, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		glRotatef(-1, 1, 0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		glRotatef(1, 0, 1, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		glRotatef(-1, 0, 1, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		glRotatef(1, 0, 0, 1);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		glRotatef(-1, 0, 0, 1);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		glTranslatef(0, -.1, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		glTranslatef(0, .1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		glTranslatef(.1, 0, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		glTranslatef(-.1, 0, 0);

	float mult = 1;

	// White side - BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.5 * mult, -0.5 * mult, 0.5 * mult);
	glVertex3f(0.5 * mult, 0.5 * mult, 0.5 * mult);
	glVertex3f(-0.5 * mult, 0.5 * mult, 0.5 * mult);
	glVertex3f(-0.5 * mult, -0.5 * mult, 0.5 * mult);
	glEnd();

	// Yellow side - FRONT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 6.0, 0.0);
	glVertex3f(0.5* mult, -0.5 * mult, -0.5 * mult);
	glVertex3f(0.5* mult, 0.5 * mult, -0.5 * mult);
	glVertex3f(-0.5 * mult, 0.5 * mult, -0.5 * mult);
	glVertex3f(-0.5 * mult, -0.5 * mult, -0.5 * mult);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5 * mult, -0.5 * mult, -0.5 * mult);
	glVertex3f(0.5 * mult, 0.5 * mult, -0.5 * mult);
	glVertex3f(0.5 * mult, 0.5 * mult, 0.5 * mult);
	glVertex3f(0.5 * mult, -0.5 * mult, 0.5 * mult);
	glEnd();

	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5 * mult, -0.5 * mult, 0.5 * mult);
	glVertex3f(-0.5 * mult, 0.5 * mult, 0.5 * mult);
	glVertex3f(-0.5 * mult, 0.5 * mult, -0.5 * mult);
	glVertex3f(-0.5 * mult, -0.5 * mult, -0.5 * mult);
	glEnd();

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5 * mult, 0.5 * mult, 0.5 * mult);
	glVertex3f(0.5 * mult, 0.5 * mult, -0.5 * mult);
	glVertex3f(-0.5 * mult, 0.5 * mult, -0.5 * mult);
	glVertex3f(-0.5 * mult, 0.5 * mult, 0.5 * mult);
	glEnd();

	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5 * mult, -0.5 * mult, -0.5 * mult);
	glVertex3f(0.5 * mult, -0.5 * mult, 0.5 * mult);
	glVertex3f(-0.5 * mult, -0.5 * mult, 0.5 * mult);
	glVertex3f(-0.5 * mult, -0.5 * mult, -0.5 * mult);
	glEnd();

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
	window = new sf::Window(sf::VideoMode(500, 400), "Poly Lab", sf::Style::Default, sf::ContextSettings(24, 8, 0, 3, 3));
	window->setVerticalSyncEnabled(true);
	window->setFramerateLimit(60);
	window->setActive(true);
}
