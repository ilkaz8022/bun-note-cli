#include "note.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"
#include <fcntl.h>

BNOTE* createNote(const char* name, const char* note)
{
    const char* bnn_path = ".bnote/notes/";
    int chd_result = changeCurrentDirectory(bnn_path);
    if (chd_result != 0)
    {
        perror("Error: changing directory error");
    }
    
    int fopen_res = open()
    
}
