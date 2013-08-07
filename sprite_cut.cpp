#include "sprite_cut.h"
#include "variables.h"

void set_clips()
{
    //for Naruto
//check other main.cpp

	//for Indiana Jones
	for(int i=0;i<6;i++)
    {
		clipsWalkRight[ i ].x = PLAYER_WIDTH * i;
		clipsWalkRight[ i ].y = 0;
		clipsWalkRight[ i ].w = PLAYER_WIDTH;
		clipsWalkRight[ i ].h = PLAYER_HEIGHT;

		clipsWalkLeft[ i ].x = PLAYER_WIDTH * i;
		clipsWalkLeft[ i ].y = 0;
		clipsWalkLeft[ i ].w = PLAYER_WIDTH;
		clipsWalkLeft[ i ].h = PLAYER_HEIGHT;
	}

	for(int i=0;i<5;i++)
    {
		clipsJumpRight[ i ].x = PLAYER_WIDTH * i;
		clipsJumpRight[ i ].y = 0;
		clipsJumpRight[ i ].w = PLAYER_WIDTH;
		clipsJumpRight[ i ].h = PLAYER_HEIGHT;

		clipsJumpLeft[ i ].x = PLAYER_WIDTH * i;
		clipsJumpLeft[ i ].y = 0;
		clipsJumpLeft[ i ].w = PLAYER_WIDTH;
		clipsJumpLeft[ i ].h = PLAYER_HEIGHT;
	}

	for(int i=0;i<6;i++)
    {
        clipsStanceRight[ i ].x = PLAYER_WIDTH * i;
        clipsStanceRight[ i ].y = 0;
        clipsStanceRight[ i ].w = PLAYER_WIDTH;
        clipsStanceRight[ i ].h = PLAYER_HEIGHT;

		clipsStanceLeft[ i ].x = PLAYER_WIDTH * i;
		clipsStanceLeft[ i ].y = 0;
		clipsStanceLeft[ i ].w = PLAYER_WIDTH;
		clipsStanceLeft[ i ].h = PLAYER_HEIGHT;
	}

    for(int i=0;i<10;i++)
    {
		clipsEWalkRight[ i ].x = PLAYER_WIDTH * i;
		clipsEWalkRight[ i ].y = 0;
		clipsEWalkRight[ i ].w = PLAYER_WIDTH;
		clipsEWalkRight[ i ].h = PLAYER_HEIGHT;

		clipsEWalkLeft[ i ].x = PLAYER_WIDTH * i;
		clipsEWalkLeft[ i ].y = 0;
		clipsEWalkLeft[ i ].w = PLAYER_WIDTH;
		clipsEWalkLeft[ i ].h = PLAYER_HEIGHT;
	}

}
