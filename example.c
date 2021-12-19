/* File:    example.c
   Author:  Roland Weir-Howell (r.weirhowell@gmail.com)
   Desc:    Example file to demonstrate usage of colour.h (ccolour)
   License: MIT License (../LICENSE)
*/

#include "colour.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>


void rainbow()
{
    const char COLOURS[8][7] =
    { "BLACK", "RED", "GREEN", "YELLOW", "BLUE", "PURPLE", "CYAN", "WHITE" };

    for (int fg = 0; fg < 8; fg++)
    {
        for (int bg = 0; bg < 8; bg++)
        {
            char msg[18];
            snprintf(msg, 18, "%s ON %s\n", COLOURS[fg], COLOURS[bg]);

            ChangeColour(msg, bg + 40, fg + 30, true);
        }
    }
}


int main()
{
    ChangeColour(
        "ERROR: This is a big scary error\n",
        RED_FOREGROUND,
        DEFAULT_COLOR,
        true
    );

    ChangeColour(
        "Yellow warning text\n",
        YELLOW_FOREGROUND,
        DEFAULT_COLOR,
        true
    );

    ChangeColour(
        "White text on blue background\n",
        WHITE_FOREGROUND,
        BLUE_BACKGROUND,
        true
    );

    char choice[16];
    printf("Are you ready for the rainbow? [HELL YEAH / NO IM SCARED]\n");
    fgets(choice, 16, stdin);

    // strcmp returns false (0) when a match IS found
    if (!strcmp(choice, "HELL YEAH\n"))
    {
        rainbow();
    }
    else if (!strcmp(choice, "NO IM SCARED\n"))
    {
        ChangeColour("YOU COWARD\n", RED_FOREGROUND, DEFAULT_COLOR, true);
    }

    return 0;
}
