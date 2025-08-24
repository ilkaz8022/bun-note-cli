#ifndef INIT
#define INIT

#include <unistd.h>
#include <stdio.h>

typedef struct Result {
    char* path;
} BINIT;

BINIT* getCurrentDirectory(void);
int changeCurrentDirectory(const char* PATH);
static void createDirectories(void);
int b_init(void);

#endif 
