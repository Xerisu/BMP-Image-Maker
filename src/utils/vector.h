#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector {
    int x;
    int y;
} vector;

vector create_vector(int x, int y);

vector add_to_vector(const vector* point, int x, int y);

#endif /* VECTOR.H */