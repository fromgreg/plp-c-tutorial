#ifndef VEC_H
#define VEC_H

#include <stddef.h>

/*
 * A growable array of ints, like std::vector, ArrayList or Rust's Vec.
 *
 * data points to a heap buffer with room for cap ints, of which the first
 * len are in use. When the buffer is full, vec_push asks realloc for a bigger
 * one. realloc may MOVE the buffer to a new address and free the old one.
 */
typedef struct {
    int *data;
    size_t len;
    size_t cap;
} Vec;

void vec_init(Vec *v);
void vec_push(Vec *v, int value);
int vec_remove(Vec *v, size_t index);
void vec_print(const Vec *v);
void vec_free(Vec *v);

#endif
