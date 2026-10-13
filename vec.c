#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vec.h"

#define INITIAL_CAP 4

/* Starts with an empty buffer for INITIAL_CAP ints. Exits if out of memory. */
void vec_init(Vec *v) {
    v->data = malloc(INITIAL_CAP * sizeof *v->data);
    if (v->data == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    v->len = 0;
    v->cap = INITIAL_CAP;
}

/* Appends value. Doubles the capacity when the buffer is full. */
void vec_push(Vec *v, int value) {
    if (v->len == v->cap) {
        size_t new_cap = v->cap * 2;
        int *new_data = realloc(v->data, new_cap * sizeof *new_data);
        if (new_data == NULL) {
            fprintf(stderr, "Out of memory\n");
            exit(1);
        }
        /* From here on, the old v->data may already be freed! */
        v->data = new_data;
        v->cap = new_cap;
    }
    v->data[v->len++] = value;
}

/*
 * Removes the element at index and shifts all later elements one to the left.
 * Returns 1 on success, 0 if index is out of range.
 */
int vec_remove(Vec *v, size_t index) {
    /* TODO 3: implement me (bounds check + memmove) */
    (void)v;
    (void)index;
    return 0;
}

/* Prints all elements as [a, b, c]. */
void vec_print(const Vec *v) {
    printf("[");
    for (size_t i = 0; i < v->len; i++) {
        printf(i == 0 ? "%d" : ", %d", v->data[i]);
    }
    printf("]\n");
}

/* Frees the buffer. v must be initialised again before it is used. */
void vec_free(Vec *v) {
    free(v->data);
    v->data = NULL;
    v->len = 0;
    v->cap = 0;
}
