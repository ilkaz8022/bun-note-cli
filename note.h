#ifndef NOTE_H
#define NOTE_H

typedef struct Note { 
    const char* name; 
    const char* format;
    int data;
} BNOTE;

BNOTE* createNote(const char* name, const char* format, int data);
BNOTE* deleteNote(const char* name);
void setData(int data);

#endif
