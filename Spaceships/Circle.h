#ifndef Circle_hpp
#define Circle_hpp

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class Circle {
    // Position
    float x, y;
    
    // Size
    float radius;
    
    // Color
    float r, g, b;
    
public:
    // Default constructor
    Circle(float xx=0, float yy=0, float theRadius=0.1, float rr=1, float gg=0, float bb=0):
    x(xx), y(yy), radius(theRadius), r(rr), g(gg), b(bb){}
    
    // Draw method
    void draw();
    
    bool contains(float x, float y);
    
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
};

#endif
