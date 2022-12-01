#include "Window3d.h"
#include <iostream>

Window3d::Window3d()
{
	initWindow();

	glViewport(0.0f, 0.0f, window->getSize().x , window->getSize().y);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	glOrtho(-300, window->getSize().x, -300, window->getSize().y, -1000, 1000);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();

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

	const float radius = 10.f;
	float camX = sin((timeClock.getElapsedTime().asSeconds())) * radius;
	float camZ = cos((timeClock.getElapsedTime().asSeconds())) * radius;
	glm::mat4 view;

	view = glm::lookAt(glm::vec3(camX+100, 1, camZ+100),
			glm::vec3(100.0, 0.0, 100.0), glm::vec3(0.0, 1.0, 0.0));
	
	GLfloat matrix[16];
	
	const float* pSource = (const float*)glm::value_ptr(view);
	for (int i = 0; i < 16; ++i)
		matrix[i] = pSource[i];

	glLoadMatrixf(matrix);
	glScalef(0.7, 0.7, 0.7);
	//glMultMatrixf(matrix);

	float posX, posY, posZ;
	posX = -100;
	posY = -100;
	posZ = 100;

	// White side - BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(300 + posX, 100 + posY, 300 + posZ);
	glVertex3f(300 + posX, 300 + posY, 300 + posZ);
	glVertex3f(100 + posX, 300 + posY, 300 + posZ);
	glVertex3f(100 + posX, 100 + posY, 300 + posZ);
	glEnd();

	// Orange side - Front
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(300 + posX, 100 + posY, 100 + posZ);
	glVertex3f(300 + posX, 300 + posY, 100 + posZ);
	glVertex3f(100 + posX, 300 + posY, 100 + posZ);
	glVertex3f(100 + posX, 100 + posY, 100 + posZ);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(300 + posX, 100 + posY, 100 + posZ);
	glVertex3f(300 + posX, 300 + posY, 100 + posZ);
	glVertex3f(300 + posX, 300 + posY, 300 + posZ);
	glVertex3f(300 + posX, 100 + posY, 300 + posZ);
	glEnd();

	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(100 + posX, 100 + posY, 300 + posZ);
	glVertex3f(100 + posX, 300 + posY, 300 + posZ);
	glVertex3f(100 + posX, 300 + posY, 100 + posZ);
	glVertex3f(100 + posX, 100 + posY, 100 + posZ);
	glEnd();

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(300 + posX, 300 + posY, 300 + posZ);
	glVertex3f(300 + posX, 300 + posY, 100 + posZ);
	glVertex3f(100 + posX, 300 + posY, 100 + posZ);
	glVertex3f(100 + posX, 300 + posY, 300 + posZ);
	glEnd();

	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(300 + posX, 100 + posY, 100 + posZ);
	glVertex3f(300 + posX, 100 + posY, 300 + posZ);
	glVertex3f(100 + posX, 100 + posY, 300 + posZ);
	glVertex3f(100 + posX, 100 + posY, 100 + posZ);
	glEnd();

	window->display();
}


void Window3d::update()
{
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
		glTranslatef(0, -1, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		glTranslatef(0, 1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		glTranslatef(1, 0, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		glTranslatef(-1, 0, 0);
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
