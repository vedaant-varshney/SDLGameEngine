#ifndef CUST_TEXT
#define CUST_TEXT

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

enum TextureType
{
    TEXTURE_IMAGE,
    TEXTURE_TEXT
};

// Custom Texture class allowing for easy rendering and loading of image sprites
class CustomTexture
{
private:
    int imWidth;
    int imHeight;
    SDL_Texture *imTexture;
    SDL_Renderer* renderer;
    int type = TEXTURE_IMAGE;


public:
    // Initializes Texture Variables
    CustomTexture(SDL_Renderer* renderer) : imWidth{0}, imHeight{0}, renderer{renderer}, imTexture{nullptr} {};
    // Class Destructor
    ~CustomTexture() { free(); };

    // Image Loading
    void loadFromFile(std::string path);

    // Texture Modification
    void setAlpha(Uint8 alpha);
    void setColor(Uint8 r, Uint8 g, Uint8 b);
    void setBlendMode(SDL_BlendMode blending);

    // Render: position and clip of texture
    void render(int x, int y, SDL_Rect* clip = nullptr);
 
    // Deallocates memory
    void free();

    // Getters
    int getWidth() { return imWidth; }
    int getHeight() { return imHeight; }

    // Setters
};

#endif
