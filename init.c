#define MAIN_DIRECTORY  ".bnote/"
#define LOGS_DIRECTORY  ".bnote/logs"
#define NOTES_DIRECTORY ".bnote/notes"

#include "init.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


BINIT* getCurrentDirectory(void)
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


static void createDirectories(void)
{

    int d_result = mkdir(MAIN_DIRECTORY, 0777);
    if (d_result != 0)
    {
        perror("Error: creating directories error");
    }
    
    int f_result = mkdir(LOGS_DIRECTORY, 0777);
    if (f_result != 0)
    {
        perror("Error: creating directories error");
    }

    int bn_result = mkdir(NOTES_DIRECTORY, 0777);
    if (bn_result != 0)
    {
        perror("Error: creating directories error");
    }
}


int b_init(void)
{
    BINIT* c_path = getCurrentDirectory();
    if (c_path == NULL)
    {
        perror("Error: что-то пошло не так");
        return 1;
    }

    createDirectories();
    return 0;
}

 
