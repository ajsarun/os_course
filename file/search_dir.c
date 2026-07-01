#include <stdio.h>
#include <dirent.h>  // For `opendir()`, `readdir()`, `closedir()`
#include <string.h>

void search_directory(const char *dir_name, const char *target) {
    DIR *dir;
    struct dirent *entry;

    // Open the directory
    if ((dir = opendir(dir_name)) == NULL) {
        perror("Error opening directory");
        return;
    }

    // Read the entries in the directory
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Skip the "." and ".." directories
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            // Recursively search in subdirectories
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
            search_directory(path, target);
        } else if (strcmp(entry->d_name, target) == 0) {
            printf("Found: %s/%s\n", dir_name, entry->d_name);
        }
    }

    closedir(dir);
}

int main() {
    // Start search in current directory for "target_file"
    search_directory(".", "test.txt");
    return 0;
}
