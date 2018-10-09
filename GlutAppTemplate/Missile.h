#ifndef MISSILE_H
#define MISSILE_H


class Missile {
	float x, y, velX, velY, angle, r, g , b;
	bool hit;
	float missileSize;

public:
	Missile() {
		x = 0;
		y = 0;
		velX = 0;
		velX = 0;
		angle = M_PI / 2;
		missileSize = 6.0;
		hit = false;
	}

	Missile(float x, float y, float velX, float velY, float angle) {
		this->x = x;
		this->y = y;
		this->velX = velX + .01*cos(angle);
		this->velY = velY + .01*sin(angle);
		this->angle = angle;
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

	void setHit() {
		hit = true;
	}

	bool getHit() {
		return hit;
	}

	//for missle size
	float getmissilesize() {
		return missileSize;
	}

	void setmissilesize(float missileSize) {
		this->missileSize = missileSize;
	}

	void draw() {
		glPointSize(missileSize);
		glBegin(GL_POINTS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(x, y, -1);
		glEnd();
	}

	void moveMissile() {
		x += velX;
		y += velY;
	}

	void missileHit() {
		hit = true;
	}
};
#endif // !MISSILE_H