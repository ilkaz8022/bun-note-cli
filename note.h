#ifndef NOTE_H
#define NOTE_H

typedef struct Note { 
    const char* name; 
    const char* format;
    int data;
} BNOTE;

BNOTE* createNote(const char* name, const char* format, const char* note);
BNOTE *createDateNote(const char* name, const char* format, const char* note, const char* date);
BNOTE* deleteNote(const char* name);

#endif
