#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include <string>
#include "functions_common.h"
#include "variables.h"

SDL_Surface *load_image(std::string filename)
{
	//SDL_Surface* loadedImage=NULL;
	SDL_Surface* optimizedImage = NULL;
	optimizedImage=IMG_Load(filename.c_str());
	/*if( loadedImage != NULL )
	{
		optimizedImage=SDL_DisplayFormat( loadedImage );
		SDL_FreeSurface( loadedImage );
	}


	if(optimizedImage !=NULL)
	{
		Uint32 colorkey=SDL_MapRGB(optimizedImage->format,0,0xFF, 0xFF);
		SDL_SetColorKey(optimizedImage,SDL_SRCCOLORKEY,colorkey);
	}*/

	return optimizedImage;
}

void apply_surface(int x,int y,SDL_Surface* source,SDL_Surface* destination, SDL_Rect* clip)
{
	SDL_Rect offset;

	offset.x=x;
	offset.y=y;

	SDL_BlitSurface(source,clip,destination,&offset);
}

bool init(char *argv)
{
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		return false;
	}

	if( TTF_Init() == -1 )
	{
		return false;
	}
    if(argv[0]=='f')
    {
        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT ,SCREEN_BPP,SDL_FULLSCREEN);
    }
    else
    {
        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT ,SCREEN_BPP,SDL_SWSURFACE);
    }


	if( screen == NULL ) { return false; }



	SDL_WM_SetCaption( "Ninja Platformer v0.1", NULL );

	return true;
}

bool load_files()
{
	switch(level_no)
	{
	case 1:
		background0=load_image("Content/Backgrounds/beta1_0.png");
		background1=load_image("Content/Backgrounds/beta1_1.png");
		background2=load_image("Content/Backgrounds/beta1_2.png");
		block=load_image("Content/Tiles/BlockB0.png");
		break;
	case 2:
        background0=load_image("Content/Backgrounds/beta1_0.png");
		background1=load_image("Content/Backgrounds/beta1_1.png");
		background2=load_image("Content/Backgrounds/gameplayBG.png");
		block=load_image("Content/Tiles/BlockA4.png");
		break;
	case 3:
        background0=load_image("Content/Backgrounds/beta1_0.png");
		background1=load_image("Content/Backgrounds/beta1_1.png");
		background2=load_image("Content/Backgrounds/beta1_2.png");
		block=load_image("Content/Tiles/Platform.png");
		break;
	}
    diamond=load_image("Content/Sprites/Gem.png");
    diamond2=load_image("Content/Sprites/Gem2.png");
    exitsign=load_image("Content/Tiles/Exit.png");
	Player_r= load_image("Content/Sprites/Player/NARUTO_WALK_R.png");
	Player_l= load_image("Content/Sprites/Player/NARUTO_WALK_L.png");
	Player_jr= load_image("Content/Sprites/Player/NARUTO_JUMP_R.png");
	Player_jl= load_image("Content/Sprites/Player/NARUTO_JUMP_L.png");
    Player_idler=load_image("Content/Sprites/Player/Naruto_Stance_R.png");
    Player_idlel=load_image("Content/Sprites/Player/Naruto_Stance_L.png");
    Enemy_r= load_image("Content/Sprites/MonsterD/ENEMY_WALK_R.png");
	Enemy_l= load_image("Content/Sprites/MonsterD/ENEMY_WALK_L.png");
    EnemyA_r= load_image("Content/Sprites/MonsterB/ENEMY_WALK_R.png");
	EnemyA_l= load_image("Content/Sprites/MonsterB/ENEMY_WALK_L.png");
	//Enemy_jr= load_image("Content/Sprites/MonsterD/NARUTO_JUMP_R.png");
	//Enemy_jl= load_image("Content/Sprites/MonsterD/NARUTO_JUMP_L.png");
    Enemy_idler=load_image("Content/Sprites/MonsterD/Idle.png");
    Enemy_idlel=load_image("Content/Sprites/MonsterD/Idle.png");
	//Player_r= load_image("Content/Sprites/Player/Runr.png");
	//Player_l= load_image("Content/Sprites/Player/Runl.png");
	//Player_jr= load_image("Content/Sprites/Player/Jumpr.png");
	//Player_jl= load_image("Content/Sprites/Player/Jumpl.png");
	font =TTF_OpenFont("Content/Fonts/njnaruto.ttf",28);
    health_bar=load_image("Content/Sprites/Extra/healthl.png");
    health_barv=load_image("Content/Sprites/Extra/bleed.png");
    overlay_die=load_image("Content/Overlays/you_died.png");
    overlay_win=load_image("Content/Overlays/you_win.png");
    overlay_lose=load_image("Content/Overlays/you_lose.png");
    weapon_blue=load_image("Content/Weapons/kitumoshi.png");
	char buffer_read_char;
	FILE *ifile;
	enemy_c=0;
	diamond_c=0;
	stone_c=0;
	diamond2_c=0;
	enemy2_c=0;
	switch(level_no)
    {
        case 1: ifile=fopen("Content/Levels/l0.txt","r");break;
        case 2: ifile=fopen("Content/Levels/l1.txt","r");break;
        case 3: ifile=fopen("Content/Levels/l2.txt","r");break;
        default: break;
    }
    for(int j=0;j<18;j++)
    {
        for(int k=0;k<301;k++)
        {
            fscanf(ifile,"%c",&buffer_read_char);
            switch(buffer_read_char)
            {
                case 'G' : 	diamond_coordy[diamond_c]=j*32+24;
                            diamond_coordx[diamond_c]=k*40;
                            diamond_visible[diamond_c]=true;
                            diamond_c++;
                            break;
                case 'H' : 	diamond2_coordy[diamond2_c]=j*32+24;
                            diamond2_coordx[diamond2_c]=k*40;
                            diamond2_visible[diamond2_c]=true;
                            diamond2_c++;
                            break;
                case '#' : 	stone_coordy[stone_c]=j*32+24;
                            stone_coordx[stone_c]=k*40;
                            stone_c++;
                            break;
                case '1' :	level_beginy=j*32-8;
                            level_beginx=k*40-12;
                            break;
                case 'X' :	level_endy=j*32+24;
                            level_endx=k*40;
                            break;
                case 'E' :  enemy_coordy[enemy_c]=j*32-8;
                            enemy_coordx[enemy_c]=k*40-12;
                            enemy_c++;
                            break;
                case 'D' :  enemy2_coordy[enemy2_c]=j*32-8;
                            enemy2_coordx[enemy2_c]=k*40-12;
                            enemy2_c++;
                            break;
                default :	break;
            }
            //printf("%c",buffer_read_char);
        }
    }
    fclose(ifile);


	return true;
}

void clean_up()
{
	SDL_FreeSurface( Player_r );
	SDL_FreeSurface( Player_l );
	SDL_FreeSurface( Player_jr );
	SDL_FreeSurface( Player_jl );
	SDL_FreeSurface( Player_idler );
	SDL_FreeSurface( Player_idlel );
    SDL_FreeSurface( Enemy_r );
	SDL_FreeSurface( Enemy_l );
    SDL_FreeSurface( Enemy_idler );
	SDL_FreeSurface( Enemy_idlel );
    SDL_FreeSurface( EnemyA_r );
	SDL_FreeSurface( EnemyA_l );
	SDL_FreeSurface(background0);
	SDL_FreeSurface(background1);
	SDL_FreeSurface(background2);
	SDL_FreeSurface( diamond );
	SDL_FreeSurface( diamond2 );
	SDL_FreeSurface( block );
	SDL_FreeSurface( exitsign );
	SDL_FreeSurface( overlay_die );
	SDL_FreeSurface( overlay_win );
	SDL_FreeSurface( overlay_lose );
	SDL_FreeSurface( weapon_blue );
	SDL_Quit();
}