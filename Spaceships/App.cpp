#define _USE_MATH_DEFINES
#include "App.h"
#include <math.h>
using namespace std;

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    
    // This is our ship
    r = new ucm::Rectangle(0.0f, 0.5f);
    
    // This is the enemy
    c = new Circle(0.0f ,0.0f, 0.1f, 0.0f, 0.0f, 1.0f);
    
    // At the start, our ship should move to the right
    move = true;
    right = true;
    
    // Variables for enemy movement (circling the ship)
    theta = 0.0f;
    inc = 0.05f;
    
    // Specifies that at the start, the enemy has not been shot
    shot = false;
    
    // Position of the missle
    missleX = 0;
    missleY = 0.5;
    
    // Count how many missles we have fired
    counter = 0;
    
    // A variable that stores whether we have won or not
    gameover = false;
    
    // A variable that specifies whether we should execute idle function
    loop = true;
    
    // Welcome message
    cout << "Hit the blue Circle. Press F to fire." << endl;
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Draw the ship
    r->draw();
    
    // If a missle has been fired and it's not game over, draw that missle
    if (r->missle & !gameover){
        ucm::Rectangle* m = new ucm::Rectangle(missleX, missleY + 0.05f, 0.02f, 0.05f, 1.0f, 1.0f, 1.0f);
        m->draw();
    }
    
    // If the enemy has not been hit, draw it
    if (!shot){
        c ->draw();
    }
  
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        delete this;
        exit(0);
    }
    else if (key == ' '){
        // Uncomment below to enable user to stop moving
        // move = !move;
    }
    else if (key == 'f'){
        // Fire a missle from the current position
        missleX = r->getX() + 0.03f;
        missleY = r->getY() + 0.01f;
        r->fire();
        // Increment missle counter
        counter++;
    }
}

void App::idle(){
    // loop should always be true, unless it's game over
    if (loop) {
        
        // If the spaceship should move from side to side,
        // make it do so
        if (move){
            float x = r->getX();
            
            if (x >= 0.9){
                // Reached right edge, start moving left
                right = false;
            }
            
            if (x <= -1.0){
                // Reached left edge, start moving right
                right = true;
            }
            
            // Move in the appropriate derection
            if (right){
                r->setX(x+0.01f);
            }
            else {
                r->setX(x-0.01f);
            }
        }
        
        // If there is a missle, make it go up
        if (r->missle){
            missleY += 0.01f;
        }
        
        // Once missle leaves the screen, make it disappear
        if (missleY > 1){
            r->missle = false;
        }
        
        // Update coordinates of enemy
        if (theta <= 2*M_PI - inc){
            theta += inc;
        }
        else{
            theta = 0;
        }
        
        c->setX(0.3f*cos(theta)+r->getX() + 0.5f * r->getW());
        c->setY(0.3f*sin(theta)+r->getY() - 0.5f * r->getH());
        
        // Collision detection between missle and enemy
        if (c->contains(missleX, missleY) && r->missle){
            // Set shot to true so the enemy will not be drawn again
            shot = true;
            
            // Stop moving the ship
            move = false;
            
            // Set game over to true so that final message can be displayed
            gameover = true;
        }
        
        if (gameover){
            // Display final message
            cout << "You win!" << endl;
            if (counter == 1){
                cout << counter << " shot was fired." << endl;
            }
            else {
                cout << counter << " shots were fired." << endl;
            }
            cout << "Press ESC to exit game." << endl;
            
            // Stop looping, otherwise final message will be displayed many times
            loop = false;
        }
        
        // Redraw the scene after all modifications have been made
        redraw();
    }
}

App::~App(){
    delete r;
    delete c;
}
