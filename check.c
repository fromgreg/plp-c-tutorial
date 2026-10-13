#include <stdio.h>
#include <stdlib.h>

/*
 * Setup check. Prints a message, then writes one int past the end of a heap
 * buffer. The plain build does not notice. The ASan build must stop with a
 * heap-buffer-overflow report, which proves that AddressSanitizer works.
 */
int main(void) {
    printf("Compiler works.\n");

    int *probe = malloc(4 * sizeof *probe);
    if (probe == NULL) {
        return 1;
    }
    probe[4] = 1;
    free(probe);
    return 0;
}
