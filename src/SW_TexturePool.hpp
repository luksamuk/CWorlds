// SW_TexturePool.hpp
// Definitions for the texture pool, a class
// designed to store all textures currently loaded,
// and also manage the texture loading so textures
// aren't loaded twice.

#ifndef SW_TEXTUREPOOL_H
#define SW_TEXTUREPOOL_H

#include "SW_Base.hpp"
#include "SW_CommonTypes.hpp"

class SW_Texture
{
    friend class SW_TexturePool;
private:
    GLuint name = 0x00;
    vec2   size;
    string path;
public:
    string Path() const;
    vec2   Size() const;
};

class SW_Font {
private:
    vec2 charsize;
    SW_Texture* m_texture;
public:
    //vec2 CharSize() const;
    //void DrawString(vec2 Position, string Text, Color tint);
    //vec2 MeasureString(string text) const;
    //void dispose();
};

class SW_TexturePool {
private:
	static map<SW_Texture*, GLuint> texturemap;
	static map<SW_Texture*, int>    texturealloc_count;
public:
    static SW_Texture* LoadTexture(string assetpath);
    static void        DisposeTexture(SW_Texture* &t);
    static void        Clear();
};

#endif
