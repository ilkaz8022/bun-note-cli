#include "note.h"
#include <stdio.h>
#include "init.h"
#include <fcntl.h>
#include <stdlib.h>
#include "log.h"


int createNote(const char *name, const char *note)
{
    FILE* fp = fopen(name, "a");
    if (fp == NULL)
    {
        putLog("Error: file open");
        return 1;
    }
    else 
    {
        fputs(note, fp);
        putLog("Succes: note was created");
        fclose(fp);
        return 0;
    }
}


int deleteNote(const char *name)
{
    int ch_result = changeCurrentDirectory(NOTES_DIRECTORY);
    if (ch_result != 0)
    {
        putLog("Error: change directory");
        return 1;
    }
    else 
    {
        int fres = remove(name);
        if (fres != 0)
        {
            putLog("Error: note was not removed");
            return 1;
        }
        else 
        {
            putLog("Succes: note was removed");
            return 0;
        }
    }
}


void changeNoteName(const char* name, const char* new_name)
{
    int ch_result = changeCurrentDirectory(NOTES_DIRECTORY);
    if (ch_result != 0)
    {
        putLog("Error: change directory");
        exit(EXIT_FAILURE);
    }
    else 
    {
        int rnm_result = rename(name, new_name);
        if (rnm_result != 0)
        {
            putLog("Error: note was not renamed");
            perror("Error: note was not renamed");
        }
        else 
        {
            putLog("Error: note name was changed");
        }
    }
}


void changeNote(const char* name, const char* new_note)
{
    int ch_result = changeCurrentDirectory(NOTES_DIRECTORY);
    if (ch_result != 0)
    {
        putLog("Error: change directory");
        exit(EXIT_FAILURE);
    }
    else 
    {
        FILE* fp = fopen("name", "w");
        if (fp == NULL)
        {
            putLog("Error: open file");
            perror("Error: open file");
        }
        else 
        {
            fprintf(fp, "%s\n", new_note);
            putLog("Succes: note was changed");
        }
    }
}

