/*#ifndef TEXT_INPUT_H
#define TEXT_INPUT_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "functions_common.h"
#include "variables.h"


class StringInput
{
    private:
    //The storage string
    std::string str;

    //The text surface
    SDL_Surface *text;

    public:
    //Initializes variables
    StringInput();

    //Does clean up
    ~StringInput();

    //Handles input
    void handle_input();

    //Shows the message on screen
    void show_centered();
};

#endif
*/
