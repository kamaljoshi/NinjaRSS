#ifndef FUNCTIONS_COMMON_H
#define FUNCTIONS_COMMON_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

//File Loader
SDL_Surface *load_image( std::string filename );

//Surface blitter
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL );

//Initialization
bool init(char *argv);

//File loading
bool load_files();

//Clean up
void clean_up();

#endif
