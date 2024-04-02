#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<random>
#include<SDL.h>
#include<SDL_image.h>

using namespace std;

struct Tree
{
    float player_val =-6;
    SDL_Rect des_tree;
    Tree();
    void Move();
    void Render_Tree(SDL_Renderer *renderer,SDL_Texture * tree_Tex);
};


#endif

