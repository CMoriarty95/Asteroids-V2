#include "App.h"
#include "Ship.h"
#include "Missile.h"
#include "Asteroid.h"
#include <time.h>
#include <ctime>
#include "Score.h"



clock_t start = clock();

Score score;

int tempTime = 0;
int asteroidCount = 0;
int displayCount = 0;
App::App(const char* label, int x, int y, int w, int h) : GlutApp(label, x, y, w, h) {
	// Initialize state variables
	mx = 0.0;
	my = 0.0;
	loop = true;
	pause = false;
	//asteroids.push_back(Asteroid(.04f, .04f, -.003, -.003, -0.003));
	// This is our ship
#if defined WIN32
	nebula = loadTexture("..\\nebula.bmp");
#else
	nebula = loadTexture("..\\nebula.bmp");
#endif
	background = new TexRect(-1, 1, 2, 2);
	s = new Ship();
	srand(time(0));
}

void App::draw() {

	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Set Color
	glColor3d(1.0, 1.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, nebula);
	background->draw();


	// Draw the Ship
	s->drawShip();
	s->drawMissiles();
	spawnAsteroid();
	drawAsteroid();
	idle();

	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}

GLuint App::loadTexture(const char *filename) {
	GLuint texture_id;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename);

	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
	//    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );


	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);





	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
		GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());

	return texture_id;

}

void App::mouseDown(float x, float y) {
	// Update app state
	mx = x;
	my = y;

	// Redraw the scene
	redraw();
}

void App::mouseDrag(float x, float y) {
	// Update app state
	mx = x;
	my = y;

	// Redraw the scene
	redraw();
}

void App::keyPress(unsigned char key) {
	if (pause != true) {
		if (key == 27) {
			// Exit the app when Esc key is pressed
			exit(0);
		}
		if (key == 97) {
			s->rotateLeft();
			s->moveShip();
			redraw();
		}
		if (key == 100) {
			s->rotateRight();
			s->moveShip();
			redraw();
		}
		if (key == 119) {
			s->accelerateShip();
			redraw();
		}
		if (key == 32) {
			s->fire();
			score.addShot();
			redraw();
		}
		if (key == 114) {
			loop = false;
			pause = true;
			redraw();
		}
	}
	else {
		if (key == 114) {
			loop = true;
			pause = false;
			redraw();
		}
		if (key == 27) {
			// Exit the app when Esc key is pressed
			exit(0);
		}
	}

}

void App::drawAsteroid() {
		for (int i = 0; i < asteroids.size(); i++){
				asteroids[i].draw();
		}
}

void App::spawnAsteroid() {

	int time = (int)(clock() - start) / 100;  //FINISH WRITING SPAWN CODE, MODULO THE TIME, PLACE IN IF STATEMENTS FOR TIME 0-30, 30-60 ECT
	
	float x, y, angle;
	float velX = 0;
	float velY = 0;
	int size = 0;
	if (time % 8 == 0 && tempTime != time) {
		tempTime = time;
		asteroidCount++;
		int spawn = rand() % 4;
		if (spawn == 0) {
			angle = ((((float)rand() / (float)(RAND_MAX)) * M_PI / 2) + 5 * M_PI / 4);
			x = 0; y = 1.1;
			velX = .0005*cos(angle) -.00025;
			velY = -.0005*sin(angle);
			size = rand() % 3;
			asteroids.push_back(Asteroid(x, y, velX, velY, angle, size));
		}
		else if (spawn == 1) {
			angle = ((((float)rand() / (float)(RAND_MAX)) * M_PI / 2) + 3 * M_PI / 4);
			x = 1.1; y = 0;
			velX = -.0005*cos(angle);
			velY = .0005*sin(angle) - .00025;
			size = rand() % 3;
			asteroids.push_back(Asteroid(x, y, velX, velY, angle, size));
		}
		else if (spawn == 2) {
			angle = ((((float)rand() / (float)(RAND_MAX)) * M_PI / 2) + M_PI / 4);
			x = 0; y = -1.1;
			velX = .0005*cos(angle) - .00025;
			velY = -.0005*sin(angle);
			size = rand() % 3;
			asteroids.push_back(Asteroid(x, y, velX, velY, angle, size));
		}
		else if (spawn == 3) {
			angle = ((((float)rand() / (float)(RAND_MAX)) * M_PI / 2) + 7 * M_PI / 4);
			x = -1.1; y = 0;
			velX += -.0005*cos(angle);
			velY += .0005*sin(angle);
			size = rand() % 3;
			asteroids.push_back(Asteroid(x, y, velX, velY, angle, size));
		}
	}
}

void App::checkHit() {
	for (int i = 0; i < asteroids.size(); i++) {
		for (int j = 0; j < s->missiles.size(); j++) {
			if (asteroids[i].contains(s->missiles[j]) && !asteroids[i].getHit()) {
				asteroids[i].setHit(true);
				s->missiles[j].setHit();
				score.addHit();
			}
		}
	}
}

void App::displayScore() {
	score.displayStats(start);
}

bool App::containsShip() {
	float d;
	for (int i = 0; i < asteroids.size(); i++) {
		d = sqrt(pow(asteroids[i].getX() - s->getShipX(), 2) + pow(asteroids[i].getY() - s->getShipY(), 2));
		if (d < asteroids[i].getRadius() && !asteroids[i].getHit()){
			pause = true;
			if(displayCount<1){
				score.displayStats(start);
				displayCount++;
				return true;

			}
		}
	}
	return false;
}

void App::gameOver() {

}

void App::idle() {
	if (loop && containsShip() == false && pause == false) {
		for (int i = 0; i < asteroids.size(); i++) {
			asteroids[i].moveAsteroid();
		}
		s->moveShip();
		checkHit();
		redraw();
	}
	else gameOver();

};