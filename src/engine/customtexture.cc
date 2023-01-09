#include "customtexture.h"

void CustomTexture::free()
{
    if (imTexture != nullptr)
    {
        SDL_DestroyTexture(imTexture);
        imTexture = nullptr;
        imWidth = 0;
        imHeight = 0;
    }
}

void CustomTexture::setColor(Uint8 r, Uint8 g, Uint8 b)
{
    SDL_SetTextureColorMod(imTexture, r, g, b);
}

void CustomTexture::setAlpha(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(imTexture, alpha);
}

void CustomTexture::setBlendMode(SDL_BlendMode blending)
{
    SDL_SetTextureBlendMode(imTexture, blending);
}

void CustomTexture::render(int x, int y, SDL_Rect *clip)
{
    SDL_Rect renderQuad = {x, y, imWidth, imHeight};

    // Updates render quad to clip dimensions
    if (clip != nullptr) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopy(renderer, imTexture, clip, &renderQuad);
}


void CustomTexture::loadFromFile(std::string path) {
    // Get rid of pre-existing texture
    free();
    SDL_Texture* newTexture = nullptr;

    // Bring in Image as surface
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    // Make texture from loaded surface
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    // Update Image width and height
    imWidth = loadedSurface->w;
    imHeight = loadedSurface->h;
    // Free old surface
    SDL_FreeSurface(loadedSurface);

    // Update field
    imTexture = newTexture;
}
