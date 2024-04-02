#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>

using namespace std;
struct  Player
{
    float y_val_player;
    SDL_Rect des_player;
    int down = 0;
    float FALL_SPEED = 0.2;
    Player();
    void Move();
    void Render_Player(SDL_Renderer *renderer,SDL_Texture *player_Text);
    
    SDL_Rect Player_scr[4], Player_des;
    int frame;
    void HandleEvent(SDL_Event event);
};
#endif
