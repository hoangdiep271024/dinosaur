#include "setup.h"
#include "dino.h"
#include "tree.h"
#include "menu.h"
#include "text.h"
#include "bird.h"
using namespace std;

SDL_Window  * window;
SDL_Renderer * renderer;
SDL_Surface * surface;

void init()
{
    window = NULL;
    renderer = NULL;
    if( SDL_Init( SDL_INIT_VIDEO |SDL_INIT_AUDIO) < 0 )
    {
        cout << "SDL could not initialize! SDL Error: "  << endl <<SDL_GetError();
    }
    else
    {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            cout << "Warning: Linear texture filtering not enabled!" ;
        }
        window = SDL_CreateWindow( "DINO RUNNING", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            cout << "Window could not be created! SDL Error: "<< endl << SDL_GetError() ;
        }
        else
        {
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( renderer == NULL )
            {
                cout << "Renderer could not be created! SDL Error: " << endl << SDL_GetError() ;
            }
            else
            {
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    cout << "SDL_image could not initialize! SDL_image Error: " << endl << IMG_GetError() ;
                }
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
				
				}

                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					cout<< "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() ;
				}
                if( TTF_Init() == -1 )
                {
                    cout << "SDL_ttf could not initialize! SDL_ttf Error: "<< endl <<  TTF_GetError() ;
                }
            }
        }
    }
}

int main(int argc, char* agrv[])
{
    srand(time(0));
    init();

    SDL_Texture* Player_Tex = IMG_LoadTexture(renderer, "img/nv1.png");
    SDL_Texture* tree_Tex = IMG_LoadTexture(renderer, "img/xuongrong.png");
    SDL_Texture* bird_Tex = IMG_LoadTexture(renderer, "img/bird1.png");
    SDL_Texture* menu = IMG_LoadTexture(renderer, "img/menu.png");
    SDL_Texture* back_Tex = IMG_LoadTexture(renderer, "img/bachrao.jpg");
    SDL_Texture* back2_Tex= IMG_LoadTexture(renderer, "img/background2.jpg" );
    SDL_Texture* back3_Tex= IMG_LoadTexture(renderer, "img/background3.jpg" );
    SDL_Texture* ket1 = IMG_LoadTexture(renderer, "img/ket1.png");
    SDL_Texture* ket2 = IMG_LoadTexture(renderer, "img/ket2.png");
    SDL_Texture* ket3 = IMG_LoadTexture(renderer, "img/ket3.png");
    Mix_Chunk *  gScratch = Mix_LoadWAV("sound/scratch.wav");
    Mix_Music* gMusic = Mix_LoadMUS( "sound/music.wav" );
    Mix_Chunk* glose = Mix_LoadWAV( "sound/lose.wav" );
    Mix_Chunk* gbird = Mix_LoadWAV( "sound/chim.wav" );
    SDL_Texture* pausebutton = IMG_LoadTexture(renderer, "img/pausebutton.png");
    SDL_Texture* continuebutton = IMG_LoadTexture(renderer, "img/continue.png");
    SDL_Texture* musicbutton = IMG_LoadTexture(renderer, "img/volum.png");
    SDL_Texture* pause = IMG_LoadTexture(renderer, "img/pause.jpg");
    SDL_Rect Pause = {0,0,840,600};
    SDL_Rect Menu = {300, 350, 200, 100};
    SDL_Rect Back2 ={0,0,1200,600};
    SDL_Rect Back3 ={0,0,1200,600};
     SDL_Rect Ket1 = {0, 0, 840, 600};
      SDL_Rect Ket2 = {0, 0, 840, 600};
       SDL_Rect Ket3 = {0, 0, 840, 600};
       SDL_Rect Pausebutton = {790, 0, 50, 52};
       SDL_Rect Continuebutton = {297, 200, 206,100};
       SDL_Rect Musicbutton= {790,60,50,52};
    TTF_Font* Font = TTF_OpenFont("font/Welbut__.ttf", 20);

    if( Font == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
    }
    
    TextObject ScoreText;
    ScoreText.setColor(TextObject::RED);
    TextObject HighestText;
     HighestText.setColor(TextObject::BLACK);
    int k=1;
    float score = 0;
    float highest=-1;
    bool gameRunning = true;
    bool isPaused = false;
    srand(time(NULL));
    Mix_PlayMusic(gMusic, -1);
    SDL_Event event;

    Player Character;

    Tree Obstacle;

    Bird Animal;
    int showmenu = show_menu(surface);
    if (showmenu == 1)
        return 0;
    if (showmenu == 0)
    {
        while(1)
        {
            if (showmenu == 0 )
                gameRunning = 1;
            Obstacle.des_tree.x = 840;
            Animal.Bird_des.x = Obstacle.des_tree.x + 700;
            Animal.Bird_des.y = rand()%200+250;
            while(gameRunning)
            {
                while(SDL_PollEvent(&event) != 0)
                {
                    if(event.type == SDL_QUIT)
                    {
                        gameRunning = false;
                    }
                    Character.HandleEvent(event);
                    if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.sym == SDLK_UP )
        {
           Mix_PlayChannel( -1, gScratch, 0 );
        }
        if (event.key.keysym.sym == SDLK_LEFT) {
                isPaused = !isPaused; // Khi nhấn phím p, đảo trạng thái Pause
            }
        
        }
                    if(event.type==SDL_MOUSEBUTTONDOWN){
                        if(event.button.x >= 790 && event.button.y >=60&& event.button.y<=112){
            if( Mix_PlayingMusic() == 0 )
							{
								//Play the music
								Mix_PlayMusic( gMusic, -1 );
							}
							//If music is being played
							else
							{
								//If the music is paused
								if( Mix_PausedMusic() == 1 )
								{
									//Resume the music
									Mix_ResumeMusic();
								}
								//If the music is playing
								else
								{
									//Pause the music
									Mix_PauseMusic();
								}
        }
                    }
                        if(event.button.x >= 790 && event.button.y <= 52)
                            {
                               isPaused=!isPaused;
                            }
                    }
                    
                    
                    
                    }
                SDL_RenderClear(renderer);
                if(!isPaused){

                Character.Move();

                if((int)score > k*100)
                {
                    Obstacle.player_val -= 0.5;
                    Animal.bird_val -= 0.5;
                    k++;
                }
                Obstacle.Move();
               

                score += 0.2;

                SDL_RenderCopy(renderer, back_Tex,NULL,NULL);
                Character.Render_Player(renderer, Player_Tex);
                Obstacle.Render_Tree(renderer, tree_Tex);

                string score_val = to_string((int)score);
                string highest_val= to_string((int)highest);
                ScoreText.setText("score: " + score_val);
                ScoreText.CreateText(Font);
                ScoreText.Render(0, 0);
                HighestText.setText("highest: " + highest_val);
               HighestText.CreateText(Font);
                HighestText.Render(120, 0);
                SDL_RenderCopy(renderer, pausebutton, NULL, &Pausebutton);
                SDL_RenderCopy(renderer, musicbutton, NULL, &Musicbutton);
                if(score>=highest){highest= score;}
                if(score>=150 & score<=370){
                   SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, back2_Tex, NULL, &Back2); 
                     Animal.Move();
               Character.Render_Player(renderer, Player_Tex);
                Obstacle.Render_Tree(renderer, tree_Tex);
Animal.Render_Bird(renderer, bird_Tex);
SDL_RenderCopy(renderer, musicbutton, NULL, &Musicbutton);
                    ScoreText.setText("score: " + score_val);
                ScoreText.CreateText(Font);
                ScoreText.Render(0, 0);
                SDL_RenderCopy(renderer, pausebutton, NULL, &Pausebutton);
                HighestText.setText("highest: " + highest_val);
               HighestText.CreateText(Font);
                HighestText.Render(120, 0);
                }
                if(score>370){ SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, back3_Tex, NULL, &Back3); 
                     Animal.Move();
               Character.Render_Player(renderer, Player_Tex);
                Animal.Render_Bird(renderer, bird_Tex);
                Obstacle.Render_Tree(renderer, tree_Tex);
                SDL_RenderCopy(renderer, pausebutton, NULL, &Pausebutton);
                    ScoreText.setText("score: " + score_val);
                ScoreText.CreateText(Font);
                ScoreText.Render(0, 0);
                SDL_RenderCopy(renderer, musicbutton, NULL, &Musicbutton);
                HighestText.setText("highest: " + highest_val);
               HighestText.CreateText(Font);
                HighestText.Render(120, 0);
                }

                if(checkCollision(Obstacle.des_tree,Character.des_player)&& score<=200)
                {    Mix_PlayChannel( -1, glose, 0 );
                    gameRunning = false;
                    
                    Character.down = 0;
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, ket1, NULL, &Ket1);
                    ScoreText.CreateText(Font);
                ScoreText.Render(0, 0);
               HighestText.CreateText(Font);
                HighestText.Render(120, 0);
                    SDL_RenderCopy(renderer, menu, NULL, &Menu);
                    SDL_RenderPresent(renderer);
                    score = 0;
                    Obstacle.player_val=-6;
                    Animal.bird_val=-6.5;
                    
                    break;
                }
                if(checkCollision(Animal.Bird_des,Character.des_player) && score<=200)
                {    Mix_PlayChannel( -1, glose, 0 );
                    gameRunning = false;
                    
                    Character.down = 0;
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, ket1, NULL, &Ket1);
                    ScoreText.CreateText(Font);
                ScoreText.Render(0, 0);
                 HighestText.CreateText(Font);
                HighestText.Render(120, 0);
                    SDL_RenderCopy(renderer, menu, NULL, &Menu);
                    SDL_RenderPresent(renderer);
                    score=0;
                    Obstacle.player_val=-6;
                    Animal.bird_val=-6.5;
                    break;
                }
                if(score<200){Animal.Bird_des.y=370;}
                 if(checkCollision(Obstacle.des_tree,Character.des_player)&& score>200 && score<=450)
                {   Mix_PlayChannel( -1, glose, 0 );
                    gameRunning = false;
                   
                    Character.down = 0;
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, ket2, NULL, &Ket2);
                    ScoreText.CreateText(Font);
                ScoreText.Render(0, 0);
                 HighestText.CreateText(Font);
                HighestText.Render(120, 0);
                    SDL_RenderCopy(renderer, menu, NULL, &Menu);
                    SDL_RenderPresent(renderer);
                    score=0;
                    Obstacle.player_val=-6;
                    Animal.bird_val=-6.5;
                    
                    break;
                }
                 if(checkCollision(Obstacle.des_tree,Character.des_player)&& score>450)
                {    Mix_PlayChannel( -1, glose, 0 );
                    gameRunning = false;
                    
                    Character.down = 0;
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, ket3, NULL, &Ket3);
                    ScoreText.CreateText(Font);
                ScoreText.Render(0, 0);
                 HighestText.CreateText(Font);
                HighestText.Render(120, 0);
                    SDL_RenderCopy(renderer, menu, NULL, &Menu);
                    SDL_RenderPresent(renderer);
                    score=0;
                    Obstacle.player_val=-6;
                    Animal.bird_val=-6.5;
                    break;
                }
                if(checkCollision(Animal.Bird_des,Character.des_player) && score>200 && score<=450)
                {   Mix_PlayChannel( -1, glose, 0 );
                    gameRunning = false;
                    
                    Character.down = 0;
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, ket2, NULL, &Ket2);
                    ScoreText.CreateText(Font);
                ScoreText.Render(0, 0);
                 HighestText.CreateText(Font);
                HighestText.Render(120, 0);
                    SDL_RenderCopy(renderer, menu, NULL, &Menu);
                    SDL_RenderPresent(renderer);
                    score=0;
                    Obstacle.player_val=-6;
                    Animal.bird_val=-6.5;
                   
                    break;
                }
                if(checkCollision(Animal.Bird_des,Character.des_player) && score>450)
                {   Mix_PlayChannel( -1, glose, 0 );
                    gameRunning = false;
                    
                    Character.down = 0;
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, ket3, NULL, &Ket3);
                    ScoreText.CreateText(Font);
                ScoreText.Render(0, 0);
                 HighestText.CreateText(Font);
                HighestText.Render(120, 0);
                    SDL_RenderCopy(renderer, menu, NULL, &Menu);
                    SDL_RenderPresent(renderer);
                    score=0;
                    Obstacle.player_val=-6;
                    Animal.bird_val=-6.5;
                    break;
                }
                if(Animal.Bird_des.x>720&&Animal.Bird_des.x<840){
                    Mix_PlayChannel( -1, gbird, 0 );
                }

                if(Obstacle.des_tree.x < 0)
                {
                    Obstacle.des_tree.x = rand()%100+1000;
                }
                if (Animal.Bird_des.x < 0)
                {
                    if (Obstacle.des_tree.x <= 750)
                    {
                        Animal.Bird_des.x = Obstacle.des_tree.x + rand()%100 + 700;
                        Animal.Bird_des.y = rand()%200+250;
                        if(Animal.Bird_des.y<390){Animal.Bird_des.y=400;}
                    }

                }} 
                if(isPaused){
                      SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, pause, NULL, &Pause);
                   SDL_RenderCopy(renderer, menu, NULL, &Menu);
                       SDL_RenderCopy(renderer, continuebutton, NULL, &Continuebutton);  
                        if (event.type == SDL_MOUSEBUTTONDOWN)
                        {
                           if(event.button.x >= 297 && event.button.x <= 503 && event.button.y >= 200 && event.button.y <= 300)
                            {
                               isPaused=!isPaused;
                            }



                            if(event.button.x >= 300 && event.button.x <= 500 && event.button.y >= 350 && event.button.y <= 450)
                            {
                                gameRunning=false;
                                isPaused=!isPaused;
                                score=0;                                 
                            }
                        }            
                }
               SDL_RenderPresent(renderer); 
            }
            if (gameRunning == 0)
            {
                if(SDL_PollEvent(&event) != 0 && event.type == SDL_QUIT)
                {
                    quitSDL(window, renderer);
                    return 0;
                }
                while(1)
                {
                    if (SDL_PollEvent(&event) != 0)
                    {
                        if(event.type == SDL_QUIT)
                        {
                            quitSDL(window, renderer);
                            return 0;
                        }
                        if (event.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if(event.button.x >= 300 && event.button.x <= 500 && event.button.y >= 350 && event.button.y <= 450)
                            {
                                showmenu = show_menu(surface);
                                break;
                            }
                        }
                    }
                }
            }
            if((SDL_PollEvent(&event) != 0 && event.type == SDL_QUIT) || showmenu == 1)
            {
                Mix_FreeChunk( gScratch );
                Mix_FreeChunk(glose);
                Mix_FreeMusic(gMusic);
                Mix_FreeChunk(gbird);
                gScratch=NULL;
                gMusic=NULL;
                 glose=NULL;
                 gbird=NULL;
                Mix_Quit();
                quitSDL(window, renderer);
                return 0;
            }
        }
    }
    quitSDL(window, renderer);
    return 0;
}
//g++ setup.cpp dino.cpp tree.cpp menu.cpp text.cpp bird.cpp main.cpp -I"C:\Users\HP 840 G3\Downloads\SDL2-devel-2.26.3-mingw\SDL2-2.26.3\i686-w64-mingw32\include\SDL2" -L"C:\Users\HP 840 G3\Downloads\SDL2-devel-2.26.3-mingw\SDL2-2.26.3\i686-w64-mingw32\lib" -w "-Wl,-subsystem,windows"-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_Mixer -lSDL2_ttf -o diep