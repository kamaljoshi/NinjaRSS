#include "SDL/SDL.h"
#include <stdio.h>
#include "functions_common.h"
#include "load_screen.h"
#include "high_scores.h"
#include "sprite_cut.h"
#include "game_logic.h"
#include "credits.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

	if(argc==1)
	{
	    argv[1]="windowed";
	}

	if( init(argv[1]) == false )
	{
		return 1;
	}
	 //SDL_Surface* icon = SDL_LoadBMP(iconName))
    //SDL_WM_SetIcon(icon, NULL);
    int l;
    do{
    bool start_game=false;
    while(!start_game)
    {
        int start_opt_returned=load_start_screen();

        switch(start_opt_returned)
        {
            case 8: SDL_Quit();exit(0);break;
            case 6:show_credits();break;
            case 4:show_high_scores();break;
            case 2:start_game=true;break;
            case 0:break;
        }
    }

	if( load_files() == false )
	{
		return 1;
	}

	set_clips();

  	l=game_logic();
    }while(l==-891||(l>600&&l<610));
	clean_up();

	return 0;
}
