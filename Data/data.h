#ifndef DATA_H
#define DATA_H

typedef struct text{
    char *name_text;
    char *content_text;
}text;

typedef struct files{
    struct files *hote_files;
    char *name_files;
    struct files *content_files;
    text *content_text_in;
}files;

#endif
