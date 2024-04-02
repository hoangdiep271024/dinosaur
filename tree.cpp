#include "tree.h"
#include "setup.h"

using namespace std;

Tree::Tree()
{
    des_tree = {random(841,850), 467,50,57};
}

void Tree::Move()
{
    des_tree.x += player_val;
}

void Tree::Render_Tree(SDL_Renderer *renderer,SDL_Texture * tree_Tex)
{
    SDL_RenderCopy(renderer, tree_Tex, NULL, &des_tree);
}
