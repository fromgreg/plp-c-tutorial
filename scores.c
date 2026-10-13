#include <stdio.h>

#include "vec.h"

/*
 * A tiny high-score table.
 *
 * TODO 1: Run both builds and compare:
 *             make && ./build/scores && ./build/scores-asan
 *         Can you trust the plain output? What does ASan say?
 * TODO 2: Fix the bug without removing the "leader" output.
 * TODO 3: Implement vec_remove in vec.c, then uncomment the block below.
 */
int main(void) {
    Vec scores;
    vec_init(&scores);

    vec_push(&scores, 42);
    vec_push(&scores, 17);
    vec_push(&scores, 99);

    /* Remember where the leader is stored, so we can show it later. */
    int *leader = &scores.data[2];
    printf("Leader: %d\n", *leader);

    /* Two more players join. */
    vec_push(&scores, 5);
    vec_push(&scores, 63);

    printf("Scores: ");
    vec_print(&scores);
    printf("Leader is still: %d\n", *leader);

    /*
    printf("Player 1 leaves.\n");
    if (!vec_remove(&scores, 1)) {
        fprintf(stderr, "Could not remove player 1\n");
    }
    printf("Scores: ");
    vec_print(&scores);
    */

    vec_free(&scores);
    return 0;
}
