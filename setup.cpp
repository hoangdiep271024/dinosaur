#include "setup.h"
#include <bits/stdc++.h>

using namespace std;

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool checkCollision(SDL_Rect a, SDL_Rect b)
{

    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    return true;
}
bool check_click(SDL_Rect rect, int x, int y)
{
    return (x >= rect.x && y >= rect.y && x < rect.x + rect.w && y < rect.y +  rect.h);
}
int random(int a, int b)
{
    return rand() % (b-a+1) +a;
}


