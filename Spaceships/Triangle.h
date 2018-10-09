#ifndef Triangle_hpp
#define Triangle_hpp

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class Triangle {
    // Position
    float x1, y1, x2, y2, x3, y3;
    
    // Color
    float r, g, b;
    
public:
    // Default constructor
    Triangle(float xx1=0, float yy1=0, float xx2=0.1, float yy2=0, float xx3=0.1, float yy3=0.1, float rr=1, float gg=0, float bb=0):
    x1(xx1), y1(yy1), x2(xx2), y2(yy2), x3(xx3), y3(yy3), r(rr), g(gg), b(bb){}
    
    // Draw method
    void draw();
    
    // Getters and setters
    float getX1() const { return x1; }
    float getY1() const { return y1; }
    void setX1(float xx) { x1 = xx; }
    void setY1(float yy) { y1 = yy; }
    
    float getX2() const { return x2; }
    float getY2() const { return y2; }
    void setX2(float xx) { x2 = xx; }
    void setY2(float yy) { y2 = yy; }
    
    float getX3() const { return x3; }
    float getY3() const { return y3; }
    void setX3(float xx) { x3 = xx; }
    void setY3(float yy) { y3 = yy; }

    
    float getR() const { return r; }
    float getG() const { return g; }
    float getB() const { return b; }
    void setColor(float rr, float gg, float bb) { r = rr; g = gg; b = bb; }
};

#endif
