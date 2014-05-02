// SW_TexturePool.cpp
// Code for the actual texture pool.
#include "SW_TexturePool.hpp"

// Texture specifics
string SW_Texture::Path() const {
    return path;
}
vec2 SW_Texture::Size() const {
    return size;
}


// TexturePool specifics
map<SW_Texture*, GLuint> SW_TexturePool::texturemap;
map<SW_Texture*, int>    SW_TexturePool::texturealloc_count;

SW_Texture* SW_TexturePool::LoadTexture(string assetpath) {
    for(auto tex : texturemap) {
        if(tex.first->path == assetpath) {
                SW_Log("WARNING: %s already allocated; returning reference #d\n",
                       tex.first->path.c_str(), texturealloc_count[tex.first] + 1);
                texturealloc_count[tex.first] += 1;
                return tex.first;
        }
    }

    SDL_Surface* surface;
    GLenum mode;
    surface = IMG_Load(assetpath.c_str());
    if(!surface) {
        // Throwing an exception here is a good idea
        SW_Log("%s: Image is unexistant or invalid. Returning NULL\n", assetpath.c_str());
        return NULL;
    }

    switch(surface->format->BytesPerPixel) {
    case 4:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) mode = GL_BGRA;
        else mode = GL_RGBA;
        break;
    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) mode = GL_BGR;
        else mode = GL_RGB;
        break;
    default:
        SDL_FreeSurface(surface);
        SW_Log("%s: Image uses an unrecognizable format.\n", assetpath.c_str());
        return NULL;
    }

    SW_Texture* tex = new SW_Texture;
    tex->size = vec2(surface->w, surface->h);
    tex->path = assetpath;

    // Sends image to GPU and bind it to a name
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &tex->name);
    glBindTexture(GL_TEXTURE_2D, tex->name);

    // Wrapping mode
    // When making spritesheets, it is a good idea to leave some padding.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    // Generates mipmaps
    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);

    // Filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Generate image on GPU
    glTexImage2D(GL_TEXTURE_2D, 0, mode, tex->size.x, tex->size.y, 0, mode,
                 GL_UNSIGNED_BYTE, surface->pixels);

    SDL_FreeSurface(surface);

    texturemap[tex] = tex->name;
    texturealloc_count[tex] = 1;

    return tex;
}

void SW_TexturePool::DisposeTexture(SW_Texture* &t) {
    if(!t || texturealloc_count.find(t) == texturealloc_count.end()) {
        SW_Log("Error: texture is NULL or was not allocated by pool\n");
        return;
    }
    if(texturealloc_count[t] > 1) {
        texturealloc_count[t] -= 1;
        SW_Log("WARNING: Anullated reference to %s, %d remaining.\n",
               t->path.c_str(), texturealloc_count[t]);
        t = NULL;
        return;
    }
    SW_Log("Deleting texture %s...\n", t->path.c_str());
    glDeleteTextures(1, &t->name);
    if(texturemap.find(t) != texturemap.end()) texturemap.erase(t);
    else SW_Log("WARNING: Texture deallocated from GPU, but not found on TexturePool!\n");
    if(texturealloc_count.find(t) != texturealloc_count.end()) texturealloc_count.erase(t);
    else SW_Log("Warning: Texture deallocated from GPU, but number of instances not found on TexturePool!\n");
    delete t;
    t = NULL;
}

void SW_TexturePool::Clear() {
    while(!texturemap.empty()) {
        SW_Texture* tex = texturemap.begin()->first;
        DisposeTexture(tex);
    }
    texturealloc_count.clear();
}
