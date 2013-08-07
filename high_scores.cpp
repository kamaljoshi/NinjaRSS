
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include <string>
#include "functions_common.h"
#include "variables.h"
#include "md5.h"


int check_validity_high_scores(std::string name,int score_val,char *score_ref)
{   int j=0;
    while(score_val)
    {
        name[j]+=(score_val%7)+((j*j)%5);
        j++;
        score_val/=7;
    }
    std::string md5hash=md5(name);
    std::string md5hash1=md5(md5hash);
    std::string md5hash2=md5(score_ref);
    int i=16;
    while(i--)
    {
        if(md5hash1[i]!=md5hash2[i])
        {
            return 78;
        }
    }
    return 1;
}

void show_high_scores()
{
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    Mix_Music *music = NULL;
    music = Mix_LoadMUS( "Content/Sounds/alone.wav" );
    Mix_PlayMusic( music, -1 );
    SDL_Surface *high_scores_background=NULL,*high_scores_text=NULL,*message_disp=NULL;
    high_scores_background=load_image("Content/Textures/Backgrounds/room.png");
    high_scores_text=load_image("Content/Textures/highscore_title.png");
    TTF_Font *font_used=TTF_OpenFont("Content/Fonts/njnaruto.ttf",28);
    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
    apply_surface(0,0,high_scores_background,screen);
    apply_surface(500-143,112,high_scores_text,screen);
    FILE *ifile;

    ifile=fopen("Content/bin/hs.exe","r");
    for(int i=0;i<3;i++)
    {
        char name[12],name2[12], string_in_use[40],score_check[20];
        int score_list=0;
        /*if(!(fscanf(ifile,"%s : %d-%s\n",&name,&score_list,&score_check)))
        {
        break;

        }*/
        fscanf(ifile,"%s : ",&name);
        std::string name1=name;
        strcpy(name2,name);
        fscanf(ifile,"%d-",&score_list);
        fscanf(ifile,"%s\n",&score_check);
        //fprintf(ifile,"%s : %d-%d",score_list,score_list,score_check);
        //printf("%s : %d\n",name,score_list);
        int r=check_validity_high_scores(name1,score_list,score_check);

        if(r)
        {
            sprintf(string_in_use,"%s   :    %d",name1.c_str(),score_list);
        }
        else
        {
            sprintf(string_in_use,"Value Tampered");
        }
		message_disp = TTF_RenderText_Solid( font_used, string_in_use, textColor );
		apply_surface( 300, 230+90*i, message_disp, screen );
    }
    fclose(ifile);


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
    SDL_FreeSurface(high_scores_background);
    SDL_FreeSurface(high_scores_text);

    Mix_HaltMusic();
    Mix_FreeMusic( music );
    Mix_CloseAudio();

    if(quit)
    {
         SDL_Quit();
         exit(0);
    }

}
