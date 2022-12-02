#include "Window3d.h"
#include <iostream>

Window3d::Window3d()
{
	initWindow();

	glViewport(0.0f, 0.0f, window->getSize().x , window->getSize().y);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	glOrtho(0, window->getSize().x, 0, window->getSize().y, -1000, 1000);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();


	cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);


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


	view = glm::lookAt(glm::vec3(camX*10, 0, camZ * 10),
			glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
	
	//view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
	//	glm::vec3(0.0f, 0.0f, 0.0f),
	//	glm::vec3(0.0f, 1.0f, 0.0f));
	//cameraFront.x = 1;
	//view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	//std::cout << cameraPos.x << " - " << cameraPos.y << " - " << cameraPos.z << std::endl;
	GLfloat matrix[16];
	
	const float* pSource = (const float*)glm::value_ptr(view);
	for (int i = 0; i < 16; ++i)
	{
		matrix[i] = pSource[i];
		std::cout << pSource[i] << " - ";
	}
	std::cout << std::endl;

	glLoadMatrixf(matrix);
	//glMultMatrixf(matrix);

	float posX, posY, posZ;
	posX = 0;
	posY = 0;
	posZ = 0;

	// White side - BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(200 + posX, 0 + posY, 200 + posZ);
	glVertex3f(200 + posX, 200 + posY, 200 + posZ);
	glVertex3f(0 + posX, 200 + posY, 200 + posZ);
	glVertex3f(0 + posX, 0 + posY, 200 + posZ);
	glEnd();

	// Orange side - Front
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(200 + posX, 0 + posY, 0 + posZ);
	glVertex3f(200 + posX, 200 + posY, 0 + posZ);
	glVertex3f(0 + posX, 200 + posY, 0 + posZ);
	glVertex3f(0 + posX, 0 + posY, 0 + posZ);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(200 + posX, 0 + posY, 0 + posZ);
	glVertex3f(200 + posX, 200 + posY, 0 + posZ);
	glVertex3f(200 + posX, 200 + posY, 200 + posZ);
	glVertex3f(200 + posX, 0 + posY, 200 + posZ);
	glEnd();

	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0 + posX, 0 + posY, 200 + posZ);
	glVertex3f(0 + posX, 200 + posY, 200 + posZ);
	glVertex3f(0 + posX, 200 + posY, 0 + posZ);
	glVertex3f(0 + posX, 0 + posY, 0 + posZ);
	glEnd();

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(200 + posX, 200 + posY, 200 + posZ);
	glVertex3f(200 + posX, 200 + posY, 0 + posZ);
	glVertex3f(0 + posX, 200 + posY, 0 + posZ);
	glVertex3f(0 + posX, 200 + posY, 200 + posZ);
	glEnd();

	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(200 + posX, 0 + posY, 0 + posZ);
	glVertex3f(200 + posX, 0 + posY, 200 + posZ);
	glVertex3f(0 + posX, 0 + posY, 200 + posZ);
	glVertex3f(0 + posX, 0 + posY, 0 + posZ);
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

	const float cameraSpeed = 2.5f * (dt*100);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		cameraPos += cameraSpeed * cameraFront;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		cameraPos -= cameraSpeed * cameraFront;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
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
