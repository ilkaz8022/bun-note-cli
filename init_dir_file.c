#include "init_dir_file.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


BINIT* getCurrentDirectory()
{
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("Succes: current directory is : %s\n", cwd);

        BINIT* result = (BINIT*)malloc(sizeof(BINIT));
        if (result == NULL)
        {
            perror("Error: memory allocation error");
            return NULL;
        }
    
        result->path = (char*)malloc(strlen(cwd) + 1);
        if (result->path == NULL)
        {
            perror("Error: memory allocation error");
            free(result);
            return NULL;
        }
        strcpy(result->path, cwd);
        return result;
    }
    else 
    {
        perror("Error: cannot get current directory");
        return NULL;
    }
}

int changeCurrentDirectory(const char* PATH)
{
   int ch_result = chdir(PATH);
   if (ch_result == 0)
   { 
       return 0;
   }
   else 
   {
       return -1;
   }
}

static void createDirectories()
{
    const char* main_folder = ".bnote/";
    const char* b_log = ".bnote/logs/";
    const char* notes = ".bnote/notes/";

    int d_result = mkdir(main_folder, 0777);
    if (d_result != 0)
    {
        perror("Error: creating directories error");
    }
    
    int f_result = mkdir(b_log, 0777);
    if (f_result != 0)
    {
        perror("Error: creating directories error");
    }

    int bn_result = mkdir(notes, 0777);
    if (bn_result != 0)
    {
        perror("Error: creating directories error");
    }
}


