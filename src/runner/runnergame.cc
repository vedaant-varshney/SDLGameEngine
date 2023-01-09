#include "runnergame.h"
#include "../engine/customtexture.h"
#include "player.h"

void Runner::start()
{
    newTexture("background", "images/background.png");
    newTexture("playerTexture", "images/player.png");
    GameObject *gObj = new Player{textures["playerTexture"], 0, 0, height, width};
    newGameObject("player", gObj);
    gObj = nullptr;
}

void Runner::run()
{
    SDL_Event e;
    bool quit = false;

    int xPos = 0;
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            gameObjects["player"]->handleEvent(e);
        }

        textures["background"]->render(0, 0);
        // textures["playerTexture"]->render(xPos, 50);
        // ++xPos;
        gameObjects["player"]->move();
        gameObjects["player"]->render();

        SDL_RenderPresent(gRenderer);
    }
    end();
}

// TODO check later if we need an override for end

// void Runner::end() {

// }
