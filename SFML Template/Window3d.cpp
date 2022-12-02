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

	yaw = -90;
	firstMouse = true;

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	centerZ = 3;
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

	float x = cos(timeClock.getElapsedTime().asSeconds());
	float y = sin(timeClock.getElapsedTime().asSeconds());
	float z = -1;
	glm::mat4 view;
	//view = glm::lookAt(glm::vec3(centerX,centerY,centerZ), glm::vec3(0,0,0), glm::vec3(0,1,0));
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

	
	glLoadIdentity();
	glMultMatrixf(glm::value_ptr(view));

	//Front
	glBegin(GL_POLYGON);
	glColor3f(1, .5, 0);
	glVertex3f(0,0,0);
	glVertex3f(100,0,0);
	glVertex3f(100,100,0);
	glVertex3f(0,100,0);
	glEnd();
	//Left
	glBegin(GL_POLYGON);
	glColor3f(0, .5, 1);
	glVertex3f(0,0,0);
	glVertex3f(0,100,0);
	glVertex3f(0, 100, 100);
	glVertex3f(0, 0, 100);
	glEnd();
	//Bottom
	glBegin(GL_POLYGON);
	glColor3f(1, 0, .5);
	glVertex3f(0,0,0);
	glVertex3f(100,0,0);
	glVertex3f(100,0,100);
	glVertex3f(0,0,100);
	glEnd();

	//Top
	glBegin(GL_POLYGON);
	glColor3f(1, 0, .5);
	glVertex3f(0, 100, 0);
	glVertex3f(100, 100, 0);
	glVertex3f(100, 100, 100);
	glVertex3f(0, 100, 100);
	glEnd();

	window->display();
}


void Window3d::update()
{
	if (firstMouse)
	{
		lastX = sf::Mouse::getPosition(*window).x;
		lastY = sf::Mouse::getPosition(*window).y;
		firstMouse = false;
	}

	float xpos = sf::Mouse::getPosition(*window).x;
	float ypos = sf::Mouse::getPosition(*window).y;

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.3f;
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
			//sf::Mouse::setPosition(sf::Vector2i(window->getSize().x / 2, window->getSize().y / 2), *window);
			
		}

		if (event.type == sf::Event::MouseWheelMoved)
		{

		}

		if (event.type == sf::Event::Resized)
		{
			glViewport(0.0f, 0.0f, event.size.width, event.size.height);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(0, event.size.width, 0, event.size.height, -1000, 1000);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			const float speed = 1.f;
			const float angle = 10.f;
			const float cameraSpeed = 10.f;

			switch (event.key.code)
			{
			case sf::Keyboard::I:
				camY += speed;
				break;
			case sf::Keyboard::K:
				camY -= speed;
				break;
			case sf::Keyboard::J:
				camX += speed;
				break;
			case sf::Keyboard::L:
				camX -= speed;
				break;
			case sf::Keyboard::Q:
				centerZ += speed;
				//glTranslatef(0, speed, 0);
				break;
			case sf::Keyboard::E:
				centerZ -= speed;
				//glTranslatef(0, speed, 0);
				break;
			case sf::Keyboard::W:
				cameraPos += cameraSpeed * cameraFront;
				centerY += speed;
				//glTranslatef(0, speed, 0);
				break;
			case sf::Keyboard::S:
				cameraPos -= cameraSpeed * cameraFront;
				centerY -= speed;
				//glTranslatef(0, -speed, 0);
				break;
			case sf::Keyboard::A:
				cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
				centerX += speed;
				//glTranslatef(-speed,0,0);
				break;
			case sf::Keyboard::D:
				cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
				centerX -= speed;
				//glTranslatef(speed,0,0);
				break;
			case sf::Keyboard::Right:
				glRotatef(angle, 0, speed, 0);
				break;
			case sf::Keyboard::Left:
				glRotatef(angle, 0, -speed, 0);
				break;
			case sf::Keyboard::Up:
				glRotatef(angle, speed, 0, 0);
				break;
			case sf::Keyboard::Down:
				glRotatef(angle, -speed, 0, 0);
				break;
			case sf::Keyboard::Space:
				glLoadIdentity();
				break;
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
}
