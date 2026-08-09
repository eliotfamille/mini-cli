#ifndef FONCTION_H
#define FONCTION_H

#include <stdlib.h>
#include <stdbool.h>
#include "data.h"
#include "interaction.h"

files *root;
int i_pwd=0;
int i_pwd_find=0;

char **pwd;
char **pwd_find;

// verification
bool find_files(files *hote, char to_find[]);
bool find_text(files *hote, char name[]);

// show
void list(files *hote);

// command
void cd(files *hote, files *direction);
void search(files *hote,char name[]);
void touch(files *hote,char name[],char content[]);
void mkdir(files *hote,char name[]);

#endif
