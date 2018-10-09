#include "Triangle.h"

void Triangle::draw(){
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
    
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    
    glEnd();
}
