#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "load_screen.h"
#include "functions_common.h"
#include "variables.h"

int load_start_screen()
{
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    Mix_Music *music = NULL;
    music = Mix_LoadMUS( "Content/Sounds/the_raising_fighting_spirit.wav" );
    Mix_PlayMusic( music, -1 );
    SDL_Surface *start_screen_background=NULL,*start_screen_ninja=NULL;
    //SDL_Surface *start_screen_start=NULL,*start_screen_options=NULL,*start_screen_exit=NULL,*start_screen_hs=NULL,*start_screen_credits=NULL,*start_screen_sel=NULL;
    SDL_Surface *start_button=NULL,*start_button_small=NULL,*start_button_bg=NULL,*start_button_bg_small=NULL,*start_button_exit=NULL,*start_button_hs=NULL,*start_button_back=NULL,*start_button_credits=NULL;
    start_screen_background=load_image("Content/Textures/Backgrounds/titlescreenBG.png");
    start_screen_ninja=load_image("Content/Textures/ninja.png");
    //start_screen_start=load_image("Content/Textures/startnBtn.png");
    //start_screen_exit=load_image("Content/Textures/exitBtn.png");
    //start_screen_sel=load_image("Content/Textures/selHover.png");
    //start_screen_hs=load_image("Content/Textures/highscoresBtn.png");
    //start_screen_credits=load_image("Content/Textures/creditsBtn.png");
    start_button=load_image("Content/main_start.png");
    start_button_small=load_image("Content/main_start_small.png");
    start_button_bg=load_image("Content/main_button_bg.png");
    start_button_bg_small=load_image("Content/main_button_bg_small.png");
    start_button_exit=load_image("Content/main_exit.png");
    start_button_hs=load_image("Content/main_hs.png");
    start_button_back=load_image("Content/main_back.png");
    start_button_credits=load_image("Content/main_credits.png");
    bool button_start=false;
    bool button_exit=false,button_credits=false,button_hs=false;
    //start_screen_options=load_image("Content/Textures/optionBtn.png");
    bool quit=false;
    int t=2;
    if(start_screen_background==NULL)
        quit=true;
    SDL_Rect clipStartScreenB;
    SDL_Rect clipStartScreenN;
    bool change_opt=true,opt_selected=false;

    clipStartScreenB.x = 0;
    clipStartScreenB.y = 0;
    clipStartScreenN.x = 0;
    clipStartScreenN.y = 0;

    /*if(first_exec)
    {
        for(int i=1;i<=20;i++)
        {
            for(int j=1;j<=40;j++)
            {

                clipStartScreenB.w = 50*i;
                clipStartScreenB.h = 15*j;

                apply_surface(0,0,start_screen_background,screen,&clipStartScreenB);

                //SDL_Delay(40);
                SDL_Flip(screen);
            }
            clipStartScreenN.w=385;
            clipStartScreenN.h=(int)(25.25*i);
            apply_surface(60,20,start_screen_ninja,screen,&clipStartScreenN);
            SDL_Flip(screen);
            SDL_Delay(20);
            if(i==20)
            {
                first_exec=false;
            }
        }
    }
    */
    while(!opt_selected)
    {

        while(SDL_PollEvent(&event))
		{
       		if( event.type == SDL_QUIT )
			{
				quit=true;opt_selected=true;break;
			}

			if(event.type=SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym)
				{
				    case SDLK_RETURN:opt_selected=true;break;
					case SDLK_ESCAPE: 	quit=true;opt_selected=true; break;
					case SDLK_UP :	t--;change_opt=true;break;
					case SDLK_DOWN :	t++;	change_opt=true;	break;
					default : break;

				}
			}
            else if( event.type == SDL_KEYUP )
            {
                switch( event.key.keysym.sym )
                {
                    case SDLK_RETURN:opt_selected=true;change_opt=true;break;
                    case SDLK_ESCAPE: 	quit=true;opt_selected=true; break;
					case SDLK_UP :	t--;change_opt=true;break;
					case SDLK_DOWN :	t++;	change_opt=true;	break;
					default : break;
                }
            }
             int x_coord = event.motion.x;
                int y_coord = event.motion.y;
                //printf("%d %d\n",x_coord,y_coord);
               /* if( x_coord>=590&&x_coord<=790 )
                {
                    if(y_coord>=310&&y_coord<=560)
                    {
                        if(y_coord<=370)
                        {
                            t=2;
                            change_opt=true;
                        }
                        else if(y_coord<=430)
                        {
                            t=4;
                            change_opt=true;

                        }
                        else if(y_coord<=490)
                        {
                            t=6;
                            change_opt=true;
                        }
                        else
                        {
                            t=8;
                            change_opt=true;
                        }
                    }
                }
                */
                if(x_coord>=580&&x_coord<=760&&y_coord<=390&&y_coord>=210)
                {
                    button_start=true;
                    change_opt=true;
                    if( event.button.button == SDL_BUTTON_LEFT )
                    {
                        opt_selected=true;change_opt=true;t=2;
                    }
                }
                else
                {
                    button_start=false;
                    change_opt=true;
                }
                if(x_coord>=525&&x_coord<=615&&y_coord<=520&&y_coord>=430)
                {
                    button_hs=true;
                    change_opt=true;
                    if( event.button.button == SDL_BUTTON_LEFT )
                    {
                        opt_selected=true;change_opt=true;t=4;
                    }
                }
                else
                {
                    button_hs=false;
                    change_opt=true;
                }
                if(x_coord>=635&&x_coord<=725&&y_coord<=520&&y_coord>=430)
                {
                    button_credits=true;
                    change_opt=true;
                    if( event.button.button == SDL_BUTTON_LEFT )
                    {
                        opt_selected=true;change_opt=true;t=6;
                    }
                }
                else
                {
                    button_credits=false;
                    change_opt=true;
                }
                if(x_coord>=745&&x_coord<=835&&y_coord<=520&&y_coord>=430)
                {
                    button_exit=true;
                    change_opt=true;
                    if( event.button.button == SDL_BUTTON_LEFT )
                    {
                        opt_selected=true;change_opt=true;t=8;
                    }
                }
                else
                {
                    button_exit=false;
                    change_opt=true;
                }
            //Snip 2

            if(t>8){t=2;}
            if(t<2){t=8;}
            if(change_opt)
            {
                apply_surface(0,0,start_screen_background,screen);
                apply_surface(60,20,start_screen_ninja,screen);
                if(button_start)
                {
                    apply_surface(570,200,start_button,screen);
                }
                else
                {
                    apply_surface(580,210,start_button_small,screen);
                }
                if(button_credits)
                {
                    apply_surface(630,425,start_button_bg,screen);
                }
                else
                {
                    apply_surface(635,430,start_button_bg_small,screen);
                }
                if(button_exit)
                {
                    apply_surface(740,425,start_button_bg,screen);
                }
                else
                {
                    apply_surface(745,430,start_button_bg_small,screen);
                }
                if(button_hs)
                {
                    apply_surface(520,425,start_button_bg,screen);
                }
                else
                {
                    apply_surface(525,430,start_button_bg_small,screen);
                }
                apply_surface(548,448,start_button_hs,screen);
                apply_surface(652,448,start_button_credits,screen);
                apply_surface(768,439,start_button_exit,screen);

               // apply_surface(590,310,start_screen_start,screen);
               // apply_surface(590,370,start_screen_hs,screen);
               // apply_surface(590,430,start_screen_credits,screen);
               // apply_surface(590,490,start_screen_exit,screen);
               // apply_surface(570,(246+(60*(int)(t/2))),start_screen_sel,screen);
                SDL_Flip(screen);
                change_opt=false;
            }
		}

//Snip 3


    SDL_Delay(50);
    }
    SDL_FreeSurface(start_screen_background);
    //SDL_FreeSurface(start_screen_credits);
    //SDL_FreeSurface(start_screen_sel);
    //SDL_FreeSurface(start_screen_start);
    //SDL_FreeSurface(start_screen_options);
   // SDL_FreeSurface(start_screen_exit);
    //SDL_FreeSurface(start_screen_hs);
    SDL_FreeSurface(start_screen_ninja);
    SDL_FreeSurface(start_button);
    SDL_FreeSurface(start_button_small);
    SDL_FreeSurface(start_button_bg);
    SDL_FreeSurface(start_button_bg_small);
    SDL_FreeSurface(start_button_exit);
    SDL_FreeSurface(start_button_hs);
    SDL_FreeSurface(start_button_back);
    SDL_FreeSurface(start_button_credits);
    if(quit)
        t=8;
    if(opt_selected==true)
    {
        return t;
    }
    Mix_HaltMusic();
    Mix_FreeMusic( music );
    Mix_CloseAudio();

    return 99;
}


//Snip 2

               /* if( event.button.button == SDL_BUTTON_LEFT )
                {
                    if( x_coord>=590&&x_coord<=790 )
                    {
                        if(y_coord>=310&&y_coord<=560)
                        {
                            if(y_coord<=370)
                            {
                                opt_selected=true;change_opt=true;
                            }
                            else if(y_coord<=430)
                            {
                               opt_selected=true;change_opt=true;

                            }
                            else if(y_coord<=490)
                            {
                               opt_selected=true;change_opt=true;
                            }
                            else
                            {
                                quit=true;opt_selected=true;
                            }
                        }
                    }
                }
                */

//Sinp 3
		/*if(SDL_PollEvent( &event ))
		{
		                if( event.type == SDL_MOUSEMOTION )
            {
                //Get the mouse offsets
                int x_coord = event.motion.x;
                int y_coord = event.motion.y;
                printf("%d %d\n",x_coord,y_coord);
                //If the mouse is over the button
                if( x_coord>=590&&x_coord<=790 )
                {
                    if(y_coord>=310&&y_coord<=560)
                    {
                        if(y_coord<=370)
                        {
                            t=2;
                            change_opt=true;
                        }
                        else if(y_coord<=430)
                        {
                            t=4;
                            change_opt=true;

                        }
                        else if(y_coord<=490)
                        {
                            t=6;
                            change_opt=true;
                        }
                        else
                        {
                            t=8;
                            change_opt=true;
                        }
                    }
                }
            }
            if( event.type == SDL_MOUSEBUTTONDOWN )
            {
                //If the left mouse button was pressed
                if( event.button.button == SDL_BUTTON_LEFT )
                {
                    //Get the mouse offsets
                   int x_coord = event.button.x;
                   int y_coord = event.button.y;

                   printf("%d %d\n",x_coord,y_coord);

                }
            }
		}
		*/
