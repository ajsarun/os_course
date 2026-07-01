#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
    // Create a directory with read/write/execute permissions for the owner
    if (mkdir("test", 0755) == -1) {
        perror("Error creating directory");
    } else {
        printf("Directory created successfully\n");
    }
    return 0;
}
