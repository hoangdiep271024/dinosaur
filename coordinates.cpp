#include "tree.h"

using namespace std;

Tree::Tree(){
    des_tree.x = 850;
    des_tree.y = 474;
    des_tree.w = 30;
    des_tree.h = 36;
}

void Tree::Move(){
    des_tree.x -= 4;
}
