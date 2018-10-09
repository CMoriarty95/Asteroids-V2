#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "Ship.h"
#include "RgbImage.h"
#include "TexRect.hpp"
#include "Asteroid.h"

class App : public GlutApp {
	// Maintain app state here
	std::vector<Asteroid> asteroids;

	float mx;
	float my;
	bool loop;
	bool pause;
	bool over;

	// Declared Ship
	Ship* s;

public:
	// Constructor, to initialize state
	App(const char* label, int x, int y, int w, int h);

	// These are the events we want to handle
	void draw();
	void keyPress(unsigned char key);
	void mouseDown(float x, float y);
	void mouseDrag(float x, float y);
	void idle();
	void drawAsteroid();
	void spawnAsteroid();
	void checkHit();
	void displayScore();
	void gameOver();
	bool containsShip();
	GLuint loadTexture(const char *filename);
	GLuint nebula;
	TexRect* background;
};

#endif
