#ifndef DATA_H
#define DATA_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// text files
typedef struct text{
    char *name_text;
    char *content_text;
}text;

typedef struct folder{
    struct folder *hote_folder;
    char *name_folder;
    struct folder *content_folder;
    text *content_text_in;
}folder;

#endif
