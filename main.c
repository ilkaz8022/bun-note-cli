#include "init.h"
#include "log.h"
#include "note.h"
#include <string.h>

#define RED   "\033[31m"
#define RESET "\033[0m"

void usage(void);


int main(int argc, char** argv)
{
    if (argc < 2) 
    {
        printf(RED "Error: no arguments provided\n" RESET);
        putLog("[ARGS ERROR] argument error");
        usage();
        return 1;
    }

    if (strcmp(argv[1], "init") == 0) 
    {
        b_init();
    }

    else if (strcmp(argv[1], "make-note") == 0) 
    {
        if (argc < 4)
        {
            printf(RED "Error: make-note requires <name> <text>\n" RESET);
            putLog("[ARGS ERROR] argument error make-note");
            return 1;
        }
        createNote(argv[2], argv[3]);
    }

    else if (strcmp(argv[1], "del-note") == 0)
    {
        if (argc < 3)
        {
            printf(RED "Error: del-note requires <name>\n" RESET);
            putLog("[ARGS ERROR] argument error del-note");
            return 1;
        }
        deleteNote(argv[2]);
    }

    else if (strcmp(argv[1], "change-name") == 0) 
    {
        if (argc < 4) 
        {
            printf(RED "Error: change-name requires <old_name> <new_name>\n" RESET);
            putLog("[ARGS ERROR] argument error change-name");
            return 1;
        }
        changeNoteName(argv[2], argv[3]);
    }

    else if (strcmp(argv[1], "change-note") == 0)
    {
        if (argc < 4)
        {
            printf(RED "Error: change-note requires <name> <new_text>\n" RESET);
            putLog("[ARGS ERROR] argument error change-note");
            return 1;
        }
        changeNote(argv[2], argv[3]);
    }

    else if (strcmp(argv[1], "get-log") == 0) 
    {
        getLogs();
    }

    else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "help") == 0)
    {
        usage();
    }

    else
    {
        printf(RED "Error: unknown command '%s'\n" RESET, argv[1]);
        putLog("[ARGS ERROR] unknown command");
        return 1;
    }    

    return 0;
}


void usage(void)
{
    printf("  bnote init\n");
    printf("  bnote make-note <name> <text>\n");
    printf("  bnote del-note <name>\n");
    printf("  bnote change-name <old_name> <new_name>\n");
    printf("  bnote change-note <name> <new_text>\n");
    printf("  bnote get-log\n");
    printf("  bnote --help | help\n");
}
