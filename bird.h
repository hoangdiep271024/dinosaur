#ifndef BIRD_H_
#define BIRD_H_

#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>

using namespace std;

struct Bird
{
    Bird();
    ~Bird();
    void Move();
    void Render_Bird(SDL_Renderer *renderer,SDL_Texture *bird_Text);
    float bird_val = -6.5;
    SDL_Rect Bird_scr[4], Bird_des;
    int frame;
};
#endif
