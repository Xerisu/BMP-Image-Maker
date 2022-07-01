#include "image.h"
#include "../utils/color.h"
#include "../utils/vector.h"
#include <stdlib.h>
#include <math.h>

#define SQUARE(x) ((x)*(x))

void draw_point_on_every_circles_octant(image* image, vector circle_center, vector second_octant_point, int thickness, color color) {
    vector first_octant = add_to_vector(&circle_center, second_octant_point.y, second_octant_point.x);
    vector second_octant = add_to_vector(&circle_center, second_octant_point.x, second_octant_point.y);
    vector third_octant = add_to_vector(&circle_center, -second_octant_point.x, second_octant_point.y);
    vector fourth_octant = add_to_vector(&circle_center, -second_octant_point.y, second_octant_point.x);
    vector fifth_octant = add_to_vector(&circle_center, -second_octant_point.y, -second_octant_point.x);
    vector sixth_octant = add_to_vector(&circle_center, -second_octant_point.x, -second_octant_point.y);
    vector seventh_octant = add_to_vector(&circle_center, second_octant_point.x, -second_octant_point.y);
    vector eigth_octant = add_to_vector(&circle_center, second_octant_point.y, -second_octant_point.x);
    draw_point(image, first_octant, thickness, color);
    draw_point(image, second_octant, thickness, color);
    draw_point(image, third_octant, thickness, color);
    draw_point(image, fourth_octant, thickness, color);
    draw_point(image, fifth_octant, thickness, color);
    draw_point(image, sixth_octant, thickness, color);
    draw_point(image, seventh_octant, thickness, color);
    draw_point(image, eigth_octant, thickness, color);
}

image create_image(vector size, color base_color) 
{  
    image my_image;
    
    if (size.x < 1) {
        size.x = 1;
    }
    if (size.y < 1) {
        size.y = 1;
    }

    my_image.pixels = (color**)malloc(size.y*sizeof(color*));
    for (int y = 0; y < size.y; y++) {
        my_image.pixels[y] = (color*)malloc(size.x*sizeof(color));
        for (int x = 0; x < size.x; x++) {
            my_image.pixels[y][x] = base_color;
        }
    }

    my_image.size = size;

    return my_image;
}

void draw_point(image* image, vector center, int thickness, color color) {
    if (thickness < 0) 
        thickness = 1;

    if (thickness%2 == 0) thickness += 1;
    for (int y = center.y - thickness/2; y <= center.y + thickness/2; y++) {
        for (int x = center.x - thickness/2; x <= center.x + thickness/2; x++) {
            if (x < 0 || y < 0) continue;
            if (x >= image->size.x || y >= image->size.y) continue;
            image->pixels[y][x] = color;
        }
    }
}

void draw_circle(image* image, unsigned int radius, vector center, int thickness, color color) {
    /* for(int y = 0; y < image->size.y; y++) {
        for(int x = 0; x < image->size.x; x++) {
            unsigned int distance = abs(SQUARE(x - center.x) + SQUARE(y - center.y) - SQUARE(radius));
            if (distance <= thickness) {
                image->pixels[y][x] = color;
            }
        }
    } */
    int dE = 3;
    int dSE = 5 - 2 * radius;
    int d = 1 - radius;
    int x = 0;
    int y = radius;
    // Alternative midpoint algorithm

    draw_point_on_every_circles_octant(image, center, create_vector(x,y), thickness, color);
    while (y > x)
    {
        if (d < 0) //Move to E
        {
            d += dE;
            dE += 2;
            dSE += 2;
        }
        else //Move to SE
        {
            d += dSE;
            dE += 2;
            dSE += 4;
            y--;
        }
        x++;
        draw_point_on_every_circles_octant(image, center, create_vector(x,y), thickness, color);
    }
}

void free_image(image* image) { 
    for (int y = 0; y < image->size.y; y++) {
        free(image->pixels[y]);
    }
    free(image->pixels);
    image->size.x = -1;
    image->size.y = -1;
}