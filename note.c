#include "note.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init_dir_file.h"

BNOTE* createNote(const char* name, const char* format, int data)
{
    const char* bnn_path = ".bnote/notes/";
    int chd_result = changeCurrentDirectory(bnn_path);
    if (chd_result != 0)
    {
        perror("Error: changing directory error");
    }
    
    
}
