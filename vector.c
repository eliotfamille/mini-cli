#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

bool find_files(files* hote, char to_find[])
{
    for(int i=0; i<sizeof(hote->content_files); i++){
        if(hote->content_files[i].name_files==to_find)
            return true;
    }
    return false;
}
void list(files* hote)
{
    if(hote->content_files!=NULL){
        for(int i=0; i<sizeof(hote->content_files); i++){
            printf("[%s]\n",hote->content_files[i].name_files);
        }
    }
    if(hote->content_text_in!=NULL){
        for(int i=0; i<sizeof(hote->content_text_in); i++){
            printf("%s.txt",hote->content_text_in[i].name_text);
        }
    }
}


void pwd(files* root,files *now)
{
    if(root==NULL)return;
    printf("/%s",root->name_files);
}

void cd(files* hote, files* direction)
{
    if(find_files(hote,direction->name_files)){

        hote=direction;
    }
    else{
        puts("Files not found");
        return;
    }
}



