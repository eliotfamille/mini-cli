#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include "struct.h"

bool find_files(files* hote, char to_find[]);
void list(files *hote);


void pwd(files *root,files *now);
void cd(files *hote, files *direction);
void search(files *root,char name);

#endif
