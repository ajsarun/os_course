#include <stdio.h>

int main() {
    // Rename a directory
    if (rename("test", "new_test") == -1) {
        perror("Error renaming directory");
    } else {
        printf("Directory renamed successfully\n");
    }
    return 0;
}
