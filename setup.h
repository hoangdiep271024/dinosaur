#ifndef SETUP_H_
#define SETUP_H_

#include<SDL.h>
#include<SDL_image.h>
#include<random>
#include <bits/stdc++.h>
#include<time.h>
#include<SDL_ttf.h>

using namespace std;

const int WINDOW_WIDTH = 840;
const int WINDOW_HEIGHT = 600;

extern SDL_Window  * window;
extern SDL_Renderer * renderer;
extern SDL_Surface * surface;

int random(int a, int b);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

bool checkCollision(SDL_Rect a, SDL_Rect b);

void handleEvent(SDL_Event event, SDL_Rect &des, float &y_val);
bool check_click(SDL_Rect rect, int x, int y);

#endif
