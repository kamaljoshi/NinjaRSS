#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "functions_common.h"
#include "variables.h"
#include "main_player.h"



Player::Player()
{
    offSet = 0;
    velocity = 0;
    health=30;
    frame = 0;
    frame_idle=0;
    idle_cond=true;
    status = PLAYER_RIGHT;
    for(int i=0;i<5;i++)
    {
        weapon_blue_active[i]=0;
    }
}

bool move_left_right=true;

void Player::handle_events()
{
    if( event.type == SDL_KEYDOWN )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: velocity += PLAYER_WIDTH / 4; break;
            case SDLK_LEFT: velocity -= PLAYER_WIDTH / 4; break;
            case SDLK_SPACE: if(!jump_condition&&!not_landed&&!free_fall)
            				{
            					jump_condition=true;
            					jump_val=16;
            				}
            				break;
            case SDLK_UP: if(!jump_condition&&!not_landed&&!free_fall)
            				{
            					jump_condition=true;
            					jump_val=16;
            				}
            				break;
            case SDLK_x: fire();
                        //shuriken_fire=true;
                        break;
            default : break;
        }
    }
    else if( event.type == SDL_KEYUP )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: velocity -= PLAYER_WIDTH / 4; break;
            case SDLK_LEFT: velocity += PLAYER_WIDTH / 4; break;
            case SDLK_SPACE: if(!jump_condition&&!not_landed&&!free_fall)
            				{
            					jump_condition=true;
            					jump_val=16;
            				}
            case SDLK_UP: if(!jump_condition&&!not_landed&&!free_fall)
            				{
            					jump_condition=true;
            					jump_val=16;
            				}
            				break;
            default : break;
        }
    }
if(not_landed)
{
    not_landed=false;
}
}

void Player::move(int health_t1,int health_t2)
{
    int health_t=health_t1+health_t2;
    if(!collision_course)
    {
        offSet += velocity;
    }
    else
    {
        collision_course=false;
    }

    if( ( offSet < 0 ) || ( offSet + PLAYER_WIDTH > SCREEN_WIDTH*12 ) )
    {
        offSet -= velocity;
    }


    if(!free_fall)
    {
        if(jump_condition&&jump_val)
        {
            if(jump_val>8)
            {
                level_beginy-=16;
            }
            else
            {
                level_beginy +=16;
            }

            jump_val--;
        }

        if(!jump_val)
        {
            jump_condition=false;
        }
    }
    else
    {
        level_beginy+=16;
        jump_condition=false;
        jump_val=0;
        if(level_beginy>=600)
        {
            health=0;
        }
    }


    if(health_t)
    {
        health-=health_t;
        printf("Weak\n");
    }


    for(int i=0;i<5;i++)
    {
        if(weapon_blue_active[i]==1)
        {
           if(weapon_blue_coordx[i]-camera.x<=0||weapon_blue_coordx[i]-camera.x>=1000)
            {
                 weapon_blue_active[i]=0;
            }
            else
            {
                if(weapon_blue_o[i]==0)
                    weapon_blue_coordx[i]+=30;
                else
                    weapon_blue_coordx[i]-=30;
            }
        }
    }
}

void Player::show()
{
    if(level_beginx+32-camera.x>750)
    {
        camera.x = ( level_beginx + 32 ) - 750;
    }
    if(level_beginx+32-camera.x<150)
    {
        camera.x = ( level_beginx + 32 ) - 150;
    }

    if( camera.x < 0 )
    {
        camera.x = 0;
    }

    if( camera.x > SCREEN_WIDTH*12 - camera.w )
    {
        camera.x = SCREEN_WIDTH*12 - camera.w;
    }
    camera1.x=camera.x/2;
    camera2.x=camera.x/4;
    if( velocity < 0 )
    {
         status = PLAYER_LEFT;
        idle_cond=false;
        frame++;
    }
    else if( velocity > 0 )
    {
        status = PLAYER_RIGHT;
        idle_cond=false;
        frame++;
    }
    else
    {
        frame = 0;
        idle_cond=true;
    }

    if( frame >= 6 )
    {
        frame = 0;
    }

    if(idle_cond&&!jump_condition)
    {
        frame_idle++;
        if(frame_idle>=6)
        {
            frame_idle=0;
        }
        if( status == PLAYER_RIGHT )
        {
            apply_surface( offSet-camera.x, level_beginy, Player_idler, screen, &clipsStanceRight[frame_idle ] );
        }
        else
        {
            apply_surface( offSet-camera.x, level_beginy, Player_idlel, screen, &clipsStanceLeft[ frame_idle ] );
        }
    }
    /*else if(free_fall)
    {
        apply_surface( offSet-camera.x, level_beginy, Player_jr, screen, &clipsJumpRight[ 4 ] );
    }*/
    else
    {
        if( status == PLAYER_RIGHT )
        {
            if(!jump_condition)
            {
                apply_surface( offSet-camera.x, level_beginy, Player_r, screen, &clipsWalkRight[ frame ] );
            }
            else
            {
                apply_surface( offSet-camera.x, level_beginy, Player_jr, screen, &clipsJumpRight[ (15-jump_val)/3] );
            }
        }
        else if( status == PLAYER_LEFT )
        {
            if(!jump_condition)
            {
                apply_surface( offSet-camera.x, level_beginy, Player_l, screen, &clipsWalkLeft[ frame ] );
            }
            else
            {
                apply_surface( offSet-camera.x, level_beginy, Player_jl, screen, &clipsJumpLeft[ (15-jump_val)/3 ] );
            }
        }
    }

    for(int i=0;i<5;i++)
    {
        if(weapon_blue_active[i]==1)
        {
            apply_surface( weapon_blue_coordx[i]-camera.x, weapon_blue_coordy[i], weapon_blue, screen);
        }
    }

    apply_surface( 10, 10, health_bar, screen);

    for(int i=0;i<health&&i>=0;i++)
    {
        apply_surface( 20+(6*i), 14, health_barv, screen);
    }
  	level_beginx=offSet;
}

void Player::fire()
{
    for(int i=0;i<5;i++)
    {
        if(weapon_blue_active[i]==0)
        {
            weapon_blue_active[i]=1;
            weapon_blue_c[i]=30;
            weapon_blue_coordx[i]=level_beginx+32;
            weapon_blue_coordy[i]=level_beginy+16;
            weapon_blue_o[i]=status;
            fprintf(stderr,"NW : %d - %d - %d\n",camera.x,weapon_blue_coordx[i],offSet);
            break;
        }
    }
}

