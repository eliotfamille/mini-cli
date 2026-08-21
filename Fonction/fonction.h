#ifndef FONCTION_H
#define FONCTION_H

#include "data.h"
#include "interaction.h"

extern folder *root;        // the folder root
extern int i_pwd;           // index to brows in the system
extern int i_pwd_find;      // temporary index to find somethink

extern char **pwd;          // the actual directory
extern char **pwd_find;     // a temporary directory of an folder or file

// verification
bool find_folder(folder *hote, char to_find[]);
bool find_text(folder *hote, char name[]);

// show
void list(folder *hote);

// command
void cd(folder *hote, char *name);
void search(folder *hote,char *name);
void touch(folder *hote,text *file);
void mkdir(folder *hote,char *name);

#endif
