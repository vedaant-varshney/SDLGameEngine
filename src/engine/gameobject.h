#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "SDL2/SDL.h"
#include "customtexture.h"

struct Vel
{
    int x;
    int y;
};

// Core Element of Game, comprises Enemies, Players, etc
class GameObject
{
private:
    void boundsCheck(); 

protected:
    CustomTexture *objTexture;
    int x, y; // Position
    int maxSpeed;
    int windowHeight;
    int windowWidth;
    bool visible = true;
    // Directional Velocity
    Vel vel{0, 0};

public:
    GameObject(CustomTexture *objTexture, int x, int y, int maxSpeed, int wHeight, int wWidth) : objTexture{objTexture}, x{x}, y{y}, maxSpeed{maxSpeed}, windowHeight{wHeight}, windowWidth{wWidth} {}

    // We let the Game remove all textures
    ~GameObject() {}

    // Handling Input/Controls
    virtual void handleEvent(SDL_Event &e) = 0;

    // Updates position to new x and y
    // Without params, moves based on velocity
    void move();
    void move(int xPos, int yPos);

    // Renders to Screen
    void render()
    {
        if (visible)
            objTexture->render(x, y);
    }

    // Returns true if the GameObject collided with the other GameObject
    bool collidedWith(GameObject* other);
    


    // Getters
    bool getVisible() { return visible; }
    Vel getVel() { return vel; }
    int getMaxSpeed() {return maxSpeed;}
    int getXPos() {return x;}
    int getYPos() {return y;}
    int getWidth() {return objTexture->getWidth();}
    int getHeight() {return objTexture->getHeight();}

    // Setters
    void setVisible(bool vis) { visible = vis; }
    void setXVel(int newXVel) { vel.x = newXVel; }
    void setYVel(int newYVel) { vel.y = newYVel; }
};

#endif
