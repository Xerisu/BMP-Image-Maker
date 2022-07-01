#ifndef IMAGE_H
#define IMAGE_H

#include "../utils/color.h"
#include "../utils/vector.h"

typedef struct image {
    color** pixels;
    vector size;

} image;

image create_image(vector size, color base_color);

void draw_point(image* image, vector center, int thickness, color color);

void draw_circle(image* image, unsigned int radius, vector center, int thickness, color color);

void free_image(image* image);

#endif /* IMAGE_H */