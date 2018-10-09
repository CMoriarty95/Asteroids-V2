#ifndef ASTEROID_H
#define ASTEROID_H
#include "Missile.h"
#include "Ship.h"




class Asteroid {
protected:
	float x, y, velX, velY, angle, radius;
	int size;
	bool hit;
public:
	Asteroid() {
		glColor3f(1, 1, 1);
		x = 0;
		y = 0;
		velX = 0;
		velY = 0;
		angle = M_PI / 2;
		size = 0;
		radius = 0;
		hit = false;
	}

	Asteroid(float x, float y, float velX, float velY, float angle, int size) {
		glColor3f(1, 1, 1);
		this->x = x;
		this->y = y; 
		this->velX = velX;
		this->velY = velY;
		this->angle = angle;
		this->size = size;
		radius = 0;
		hit = false;
	}

	//for X
	float getX() {
		return x;
	}

	void setX(float x) {
		this->x = x;
	}

	//for Y
	float getY() {
		return y;
	}

	void setY(float y) {
		this->y = y;
	}

	//for velX
	float getvelX() {
		return velX;
	}

	void setvelX(float velX) {
		this->velX = velX;
	}

	//for velY
	float getvelY() {
		return velY;
	}

	void setvelY(float velY) {
		this->velY = velY;
	}

	//for angle
	float getangle() {
		return angle;
	}

	void setangle(float angle) {
		this->angle = angle;
	}

	float getRadius() {
		return radius;
	}

	//for hi
	bool getHit() {
		return hit;
	}

	void setHit(bool hit) {
		this->hit = hit;
	}

	void draw() {
		if(hit == false){
			if (size == 0) {
				glBegin(GL_POLYGON);
				radius = 0.1;
				for (float theta = 0; theta <= 2 * M_PI; theta += 0.1) {
					glVertex3f(radius * cos(theta) + x, radius * sin(theta) + y, -1);
				}
				glEnd();
			}
			else if (size == 1) {
				radius = .05;
				glBegin(GL_POLYGON);
				for (float theta = 0; theta <= 2 * M_PI; theta += 0.1) {
					glVertex3f(radius * cos(theta) + x, radius * sin(theta) + y, -1);
				}
				glEnd();
			}
			else {
				radius = .025;
				glBegin(GL_POLYGON);
				for (float theta = 0; theta <= 2 * M_PI; theta += 0.1) {
					glVertex3f(radius * cos(theta) + x, radius * sin(theta) + y, -1);
				}
				glEnd();
			}
		}
	}

	void moveAsteroid() {
		x += velX;
		y += velY;
		if (getX() >= 1) {
			setX(-.99);
		}
		else if (getY() >= 1) {
			setY(-.99);
		}
		else if (getX() <= -1) {
			setX(.99);
		}
		else if (getY() <= -1) {
			setY(.99);
		}
	}

	bool contains(Missile missile) {
		float d = sqrt(pow(missile.getX() - this->x, 2) + pow(missile.getY() - this->y, 2));
		return d < radius;
	}

};
#endif // !ASTEROID_H
