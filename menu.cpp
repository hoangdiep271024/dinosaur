#include "menu.h"
#include "setup.h"
using namespace std;

int show_menu(SDL_Surface * screen)
{ 
    int u=1;
    SDL_Rect Back_scr = {0,0,840,600};
    // nut Play
    SDL_Rect Playbutton_dest = {360,240,120,60};
    SDL_Rect Playbutton_scr = {0,0,120,60};
    SDL_Rect Playbutton_bright_scr = {0,60,120,60};
    // nut Quit
    SDL_Rect Exitbutton_dest = {360,300,120,60};
    SDL_Rect Exitbutton_scr = {240,0,120,60};
    SDL_Rect Exitbutton_bright_scr = {240,60,120,60};

    SDL_Texture* back_Tex = IMG_LoadTexture(renderer, "img/dinosaurs-5687815_1280.jpg");
    SDL_RenderCopy(renderer, back_Tex,&Back_scr,NULL);

    SDL_Texture* button = IMG_LoadTexture(renderer, "img/Button.png");
    SDL_Texture* help =IMG_LoadTexture(renderer, "img/help.png");
    SDL_Rect Help={790, 0, 50, 50};
    SDL_Texture* help2= IMG_LoadTexture(renderer, "img/help2.png");
    SDL_Rect Help2={0, 0, 840, 600};
    SDL_Texture* back = IMG_LoadTexture(renderer, "img/back.png");
    SDL_Rect Back={0,0, 100, 100};
    SDL_RenderCopy(renderer, button,&Playbutton_scr,&Playbutton_dest);
    SDL_RenderCopy(renderer, button,&Exitbutton_scr,&Exitbutton_dest);
    SDL_RenderCopy(renderer, help, NULL, &Help);
    bool selected[2] = {0,0};
    int x, y;
    SDL_Rect Pos_menu[2];
    Pos_menu[0] = Playbutton_dest;
    Pos_menu[1] = Exitbutton_dest;
    SDL_Event event;
    while (1)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                return 1;
            }
            if (event.type == SDL_MOUSEMOTION && u==1)
            {
                x = event.motion.x;
                y = event.motion.y;
                if(check_click(Pos_menu[0],x,y))
                {
                    if(!selected[0])
                    {
                        selected[0] = 1;
                        SDL_RenderCopy(renderer,button,&Playbutton_bright_scr,&Playbutton_dest);
                    }
                }
                else
                {
                    if(selected[0])
                    {
                        selected[0] = 0;
                        SDL_RenderCopy(renderer,button,&Playbutton_scr,&Playbutton_dest);
                    }
                }
                if(check_click(Pos_menu[1],x,y))
                {
                    if(!selected[1])
                    {
                        selected[1] = 1;
                        SDL_RenderCopy(renderer,button,&Exitbutton_bright_scr,&Exitbutton_dest);
                    }
                }
                else
                {
                    if(selected[1])
                    {
                        selected[1] = 0;
                        SDL_RenderCopy(renderer,button,&Exitbutton_scr,&Exitbutton_dest);
                    }
                }
                
            }
            if (event.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if(event.button.x >= 790 && event.button.y <=50  )
                            {  u=2;
                                 SDL_RenderClear(renderer);
                                SDL_RenderCopy(renderer, help2, NULL, &Help2); 
                                SDL_RenderCopy(renderer, back, NULL, &Back);  } 
                                if(event.button.x <=100 && event.button.y <=100&& u==2) {
                                 SDL_RenderClear(renderer); 
                                 u=1;
                                 SDL_RenderCopy(renderer, back_Tex,&Back_scr,NULL);
                                 SDL_RenderCopy(renderer, button,&Playbutton_scr,&Playbutton_dest);
                                 SDL_RenderCopy(renderer, button,&Exitbutton_scr,&Exitbutton_dest);
                                 SDL_RenderCopy(renderer, help, NULL, &Help);
    }

                            
                        }
            x = event.button.x;
            y = event.button.y;
            for (int i = 0; i <= 2; i++)
            {
                if (check_click(Pos_menu[i],x,y) && u==1)
                    if(event.type == SDL_MOUSEBUTTONDOWN)
                        return i;
            }
           

        }
        SDL_RenderPresent(renderer);
    }
    return 1;
}
