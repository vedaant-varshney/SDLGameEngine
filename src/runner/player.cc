#include "player.h"
#include <iostream>


void Player::handleEvent(SDL_Event &e)
{

    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            setYVel(-maxSpeed);
            break;
        case SDLK_DOWN:
            setYVel(maxSpeed);
            break;
        case SDLK_LEFT:
            setXVel(-maxSpeed);
            break;
        case SDLK_RIGHT:
            setXVel(maxSpeed);
            break;
        }
    }
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            setYVel(0);
            break;
        case SDLK_DOWN:
            setYVel(0);
            break;
        case SDLK_LEFT:
            setXVel(0);
            break;
        case SDLK_RIGHT:
            setXVel(0);
            break;
        }
    }
};
