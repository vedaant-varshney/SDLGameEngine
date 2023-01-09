#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>

class CustomTexture;
class GameObject;

class Game
{
protected:
    // Window width and height constants
    const int width, height;
    // Window we Render to
    SDL_Window *gWindow;
    // The actual renderer
    SDL_Renderer *gRenderer;

    // Textures used in game
    std::map<std::string, CustomTexture *> textures;
    // Game Objects
    std::map<std::string, GameObject *> gameObjects;

public:
    // Constructor for basic game elements
    Game(const int width, const int height);
    ~Game() = default;

    // Startup for the game including texture loading
    virtual void start();

    // Actual game loop
    virtual void run();

    // Handles freeing and cleanup
    virtual void end();

    // Getters
    int getWindowHeight() { return height; }
    int getWindowWidth() { return width; }

    // Setters
    void newTexture(std::string name, std::string path);
    void newGameObject(std::string name, GameObject *gObj);
};

#endif
