#include "game.h"
#include "customtexture.h"

Game::Game(const int width, const int height): width{width}, height{height} {
    // First Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    // Linear Texture Filtering
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"); 

    // Creating Window
    gWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

    // Vsynced Renderer for Window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // Starting with White Renderer
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    // Initialize PNG loading
    IMG_Init(IMG_INIT_PNG);
    
}

void Game::run() {
    SDL_Event e;
    bool quit = false;

    int xPos = 0;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        textures["background"]->render(0, 0);
        textures["playerTexture"]->render(xPos, 50);
        ++xPos;
        SDL_RenderPresent(gRenderer);
    }
    end();
}

void Game::end() {
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;
    // TODO: make sure to free all textures and Game Objects
    IMG_Quit();
    SDL_Quit();
}

void Game::newTexture(std::string name, std::string path) {
    CustomTexture* cText = new CustomTexture{gRenderer};
    cText->loadFromFile(path);
    textures[name] = cText;
    cText = nullptr;
}


void Game::newGameObject(std::string name, GameObject *gObj) {
    gameObjects[name] = gObj;
}


void Game::start() {
    newTexture("background", "images/background.png");
    newTexture("playerTexture", "images/player.png");
}
