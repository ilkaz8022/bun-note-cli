#ifndef NOTE_H
#define NOTE_H

int createNote(char* name, char* note);
int deleteNote(char* name);

void changeNoteName(char* name, char* new_name);
void changeNote(char* name, char* new_note);

#endif
