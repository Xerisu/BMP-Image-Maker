#include "image/image.h"
#include "utils/vector.h"
#include <stdio.h>
#include "bitmap/bitmap.h"

/* void print_image(image* image) {
    for(int y = 0; y < image->size.y; y++) {
        for (int x = 0; x < image->size.x; x++) {
            unsigned int sum = image->pixels[y][x].red;            
            if (sum == 0) putchar(' ');
            else putchar('#');
        }
        putchar('\n');
    }
} */

int main() {
    image whiteboard = create_image(create_vector(800,600), white);
    draw_circle(&whiteboard, 40, create_vector(400,300), 5, magenta);
    //draw_point(&whiteboard, create_vector(6,6), 1, create_color(0,0,0));
    //draw_point(&whiteboard, create_vector(10,10), 6, create_color(0,0,0));
    //print_image(&whiteboard);
    save_image_to_bmp(&whiteboard, "bin/image.bmp");
    free_image(&whiteboard); 
    
}
