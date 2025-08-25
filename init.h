#ifndef INIT
#define INIT

#define MAIN_DIRECTORY  ".bnote/"
#define LOGS_DIRECTORY  ".bnote/logs"
#define NOTES_DIRECTORY ".bnote/notes"

#include <unistd.h>
#include <stdio.h>

typedef struct Result {
    char* path;
} BINIT;

BINIT* getCurrentDirectory(void);
int changeCurrentDirectory(const char* path);
static int createDirectories(void);
int b_init(void);

#endif 
