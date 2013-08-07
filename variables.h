#ifndef VARIABLES_H
#define VARIABLES_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"


#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600
#define SCREEN_BPP 32
#define BLOCK_SIZE_H 32
#define BLOCK_SIZE_W 40
#define PLAYER_WIDTH 64
#define PLAYER_HEIGHT 64
#define PLAYER_DIM_X1 16
#define PLAYER_DIM_X2 48

extern const int PLAYER_RIGHT;
extern const int PLAYER_LEFT;
extern const int FRAMES_PER_SECOND;

extern SDL_Surface *Player_r ,*Player_l,*Player_jr,*Player_jl,*Player_idler,*Player_idlel;
extern SDL_Surface *Enemy_r,*Enemy_l,*Enemy_jr,*Enemy_jl,*Enemy_idler,*Enemy_idlel;
extern SDL_Surface *EnemyA_r,*EnemyA_l,*EnemyA_jr,*EnemyA_jl,*EnemyA_idler,*EnemyA_idlel;
extern SDL_Surface* screen;
extern SDL_Surface* background1,*background2,*background3,*background0;
extern SDL_Surface* block,*diamond,*diamond2,*exitsign,*shuriken,*health_bar,*health_barv;
extern SDL_Surface* message ,*upMessage, *downMessage, *leftMessage, *rightMessage;
extern SDL_Surface* overlay_die,*overlay_lose,*overlay_win;
extern SDL_Surface* weapon_blue;
extern SDL_Event event;

extern SDL_Rect clip[4];
extern SDL_Rect clipsWalkRight[ 10 ];
extern SDL_Rect clipsWalkLeft[ 10 ];
extern SDL_Rect clipsJumpRight[ 12 ];
extern SDL_Rect clipsJumpLeft[ 12 ];
extern SDL_Rect clipsStanceRight[ 10 ];
extern SDL_Rect clipsStanceLeft[ 10 ];
extern SDL_Rect clipsEWalkRight[ 10 ];
extern SDL_Rect clipsEWalkLeft[ 10 ];
extern SDL_Rect camera;
extern SDL_Rect camera1;
extern SDL_Rect camera2;

extern TTF_Font *font;

extern SDL_Color textColor;

extern int level_no;
extern int stone_coordx[1000],stone_coordy[1000],stone_c;
extern int diamond_coordx[1000],diamond_coordy[1000],diamond_c,diamond_mov[1000];
extern int diamond2_coordx[1000],diamond2_coordy[1000],diamond2_c,diamond2_mov[1000];
extern int enemy_coordx[1000],enemy_coordy[1000],enemy_c;
extern int enemy2_coordx[1000],enemy2_coordy[1000],enemy2_c;
extern int weapon_blue_coordx[10],weapon_blue_coordy[10],weapon_blue_active[10],weapon_blue_c[10],weapon_blue_o[10];
extern int level_beginx,level_beginy;
extern int level_endx,level_endy;
extern int jump_val;
extern int score;

extern char level_info[2][240][300];

extern bool quit;
extern bool diamond_visible[1000],diamond2_visible[1000];
extern bool jump_condition;
extern bool free_fall;
extern bool not_landed;
extern bool collision_course;
extern bool shuriken_fire;
extern bool first_exec;
extern bool game_lost;
extern bool sad_tune;

extern Uint8 *keystates;

extern char scoreboard[100];

#endif
