#pragma once
#include "powerUp.h"
#include "Ship.h"
#include "App.h"
#include "Timer.h"
#include "Asteroid.h"



class Shield : public powerUp {
public:
	/*
std::vector<Shield> shield[1];

	Timer shieldTimer;

	Shield()
	{
		 r = 0;
		 g = 0;
		 b = 1;
	}

	void shieldActivate(Ship ship) {
		if (containsShip(ship)) {
				for (float theta = 0; theta <= 2 * M_PI; theta += 0.1) {
					glVertex2f(radius * cos(theta) + ship.getShipX() , radius * sin(theta) + ship.getShipY);
					shield[0].push_back(Shield());
				}
				shieldTimer.setTimer();
		}
	}

	void shieldHit(Asteroid asteroid) {
		float d = sqrt(pow(asteroid.getX() - this->x, 2) + pow(asteroid.getY() - this->y, 2));
		if (d < (radius + asteroid.getRadius()))
			shield[0].pop_back();
	}

	bool shieldStatus() {
		if (shieldTimer.compareTime() > 30) {
			shield[0].pop_back();
		}

	}
	*/
};