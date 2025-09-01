#ifndef NOTE_H
#define NOTE_H

int createNote(const char* name ,const char* note);
int deleteNote(const char* name);

void changeNoteName(const char* name, const char* new_name);
void changeNote(const char* name, const char* new_note);

#endif
