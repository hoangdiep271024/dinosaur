#include"Text.h"

TextObject::TextObject()
{
    texture = NULL;
}

TextObject::~TextObject()
{

}

void TextObject::setText(const string &text)
{
    str_val = text;
}

void TextObject::setColor(const int& type)
{
    if (type == WHITE)
    {
        SDL_Color color =  {255, 255, 255};
        text_color = color;
    }

    else if (type == BLACK)
    {
        SDL_Color color =  {0, 0, 0};
        text_color = color;
    }

    else
    {
        SDL_Color color =  {255, 0, 0};
        text_color = color;
    }
}

void TextObject::CreateText(TTF_Font* font)
{
    if (texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, str_val.c_str(), text_color );
    if( textSurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
    dst.w = textSurface->w;
    dst.h = textSurface->h;
    texture = SDL_CreateTextureFromSurface(renderer, textSurface );
    if (texture == NULL)
        cout << "FAILED" << SDL_GetError() << '\n';
    SDL_FreeSurface(textSurface);
}

void TextObject::Render(int x, int y)
{
    dst.x = x;
    dst.y = y;
    SDL_RenderCopy(renderer, texture,NULL, &dst);
}
