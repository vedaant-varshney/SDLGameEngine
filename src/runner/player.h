#ifndef PLAYER_H
#define PLAYER_h

#include "../engine/gameobject.h"

class Player : public GameObject
{
    private:
    public:
    Player(CustomTexture *objTexture, int x, int y, int wHeight, int wWidth) : GameObject{objTexture, x, y, 5, wHeight, wWidth} {};
    ~Player() {};

    void handleEvent(SDL_Event & e) override;

};

#endif
