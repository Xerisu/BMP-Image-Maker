#include "bitmap.h"
#include "../utils/color.h"
#include "../image/image.h"
#include <stdio.h>
#define EXPECTED_INT_SIZE 4
#define EXPECTED_SHORT_SIZE 2
#define HEADER_SIZE 14
#define DIB_HEADER_SIZE 40
#define ROW_SIZE_PADDING 4
#define CHANNELS_PER_PIXEL 3
#define PPM 5551

void save_int_to_file(FILE* file, int n) 
{
    fwrite((char*)&n, 1, EXPECTED_INT_SIZE, file);
}

void save_short_to_file(FILE* file, short n) 
{
    fwrite((char*)&n, 1, EXPECTED_SHORT_SIZE, file);
}

void save_image_to_bmp(const image* image, const char* path) 
{
    FILE* file = fopen(path, "wb");
    if (file == NULL)
    {
        perror("Failed to open file: ");
        return;
    }

    int bytes_per_row = CHANNELS_PER_PIXEL*image->size.x;
    int padding = bytes_per_row % ROW_SIZE_PADDING;
    if (padding != 0) padding = ROW_SIZE_PADDING - padding;
    int image_size_with_padding = (bytes_per_row + padding)*image->size.y;

    // Bitmap file header
    fwrite("BM", 1, 2, file);
    save_int_to_file(file, image_size_with_padding + HEADER_SIZE + DIB_HEADER_SIZE);
    save_short_to_file(file, 0);
    save_short_to_file(file, 0);
    save_int_to_file(file, HEADER_SIZE + DIB_HEADER_SIZE);

    // Bitmap dib header
    save_int_to_file(file, DIB_HEADER_SIZE);
    save_int_to_file(file, image->size.x);
    save_int_to_file(file, image->size.y);
    save_short_to_file(file, 1);
    save_short_to_file(file, CHANNELS_PER_PIXEL*8);
    save_int_to_file(file, 0);
    save_int_to_file(file, image_size_with_padding);
    save_int_to_file(file, PPM);
    save_int_to_file(file, PPM);
    save_int_to_file(file, 0);
    save_int_to_file(file, 0);

    // Actual image (pixel data)
    for (int y = image->size.y - 1; y >= 0; y--) {
        for (int x = 0; x < image->size.x; x++) {
            fputc(image->pixels[y][x].blue, file);
            fputc(image->pixels[y][x].green, file);
            fputc(image->pixels[y][x].red, file);
            
        }
        for (int i = 0; i < padding; i++) {
            fputc(0, file);
        }
    }


    fclose(file);
}