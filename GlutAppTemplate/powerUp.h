#pragma once
#ifndef Circle_hpp
#define Circle_hpp

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <math.h>
#include "Ship.h"
//#define M_PI 3.141592


class powerUp {
	/*
std::vector<powerUp> powerUps;
protected:
	// Position
	float x, y;

	// Size
	float radius;

	// Color
	float r, g, b;
public:
	
	// Default constructor
	powerUp(float xx = 0, float yy = 0, float theRadius = 0.05, float rr = 1, float gg = 1, float bb = 1) :
		x(xx), y(yy), radius(theRadius), r(rr), g(gg), b(bb) {}

	// Draw method
	virtual void draw(){
		glColor3f(r, g, b);
		glBegin(GL_POLYGON);

		for (float theta = 0; theta <= 2 * M_PI; theta += 0.1) {
			glVertex2f(radius * cos(theta) + x, radius * sin(theta) + y);
		}

		glEnd();
	}

	bool containsShip(Ship s) {
		// Calculate distance from center of powerup to ship center
		float d = sqrt(pow(s.getShipX() - this->x, 2) + pow(s.getShipY() - this->y, 2));
		
		// If that distance is less than the radius, then the top left point
		// of the missle is inside the circle
		return d < radius;
	}

		// Getters and setters
	
	float getX() const { return x; }
	float getY() const { return y; }
	void setX(float xx) { x = xx; }
	void setY(float yy) { y = yy; }

	float getRadius() const { return radius; }
	void setRadius(float theRadius) { radius = theRadius; }

	float getR() const { return r; }
	float getG() const { return g; }
	float getB() const { return b; }
	void setColor(float rr, float gg, float bb) { r = rr; g = gg; b = bb; }
	*/
};

#endif
