#include "functions_common.h"
#include "variables.h"

void diamond_load()
{
    for(int i=0;i<diamond_c;i++)
    {
        if(diamond_visible[i])
        {
            if (level_beginx +48>=diamond_coordx[i] && level_beginx +16<=diamond_coordx[i]+32)
            {
                if(level_beginy+8<=diamond_coordy[i]+32&&level_beginy+56>=diamond_coordy[i])
                {
                    score+=10;
                    diamond_visible[i]=false;
                }
            }
        }

        if(diamond_visible[i])
            apply_surface( diamond_coordx[i]+4-camera.x, diamond_coordy[i], diamond, screen );
    }
    for(int i=0;i<diamond2_c;i++)
    {
        if(diamond2_visible[i])
        {
            if (level_beginx +48>=diamond2_coordx[i] && level_beginx +16<=diamond2_coordx[i]+32)
            {
                if(level_beginy+8<=diamond2_coordy[i]+32&&level_beginy+56>=diamond2_coordy[i])
                {
                    score+=20;
                    diamond2_visible[i]=false;
                }
            }
        }

        if(diamond2_visible[i])
            apply_surface( diamond2_coordx[i]+4-camera.x, diamond2_coordy[i], diamond2, screen );
    }
}
