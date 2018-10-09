#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

class App: public GlutApp {
    // Maintain app state here
    
	ucm::Rectangle* r;
    Circle* c;
    
    bool right;
    bool move;
    
    float theta;
    float inc;
    
    float missleX;
    float missleY;
    
    bool shot;
    
    int counter;
    
    bool gameover;
    bool loop;
    
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    
    void idle();
    
    ~App();
};

#endif
