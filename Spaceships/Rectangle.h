#ifndef Rectangle_hpp
#define Rectangle_hpp

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

namespace ucm {
	class Rectangle {
		// Position
		float x, y;

		// Size
		float w, h;

		// Color
		float r, g, b;



	public:

		bool missle;

		// Default constructor
		Rectangle(float xx = 0, float yy = 0, float ww = 0.1, float hh = 0.1, float rr = 1, float gg = 0, float bb = 0) :
			x(xx), y(yy), w(ww), h(hh), r(rr), g(gg), b(bb) {

			missle = false;
		}

		// Draw method
		void draw();

		void fire();

		// Getters and setters
		float getX() const { return x; }
		float getY() const { return y; }
		void setX(float xx) { x = xx; }
		void setY(float yy) { y = yy; }

		float getW() const { return w; }
		float getH() const { return h; }
		void setW(float ww) { w = ww; }
		void setH(float hh) { h = hh; }

		float getR() const { return r; }
		float getG() const { return g; }
		float getB() const { return b; }
		void setColor(float rr, float gg, float bb) { r = rr; g = gg; b = bb; }
	};
}
#endif
