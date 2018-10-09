#define _USE_MATH_DEFINES
#include <math.h>
#include "Circle.h"

void Circle::draw(){
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
    
    for (float theta = 0; theta <= 2*M_PI; theta+=0.1) {
        glVertex2f(radius * cos(theta) + x, radius * sin(theta) + y);
    }
    
    glEnd();
}


bool Circle::contains(float x, float y){
    // Calculate distance from center of circle to missle top left point
    float d = sqrt(pow(x - this->x, 2) + pow(y - this->y, 2));
    
    // If that distance is less than the radius, then the top left point
    // of the missle is inside the circle
    return d < radius;
}
