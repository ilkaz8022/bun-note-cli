#include "init.h"
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "log.h"


BINIT* getCurrentDirectory(void)
{
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        BINIT* result = (BINIT*)malloc(sizeof(BINIT));
        if (result == NULL)
        {
            putLog("Error: memory allocation error");
            return NULL;
            exit(EXIT_FAILURE);
        }
    
        result->path = (char*)malloc(strlen(cwd) + 1);
        if (result->path == NULL)
        {
            putLog("Error: memory allocation error");
            free(result);
            return NULL;
            exit(EXIT_FAILURE);
       }
        strcpy(result->path, cwd);
        return result;
    }
    else 
    {
        putLog("Error: cannot get current directory");
        return NULL;
    }
}


int changeCurrentDirectory(const char* path)
{
   int ch_result = chdir(path);
   if (ch_result == 0)
   { 
       return 0;
   }
   else 
   {
       return -1;
   }
}


static int createDirectories(void)
{

    int d_result = mkdir(MAIN_DIRECTORY, 0777);
    if (d_result != 0)
    {
        putLog("Error: creating directories error");
        return 1;
    }
    
    int f_result = mkdir(LOGS_DIRECTORY, 0777);
    if (f_result != 0)
    {
        putLog("Error: creating directories error");
        return 1;
    }

    int bn_result = mkdir(NOTES_DIRECTORY, 0777);
    if (bn_result != 0)
    {
        putLog("Error: creating directories error");
        return 1;
    }

    return 0;
}


int b_init(void)
{
    BINIT* c_path = getCurrentDirectory();
    if (c_path == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int md_result = createDirectories();
    if (md_result != 0)
    {
        putLog("Error: init error");
        return 0;
    }
    else 
    {
        free(c_path->path);
        free(c_path);
        return 0;
    }
}


 
