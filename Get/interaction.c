#include "interaction.h"

// complete_txt
text *complete_txt()
{
    int size=64;
    int index=0;
    text *txt=malloc(sizeof(text*));
    if(txt==NULL){
        puts("Faild allocation");
        return NULL;
    }
    printf("Enter name file: ");
    scanf("%s",txt->name_text);
    txt->content_text=malloc(size*sizeof(char));
    if(txt->content_text==NULL){
        puts("faild allocation!");
        return txt;
    }
    puts("Content:");
    while(fgets(txt->content_text+index,size-index,stdin)){
        index+=strlen(txt->content_text+index);
        if((size-index)<5){
            txt->content_text=realloc(txt->content_text,(size*2)*sizeof(char));
            if(txt->content_text==NULL){
                puts("echec allocation");
                free(txt->content_text);
                return txt;
            }
        }
    }
    return txt;
}
// complete_folder
folder * complete_folder()
{
    folder *file=malloc(1*sizeof(folder*));
    if(file==NULL){
        puts("Faild allocation");
        return NULL;
    }

    return file;
}
