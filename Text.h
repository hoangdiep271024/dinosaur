#ifndef TEXT_H_
#define TEXT_H_

#include<string>
#include "setup.h"

using namespace std;

struct TextObject
{
    enum TextColor
    {
        WHITE = 0,
        BLACK = 1,
        RED = 2,
    };
    TextObject();
    ~TextObject();
    void setText(const string &text);
    void setColor(const int &type);
    void CreateText(TTF_Font* font);
    void Render(int x, int y);

    SDL_Texture* texture;
    SDL_Rect dst;
    string str_val;
    SDL_Color text_color;

};

#endif



