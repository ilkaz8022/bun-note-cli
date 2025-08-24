#ifndef INIT
#define INIT

#include <unistd.h>
#include <stdio.h>

typedef struct Result {
    char* path;
    const char* NAME;
    int handle;
} BINIT;

BINIT* getCurrentDirectory(void);
int changeCurrentDirectory(const char* PATH);
static void createDirectories(void);
void createFile(void);
int initalDirectory(void);

#endif 
