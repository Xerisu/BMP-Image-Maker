#ifndef COLOR_H
#define COLOR_H


typedef struct color {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} color;

extern const color red;
extern const color green;
extern const color blue;
extern const color black;
extern const color white;
extern const color yellow;
extern const color magenta;
extern const color cyan;
extern const color mint;
extern const color violet;
extern const color pink;
extern const color orange;
extern const color turquoise;
extern const color brown;
extern const color grey;

color create_color(unsigned char red, unsigned char green, unsigned char blue);

#endif