#include "interaction.h"

// complete_txt
text * complete_txt(char name[], char content[])
{
    text *txt=malloc(1*sizeof(text*));
    if(txt==NULL){
        puts("Faild allocation");
        return NULL;
    }
    txt->content_text=content;
    txt->name_text=name;
    return txt;
}
// complete_files
files * complete_files(char name[])
{
    files *file=malloc(1*sizeof(files*));
    if(file==NULL){
        puts("Faild allocation");
        return NULL;
    }
    file->name_files=name;
    return file;
}
