#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "game_logic.h"
#include "functions_common.h"
#include "variables.h"
#include "timer.h"
#include "main_player.h"
#include "enemy.h"
#include "stone.h"
#include "diamond.h"
#include <string>
#include <ctime>

using namespace std;

int game_logic()
{
    int disp=120000+clock();
    score=0;
    char timer_left[20];
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    Mix_Music *music = NULL;
    if(sad_tune)
        music = Mix_LoadMUS( "Content/Sounds/sadness_and_sorrow.wav" );
    else
        music = Mix_LoadMUS( "Content/Sounds/strong_and_strike.wav" );
    Mix_PlayMusic( music, -1 );

    Player character;
    Enemy enemy(enemy_c);
    Enemy2 enemy2(enemy2_c);
    Timer fps;
	bool update=true;
	while(!quit)
	{
		while(SDL_PollEvent(&event))
		{
       		character.handle_events();

			if( event.type == SDL_QUIT )
			{
				quit = true;
			}

			/*if(event.type=SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE: 	quit=true; break;
					case SDLK_RIGHT :	level_beginx+=	10;break;
					case SDLK_LEFT :	level_beginx-=	10;		break;

				}
			}*/
		}

		if( update)
		{
			apply_surface( 0, 0, background0, screen,&camera2 );
			apply_surface( 0, 0, background1, screen,&camera1 );
			apply_surface( 0, 0, background2, screen,&camera );

            //Call the diamond loading logic and check for detections.
            diamond_load();

            //Call the stone loading logic and check for detections.
            stone_load();

            //Point 1
            character.move(enemy.handle_events(),enemy2.handle_events());

			apply_surface(level_endx-camera.x , level_endy, exitsign, screen );
			apply_surface( 800, 10, message, screen );
			sprintf(scoreboard,"Score : %d",score);
			message = TTF_RenderText_Solid( font, scoreboard, textColor );
            //Point 2

		}

        character.show();
        enemy.show();
        enemy2.show();

		if(character.health<=0)
		{
            apply_surface( 321, 210, overlay_die, screen);
            SDL_Flip( screen );
            bool return_scr=false;
            while(!return_scr)
            {
                while(SDL_PollEvent(&event))
                {
                    if( event.type == SDL_QUIT )
                    {
                        quit = true;
                        return_scr=true;
                        break;
                    }
                    else  if(event.type=SDL_KEYDOWN)
                    {
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_SPACE: return_scr=true;break;
                            case SDLK_ESCAPE:quit=true;return_scr=true;break;
                            default:break;
                        }
                    }
                }
                SDL_Delay(50);
            }
            if(!quit)
                return (-891);
		}
		else if(disp-clock()<=0)
		{
		    apply_surface( 321, 210, overlay_lose, screen);
            SDL_Flip( screen );
            bool return_scr=false;
            while(!return_scr)
            {
                while(SDL_PollEvent(&event))
                {
                    if( event.type == SDL_QUIT )
                    {
                        quit = true;
                        return_scr=true;
                        break;
                    }
                    else  if(event.type=SDL_KEYDOWN)
                    {
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_SPACE: return_scr=true;break;
                            case SDLK_ESCAPE:quit=true;return_scr=true;break;
                            default:break;
                        }
                    }
                }
                SDL_Delay(50);
            }
            if(!quit)
                return (-891);
		}
		else if(level_beginx>=11920)
		{
            level_no++;
            score+=(disp-clock())/100;
            sprintf(scoreboard,"Score : %d",score);
            apply_surface( 800, 10, TTF_RenderText_Solid( font, scoreboard, textColor ), screen );
            apply_surface( 321, 210, overlay_win, screen);
            SDL_Flip( screen );
            bool return_scr=false;
            while(!return_scr)
            {
                while(SDL_PollEvent(&event))
                {
                    if( event.type == SDL_QUIT )
                    {
                        quit = true;
                        return_scr=true;
                        break;
                    }
                    else  if(event.type=SDL_KEYDOWN)
                    {
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_SPACE: return_scr=true;break;
                            case SDLK_ESCAPE:quit=true;return_scr=true;break;
                            default:break;
                        }
                    }
                }
                SDL_Delay(50);
            }
            if(!quit)
                return (600+level_no);
		}
		sprintf(timer_left,"0%d:%d",(disp-clock())/60000,((disp-clock())/1000)%60);
        apply_surface( 470, 10, TTF_RenderText_Solid( font, timer_left, textColor ), screen );
		if( SDL_Flip( screen ) == -1 )
		{
			return 1;
		}

		if(keystates[SDLK_ESCAPE])
		{
			quit=true;
		}
        else if(keystates[SDLK_BACKSPACE])
		{
            level_no=1;
            Mix_HaltMusic();
            Mix_FreeMusic( music );
            Mix_CloseAudio();
			return (-891);
		}
		if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
	}

    Mix_HaltMusic();
    Mix_FreeMusic( music );
    Mix_CloseAudio();
    quit=false;
	return (-36);
}

/*
*   Obsolete code
*/

//Part 1

/*if(jump_condition)
{
    if((level_beginy)>=(600-128+16))
    {
        if(((level_beginx+48>=220&&level_beginx+16<=300))||((level_beginx+48>=700&&level_beginx+16<=780)))
        {
            printf("\nDetected : %d ",level_beginy);
            level_beginy=600-96;
            jump_condition=false;
            jump_val=0;
        }

    }
    else if(((level_beginy)<=(600-128+16))&&((level_beginy)>=(600-192+16)))
    {
        if(((level_beginx+48>=220&&level_beginx+16<=300))||((level_beginx+48>=700&&level_beginx+16<=780)))
        {
            printf("\nDetected : %d ",level_beginy);
            level_beginy=600-192;
            jump_condition=false;
            jump_val=0;
        }
    }
    else if((level_beginy)>=(600-224+16))
    {
        if(((level_beginx+48>=450&&level_beginx+16<=550)))
        {
            printf("\nDetected : %d ",level_beginy);
            level_beginy=600-96;
            jump_condition=false;
            jump_val=0;
        }
    }
    else if(((level_beginy)<=(600-224+16))&&((level_beginy)>=(600-288+16)))
    {
        if(((level_beginx+48>=450&&level_beginx+16<=550)))
        {
            printf("\nDetected : %d ",level_beginy);
            level_beginy=600-288;
            jump_condition=false;
            jump_val=0;
        }
    }

}
else if(!jump_condition&&level_beginy!=(600-96))
{

if(level_beginy==(600-192))
{
    if(((level_beginx+48<=210||level_beginx+16>=310))&&((level_beginx+48<=690||level_beginx+16>=790)))
        {
            printf("\nExecuted : %d ",level_beginy);
            level_beginy+=16;
            free_fall=true;
        }
}
else if(level_beginy==(600-288))
{
    if(((level_beginx+48<=450||level_beginx+16>=550)))
        {
            printf("\nExecuted : %d ",level_beginy);
            level_beginy+=16;
            free_fall=true;
        }
}
else
{
    printf("\nExecuted : %d ",level_beginy);
            level_beginy+=16;
            free_fall=true;

}

}


if(jump_condition)
{
    if((level_beginy)>=(600-128+16))
    {
        if(((level_beginx+48>=220&&level_beginx+16<=300))||((level_beginx+48>=700&&level_beginx+16<=780)))
        {
            printf("\nDetected : %d ",level_beginy);
            level_beginy=600-96;
            jump_condition=false;
            jump_val=0;
        }

    }
    else if(((level_beginy)<=(600-128+16))&&((level_beginy)>=(600-192+16)))
    {
        if(((level_beginx+48>=220&&level_beginx+16<=300))||((level_beginx+48>=700&&level_beginx+16<=780)))
        {
            printf("\nDetected : %d ",level_beginy);
            level_beginy=600-192;
            jump_condition=false;
            jump_val=0;
        }
    }
    else if((level_beginy)>=(600-224+16))
    {
        if(((level_beginx+48>=450&&level_beginx+16<=550)))
        {
            printf("\nDetected : %d ",level_beginy);
            level_beginy=600-96;
            jump_condition=false;
            jump_val=0;
        }
    }
    else if(((level_beginy)<=(600-224+16))&&((level_beginy)>=(600-288+16)))
    {
        if(((level_beginx+48>=450&&level_beginx+16<=550)))
        {
            printf("\nDetected : %d ",level_beginy);
            level_beginy=600-288;
            jump_condition=false;
            jump_val=0;
        }
    }
}
*/

//Part 2


/*if(((level_beginx+16)>=240)&&((level_beginx+48)<=(stone_coordx[i]+BLOCK_SIZE_W)))
{	if((level_beginy+64)<=stone_coordy[i])
    {
        jump_condition=false;
        jump_val=0;
        level_beginy=stone_coordy[i]-64;
    }
    else if((level_beginy)>=(stone_coordy[i]+BLOCK_SIZE_H))
    {
        jump_condition=false;
        jump_val=0;
        level_beginy=stone_coordy[i]-64;
    }
}*/
