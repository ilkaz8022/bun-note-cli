#ifndef INIT_DIR_FILE_H
#define INIT_DIR_FILE_H

#include <unistd.h>
#include <stdio.h>

typedef struct Result {
    char* path;
    const char* NAME;
    int handle;
} BINIT;

BINIT* getCurrentDirectory();
int changeCurrentDirectory(const char* PATH);
static void createDirectories();
static void createFiles();
int initalDirectory();

#endif 
