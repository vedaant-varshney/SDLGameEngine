#include "gameobject.h"

void GameObject::move()
{
    x += vel.x;
    y += vel.y;
    boundsCheck();
}

void GameObject::move(int xPos, int yPos)
{
    x = xPos;
    y = yPos;
    boundsCheck();
}

void GameObject::boundsCheck()
{
    if (x < 0)
    {
        x = 0;
    }
    if (y < 0)
    {
        y = 0;
    }
    if (x > windowWidth-objTexture->getWidth()) {
        x = windowWidth-objTexture->getWidth();
    }
    if (y> windowHeight-objTexture->getHeight()) {
        y = windowHeight-objTexture->getHeight();
    }
}

bool GameObject::collidedWith(GameObject* other) {
    int otherX = other->getXPos();
    int otherY = other->getYPos();
    int otherWidth = other->getWidth();
    int otherHeight = other->getHeight();

    bool xContained = false;
    bool yContained = false;

    // Left Edge Contained
    if (otherX >= x && otherX <= x+objTexture->getWidth()) {
        xContained = true;
    }
    // Right Edge Contained
    else if (otherX+otherWidth >= x && otherX+otherWidth <= x+objTexture->getWidth()) {
        xContained = true;
    }

    // Top Edge Contained
    if (otherY >= y && otherY <= y+objTexture->getHeight()) {
        yContained = true;
    }
    // Bottom Edge Contained
    else if (otherY+otherHeight >= otherY && otherY+otherHeight <= x+objTexture->getHeight()) {
        yContained = true;
    }

    return xContained && yContained;


}
