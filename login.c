#include <stdio.h>
#include <string.h>

struct User {
    char name[8];
    int is_admin;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <name>\n", argv[0]);
        return 1;
    }

    struct User user = { .is_admin = 0 };
    strcpy(user.name, argv[1]);

    if (user.is_admin) {
        printf("Welcome, %s. You are ADMIN.\n", user.name);
    } else {
        printf("Hello, %s. You are a regular user.\n", user.name);
    }
    return 0;
}
