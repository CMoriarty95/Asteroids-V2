#ifndef Ship_hpp
#define Ship_hpp

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <math.h>
# define M_PI 3.141592
#include <vector>
#include <Missile.h>
#include "Asteroid.h"

// Player Ship is a triangle
class Ship {
	// Position
	float shipX, shipY, shipAngle;
	//Ship design
	float shipFrontX, shipFrontY, shipLeftX, shipLeftY, shipRightX, shipRightY;
	// Color
	float r, g, b;
	//velocity of ship
	float velX, velY;

public:
	// Default constructor
	Ship() {
		shipX = 0;
		shipY = 0;
		shipAngle = (M_PI / 2);
		velX = 0;
		velY = 0;
		r = 1;
		g = 1;
		b = 1;
	}
	std::vector<Missile> missiles;
	// Getters and setters
	// Ship Position 
	float getShipX() const { return shipX; }
	float getShipY() const { return shipY; }
	void setShipX(float x) { shipX = x; }
	void setShipY(float y) { shipY = y; }
	//May or may not need this, dont need any reason to call side of ship?
	
	//front of ship
	float getshipFrontX() const {return shipFrontX;}
	float getshipFrontY() const {return shipFrontY;}
	void setshipFrontX(float xx) {shipFrontX = xx;}
	void setshipFrontY(float yy) {shipFrontY = yy;}
	// ship left point
	float getshipLeftX() const {return shipLeftX;}
	float getshipLeftY() const {return shipLeftY;}
	void setshipLeftX(float xx) {shipLeftX = xx;}
	void setshipLeftY(float yy) {shipLeftY = yy;}
	// ship right point
	float getshipRightX() const { return shipRightX;}
	float getshipRightY() const {return shipRightY;}
	void setshipRightX(float xx) {shipRightX = xx;}
	void setshipRightY(float yy) {shipRightY = yy;}
	
	//ship velocity
	float getVelX() const { return velX; }
	float getVelY() const { return velY; }
	void setVelX(float x) { velX = x; }
	void setVelY(float y) { velY = y; }
	//ship Angle
	float getShipAngle() { return shipAngle; }
	void setShipAngle(float angle) { shipAngle = angle; }

	// Colors
	float getR() const { return r; }
	float getG() const { return g; }
	float getB() const { return b; }

	// Set Color
	void setColor(float rr, float gg, float bb) {
		r = rr;
		g = gg;
		b = bb;
	}

	// Draw Function
	void drawShip() {

		shipFrontX = shipX + .05*cos(shipAngle);
		shipFrontY = shipY + .05*sin(shipAngle);
		shipLeftX = shipX + .05*cos((3 * M_PI / 4) + shipAngle);
		shipLeftY = shipY + .05*sin((3 * M_PI / 4) + shipAngle);
		shipRightX = shipX + .05*cos((5 * M_PI / 4) + shipAngle);
		shipRightY = shipY + .05*sin((5 * M_PI / 4) + shipAngle);

		glColor3f(r, g, b);
		glBegin(GL_POLYGON);
		glVertex3f(shipFrontX, shipFrontY, -1);
		glVertex3f(shipLeftX, shipLeftY, -1);
		glVertex3f(shipRightX, shipRightY, -1);
		glEnd();
	}

	void moveShip() {
		shipX += velX;
		shipY += velY;
		if (getShipX() >= 1) {
			setShipX(-.99);
		}
		else if (getShipY() >= 1) {
			setShipY(-.99);
		}
		else if (getShipX() <= -1) {
			setShipX(.99);
		}
		else if (getShipY() <= -1) {
			setShipY(.99);
		}
	}
	void accelerateShip() {
		velX += .0005*cos(shipAngle);
		velY += .0005*sin(shipAngle);
		if (velX > .01) { velX = .01; }
		if (velY > .01) { velY = .01; }
		if (velX < -.01) { velX = -.01; }
		if (velY < -.01) { velY = -.01; }
		shipX += velX;
		shipY += velY;
	}

	// Rotate on Key Press
	void rotateLeft() {
		shipAngle += (M_PI / 18);
		//drawShip();
	}

	void rotateRight() {
		shipAngle -= (M_PI / 18);
		//drawShip();
	}

	void drawMissiles() {
		for (int i = 0; i < missiles.size(); i++) {
			missiles[i].draw();
			missiles[i].moveMissile();
			if (missiles[i].getX() > 1 || missiles[i].getX() < -1 || missiles[i].getY() > 1 || missiles[i].getY() < -1 || missiles[i].getHit()) {
				missiles.erase(missiles.begin() + i);
			}
		}
	}

	void setMissilesSize(int x) {
		for (int i = 0; i < missiles.size(); i++)
			missiles[i].setmissilesize(x);
	}

	// Fire Missle Function
	void fire() {
		missiles.push_back(Missile(shipX, shipY, velX, velY, shipAngle));
		
	}

	bool destroyed(Asteroid& x) {

		//if front of ship
		float d = sqrt(pow(x.getX() - shipFrontX, 2) + pow(x.getY() - shipFrontY, 2));
		if (d < x.getRadius()){
			std::cout << "YOU DEAD" << std::endl;
			return true;
		}
		//if left of ship
		d = sqrt(pow(x.getX() - shipLeftX, 2) + pow(x.getY() - shipLeftY, 2));
		if (d < x.getRadius())
			return true;

		//if right of ship
		d = sqrt(pow(x.getX() - shipRightX, 2) + pow(x.getY() - shipRightY, 2));
		if (d < x.getRadius())
			return true;

	}

};

#endif