#include "vector.h"

vector create_vector(int x, int y) {
    vector my_vector;
    my_vector.x = x;
    my_vector.y = y;
    return my_vector;
}

vector add_to_vector(const vector* point, int x, int y) {
    vector my_vector;
    my_vector.x = x + point->x;
    my_vector.y = y + point->y;
    return my_vector;
}