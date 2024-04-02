#include "dino.h"

using namespace std;
void Player::Move()
{
    if (down == 1)
        return;
    y_val_player += FALL_SPEED;
    des_player.y += y_val_player;
    if(des_player.y  > 469)
    {
        des_player.y  = 469;
        y_val_player = 0;
    }
    if(des_player.y <290)
    {
        des_player.y  = 290;
        y_val_player = 7.5;
    }
}

Player::Player()
{
    des_player.x = 130;
    des_player.y = 469;
    des_player.w = 64;
    des_player.h = 50;
    
    Player_scr[0].x = 0;
    Player_scr[0].y = 10;
    Player_scr[0].w = 55;
    Player_scr[0].h = 50;

    Player_scr[1].x = 64;
    Player_scr[1].y = 10;
    Player_scr[1].w = 55;
    Player_scr[1].h = 50;

    Player_scr[2].x = 128;
    Player_scr[2].y = 10;
    Player_scr[2].w = 55;
    Player_scr[2].h = 50;

    Player_scr[3].x = 192;
    Player_scr[3].y = 10;
    Player_scr[3].w = 55;
    Player_scr[3].h = 50;

    frame = 0;
}
    void Player::Render_Player(SDL_Renderer *renderer,SDL_Texture *Player_Tex)
{

    SDL_RenderCopy(renderer, Player_Tex,&Player_scr[frame/4],&des_player);

    frame++;
    if (frame/4 >= 4)
    {
        frame =0;
    }
}
void Player::HandleEvent(SDL_Event event)
{
    if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.sym == SDLK_UP && des_player.y == 469)
        {
            y_val_player = -9;
        }
        if(event.key.keysym.sym == SDLK_DOWN && des_player.y == 469)
        {
            des_player.y = 489;
            des_player.h = 30;
            down = 1;
        }
    }
    else
    {
        if(event.type == SDL_KEYUP)
        {
            if(event.key.keysym.sym == SDLK_DOWN)
            {
                des_player.y = 469;
                des_player.h = 50;
                down = 0;
            }
        }

    }
}

