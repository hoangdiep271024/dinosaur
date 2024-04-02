#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<random>
#include<SDL.h>

using namespace std;

struct Tree{
    SDL_Rect des_tree;
    SDL_Rect des_bird;
    Tree();
    void Move();
};


#endif // TREE_H

