#include "bird.h"

using namespace std;

Bird::Bird()
{
    Bird_des = {1500,300,77,77};

    Bird_scr[0].x = 0;
    Bird_scr[0].y = 0;
    Bird_scr[0].w = 77;
    Bird_scr[0].h = 60;

    Bird_scr[1].x = 80;
    Bird_scr[1].y = 10;
    Bird_scr[1].w = 77;
    Bird_scr[1].h = 40;

    Bird_scr[2].x = 160;
    Bird_scr[2].y = 12;
    Bird_scr[2].w = 77;
    Bird_scr[2].h = 40;

    Bird_scr[3].x = 240;
    Bird_scr[3].y = 30;
    Bird_scr[3].w = 77;
    Bird_scr[3].h = 65;

    frame = 0;
}

Bird::~Bird()
{

}

void Bird::Render_Bird(SDL_Renderer *renderer,SDL_Texture *bird_Tex)
{

    SDL_RenderCopy(renderer, bird_Tex,&Bird_scr[frame/4],&Bird_des);

    frame++;
    if (frame/4 >= 4)
    {
        frame =0;
    }
}

void Bird::Move()
{
    Bird_des.x += bird_val;
}
