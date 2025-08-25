#include <stdio.h>
#include <time.h>
#include "init.h"

#define LINE_BUFFER_SIZE 4096


void putLog(const char* action)
{
    int ch_result = changeCurrentDirectory(LOGS_DIRECTORY);
    if (ch_result != 0)
    {
        perror("Error: change directory");
    }
    
    FILE* fp = fopen("logs", "a");
    if (fp == NULL)
    {
        perror("Error: log file open error");
    }

    time_t my_time = time(NULL);
    struct tm* now = localtime(&my_time);
    fprintf(fp, "Date: %d.%d.%d || ", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    fprintf(fp, "Time: %d:%d:%d ", now->tm_hour, now->tm_min, now->tm_sec); 
    fprintf(fp, "%s\n", action);
    fclose(fp);
}


void getLogs(void)
{
    int ch_result = changeCurrentDirectory(LOGS_DIRECTORY);
    if (ch_result != 0)
    {
        perror("Error: change directory");
    }
    
    FILE* fp = fopen("logs", "r");
    if (fp == NULL)
    {
        perror("Error: log file open error");
    }

    char line[LINE_BUFFER_SIZE];
    while (fgets(line, LINE_BUFFER_SIZE, fp) != NULL)
    {
        printf("%s", line);
    }
}
