#include <stdio.h>
#include <unistd.h>  // For POSIX `rmdir()`

int main() {
    // Remove an empty directory
    if (rmdir("test") == -1) {
        perror("Error deleting directory");
    } else {
        printf("Directory deleted successfully\n");
    }
    return 0;
}
