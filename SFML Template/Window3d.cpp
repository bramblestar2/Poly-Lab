#include "Window3d.h"
#include <iostream>

Window3d::Window3d()
{
	initWindow();


	glClearDepth(1.f);
	glClearColor(0, 0, 0, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glViewport(0.0f, 0.0f, window->getSize().x , window->getSize().y);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	float ratio = (float)window->getSize().x / (float)window->getSize().y;
	glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

	xPos = 0;
	yPos = 0;
	zPos = 0;
	yaw = 0;
	pitch = 0;
	firstMouse = true;

	view = glm::mat4(1.f);

	cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	cameraDirection = glm::normalize(cameraPos - cameraTarget);

	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
}


Window3d::~Window3d()
{
	delete window;
}


void Window3d::run()
{
	while (window->isOpen())
	{
		if (window->hasFocus())
			update();
		updateDt();
		updateSFMLEvents();
		render();
	}
}


void Window3d::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	const float radius = 200.0f;
	float camX = sin(timeClock.getElapsedTime().asSeconds()) * radius;
	float camZ = cos(timeClock.getElapsedTime().asSeconds()) * radius;

	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMultMatrixf(glm::value_ptr(view));
	//glTranslatef(0 + xPos, 0 + yPos, -200.f + zPos);
	//glRotatef(timeClock.getElapsedTime().asSeconds() * 90, 0, 0.5, 1);
	//glRotatef(xRot, 1, 0, 0);
	//glRotatef(yRot, 0, 1, 0);
	//glRotatef(zRot, 0, 0, 1);


	float width = 10;
	float height = 10;
	float length = 10;

	float x = 100;
	float y = 0;
	float z = 0;

	float rX = width + x;
	float rY = height + y;
	float rZ = length + z;

	glBegin(GL_TRIANGLES);
	glColor4f(0, 0, 1, 1);
	glVertex3f(x, y, z);
	glVertex3f(x, rY, z);
	glVertex3f(x, y, rZ);
	glVertex3f(x, y, rZ);
	glVertex3f(x, rY, z);
	glVertex3f(x, rY, rZ);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor4f(0, 1, 0, 1);
	glVertex3f(rX, y, z);
	glVertex3f(rX, rY, z);
	glVertex3f(rX, y, rZ);
	glVertex3f(rX, y, rZ);
	glVertex3f(rX, rY, z);
	glVertex3f(rX, rY, rZ);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor4f(1, 0, 0, 1);
	glVertex3f(x, y, z);
	glVertex3f(rX, y, z);
	glVertex3f(x, y, rZ);
	glVertex3f(x, y, rZ);
	glVertex3f(rX, y, z);
	glVertex3f(rX, y, rZ);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor4f(0, 1, 1, 1);
	glVertex3f(x, rY, z);
	glVertex3f(rX, rY, z);
	glVertex3f(x, rY, rZ);
	glVertex3f(x, rY, rZ);
	glVertex3f(rX, rY, z);
	glVertex3f(rX, rY, rZ);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor4f(1, 0, 1, 1);
	glVertex3f(x, y, z);
	glVertex3f(rX, y, z);
	glVertex3f(x, rY, z);
	glVertex3f(x, rY, z);
	glVertex3f(rX, y, z);
	glVertex3f(rX, rY, z);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor4f(1, 1, 0, 1);
	glVertex3f(x, y, rZ);
	glVertex3f(rX, y, rZ);
	glVertex3f(x, rY, rZ);
	glVertex3f(x, rY, rZ);
	glVertex3f(rX, y, rZ);
	glVertex3f(rX, rY, rZ);
	glEnd();

	window->display();
}


void Window3d::update()
{
	const float movementSpeed = 5.f;
	float cameraSpeed = 1.f * (dt * 100);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
		cameraSpeed *= 2;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		cameraPos += cameraSpeed * cameraFront;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		cameraPos -= cameraSpeed * cameraFront;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		cameraPos.y += cameraSpeed;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		cameraPos.y -= cameraSpeed;
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

		if (event.type == sf::Event::MouseMoved)
		{
			if (window->hasFocus())
			{
				float xpos = sf::Mouse::getPosition(*window).x;
				float ypos = sf::Mouse::getPosition(*window).y;

				sf::Mouse::setPosition(sf::Vector2i(window->getSize().x / 2, window->getSize().y / 2), *window);

				if (firstMouse)
				{
					lastX = window->getSize().x / 2;
					lastY = window->getSize().y / 2;
					firstMouse = false;
				}

				float xoffset = xpos - lastX;
				float yoffset = lastY - ypos;
				//lastX = xpos;
				//lastY = ypos;

				float sensitivity = 0.1f;
				xoffset *= sensitivity;
				yoffset *= sensitivity;

				yaw += xoffset;
				pitch += yoffset;

				if (pitch > 89.0f)
					pitch = 89.0f;
				if (pitch < -89.0f)
					pitch = -89.0f;

				glm::vec3 direction;
				direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
				direction.y = sin(glm::radians(pitch));
				direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
				cameraFront = glm::normalize(direction);
			}
		}

		if (event.type == sf::Event::MouseWheelMoved)
		{
		}

		if (event.type == sf::Event::Resized)
		{
			glViewport(0.0f, 0.0f, event.size.width, event.size.height);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			float ratio = (float)event.size.width / (float)event.size.height;
			glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);
		}

		if (event.type == sf::Event::KeyPressed)
		{
			const float movementSpeed = 5.f;

			switch (event.key.code)
			{
			
			}
		}
	}
}


void Window3d::initWindow()
{
	window = new sf::Window(sf::VideoMode(500, 400), "Poly Lab", sf::Style::Default, sf::ContextSettings(24, 8, 0, 3, 3));
	window->setVerticalSyncEnabled(true);
	window->setFramerateLimit(60);
	window->setActive(true);
	window->setMouseCursorGrabbed(true);
}
