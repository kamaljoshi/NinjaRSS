#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "credits.h"
#include "functions_common.h"
#include "variables.h"


void show_credits()
{
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    Mix_Music *music = NULL;
    music = Mix_LoadMUS( "Content/Sounds/Untitled_Session_2_mixdown.wav" );
    Mix_PlayMusic( music, -1 );
    SDL_Surface *credits_background=NULL,*credits_scroll=NULL;
    SDL_Rect scroll_roll;
    scroll_roll.x=0;
    scroll_roll.y=0;
    scroll_roll.w=440;
    scroll_roll.h=85;
    credits_background=load_image("Content/Textures/credits.png");
    credits_scroll=load_image("Content/Textures/scroll.png");

    for(;scroll_roll.h<401;scroll_roll.h+=2)
    {
        apply_surface(0,0,credits_background,screen);
        apply_surface(280,100,credits_scroll,screen,&scroll_roll);
        SDL_Delay(10);
        SDL_Flip(screen);
    }

    SDL_Flip(screen);
    bool return_to_start=false,quit=false;
    while(!return_to_start&&!quit)
    {
        while(SDL_PollEvent(&event))
		{
       		if( event.type == SDL_QUIT )
			{
				quit=true;
			}

			if(event.type=SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym)
				{
				    //case SDLK_RETURN:return_to_start=true;break;
					//case SDLK_ESCAPE: 	return_to_start=true; break;
                    case SDLK_BACKSPACE:return_to_start=true;break;
                    default : break;
				}
			}
            else if( event.type == SDL_KEYUP )
            {
                switch( event.key.keysym.sym )
                {
                    //case SDLK_RETURN:return_to_start=true;break;
                    //case SDLK_ESCAPE: 	return_to_start=true; break;
                    case SDLK_BACKSPACE:return_to_start=true;break;
                    default : break;
                }
            }
        }
    SDL_Delay(200);
    }
    SDL_FreeSurface(credits_background);
    SDL_FreeSurface(credits_scroll);

    Mix_HaltMusic();
    Mix_FreeMusic( music );
    Mix_CloseAudio();

    if(quit)
    {
         SDL_Quit();
         exit(0);
    }
}



