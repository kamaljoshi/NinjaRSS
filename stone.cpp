#include "functions_common.h"
#include "variables.h"
#include <ctime>


void stone_load()
{
    bool var_check=false;
    if(jump_val==1)
        not_landed=true;
    for(int i=0;i<stone_c;i++)
    {
        apply_surface( stone_coordx[i]-camera.x, stone_coordy[i], block, screen );

        //Removed Part 1

        if (level_beginx-stone_coordx[i] >=(-48) && level_beginx-stone_coordx[i] <=24)
        {
            if(level_beginy-stone_coordy[i]<=24&&level_beginy-stone_coordy[i]>=(-56))
            {
               collision_course=true;
            }
        }
       if(jump_condition&&!var_check&&!free_fall&&jump_val<=8)
       {
            if(stone_coordy[i]-level_beginy==PLAYER_HEIGHT && stone_coordx[i]-level_beginx<=PLAYER_WIDTH/2&&stone_coordx[i]-level_beginx>=((-PLAYER_WIDTH/2)+16))
            {
                printf("\nDetected : %d ",level_beginy);
                jump_condition=false;
                jump_val=0;
                var_check=true;
                not_landed=false;
            }
       }
       else if(jump_condition&&!var_check&&!free_fall&&jump_val>8)
       {
            if(stone_coordy[i]-level_beginy==(-PLAYER_HEIGHT/2) && stone_coordx[i]-level_beginx<=PLAYER_WIDTH/2&&stone_coordx[i]-level_beginx>=((-PLAYER_WIDTH/2)+16))
            {
                printf("\nCollided : %d - %d",level_beginy,jump_val);
                //jump_condition=false;
                jump_val=16-jump_val;
                //free_fall=true;
                var_check=true;
                not_landed=false;

            }
       }
       else if(!jump_condition&&!var_check)
       {
            if(stone_coordy[i]-level_beginy==PLAYER_HEIGHT && stone_coordx[i]-level_beginx<=PLAYER_WIDTH/2&&stone_coordx[i]-level_beginx>=((-PLAYER_WIDTH/2)+16))
            {
                printf("\nExecuted : %d -%d ",level_beginy,clock());
                var_check=true;
            }
       }

    }
    if(!var_check&&!jump_condition)
    {
       free_fall=true;
        printf("\nTerminated : %d -%d ",level_beginy,clock());
    }
    else
    {
        printf("\nExTerminated : %d -%d ",level_beginy,clock());
        free_fall=false;
    }
}

// Removed Part 1
/*if(((level_beginx+48)>=(stone_coordx[i]))&&((level_beginx+16)<=(stone_coordx[i]+BLOCK_SIZE_W)))
{	if(((level_beginy+48)>=stone_coordy[i])&&((level_beginy+12)<=(stone_coordy[i]+BLOCK_SIZE_H)))
    {
        jump_condition=false;
        jump_val=0;
        if(level_beginy+12>=(600-96))
        {
            level_beginy=600-96;
        }
        else if(level_beginy+12<=(600-192))
        {
            level_beginy=600-96;
        }

        printf("\nDetected");
    }

}*/
