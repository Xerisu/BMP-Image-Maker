#include "color.h"

color create_color(unsigned char red, unsigned char green, unsigned char blue) {
    color my_color;
    my_color.red = red;
    my_color.green = green;
    my_color.blue = blue;
    return my_color;
}

// basic colors
const color red = {.red = 255, .green = 0, .blue = 0};
const color green = {.red = 0, .green = 255, .blue = 0};
const color blue = {.red = 0, .green = 255, .blue = 0};
const color black = {.red = 0, .green = 0, .blue = 0};
const color white  = {.red = 255, .green = 255, .blue = 255};
const color yellow  = {.red = 255, .green = 255, .blue = 0};
const color magenta = {.red = 255, .green = 0, .blue = 255};
const color cyan = {.red = 0, .green = 255, .blue = 255};
const color brown = {.red = 150, .green = 75, .blue = 0};
const color grey = {.red = 128, .green = 128, .blue = 128}; 

// cooler colors
const color mint = {.red = 170, .green = 240, .blue = 209};
const color violet = {.red = 158, .green = 82, .blue = 252};
const color pink = {.red = 252, .green = 82, .blue = 222}; 
const color orange = {.red = 255, .green = 128, .blue = 0};
const color turquoise = {.red = 48, .green = 213, .blue = 200};
