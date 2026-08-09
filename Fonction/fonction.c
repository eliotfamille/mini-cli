#include <stdio.h>
#include "fonction.h"


// find_files
bool find_files(files* hote, char to_find[])
{
    for(int i=0; i<sizeof(hote->content_files); i++){
        if(hote->content_files[i].name_files==to_find)
            return true;
    }
    return false;
}
// find_text
bool find_text(files* hote, char name[])
{
    if(hote->content_text_in!=NULL){
        for(int i=0; i<sizeof(hote->content_text_in); i++){
            if(hote->content_files[i].name_files==name){
                return true;
            }
        }
    }
    return false;
}

// show content_files
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


// acce to an file
void cd(files* hote, files* direction)
{
    i_pwd++;
    pwd=realloc(pwd,i_pwd*sizeof(char*));

    if(find_files(hote,direction->name_files)){
        hote=direction;
    }
    else{
        puts("Files not found");
        return;
    }
}

// search
void search(files *hote, char name[])
{
    i_pwd_find++;
    pwd_find=realloc(pwd_find,i_pwd_find*sizeof(char*));
    pwd_find[sizeof(pwd_find)-1]=name;

    if(hote==NULL){
        i_pwd_find--;
        pwd_find=realloc(pwd_find,i_pwd_find*sizeof(char*));
        return;
    }
    if(hote->name_files==name){
        for(int i=0; i<sizeof(pwd_find);i++){
            printf("%s/",pwd_find[i]);
        }
        free(pwd_find);
        i_pwd_find=0;
        return;
    }
    if(find_files(hote,name)){
        for(int i=0; i<sizeof(pwd_find);i++){
            printf("%s/",pwd_find[i]);
        }
        printf("%s.txt",name);
        free(pwd_find);
        i_pwd_find=0;
        return;
    }
    for(int i=0;i<sizeof(hote->content_files);i++){
        search(&hote->content_files[i],name);
    }
    free(pwd_find);
    i_pwd_find=0;
}

// creat_text
void touch(files* hote, char name[], char content[])
{
    if(find_text(hote,name)){
        puts("Alraidy exist");
        return;
    }
    text *txt=complete_txt(name, content);
    if(txt==NULL){
        puts("Faild to creat text");
        return;
    }
    hote->content_text_in=realloc(hote->content_text_in,(sizeof(hote->content_text_in)+1)*sizeof(text));
    hote->content_text_in[sizeof(hote->content_text_in)-1]=*txt;
    free(txt);
}
// creat_directory
void mkdir(files* hote, char name[])
{
    if(find_files(hote,name)){
        puts("File alraidy exist");
        return;
    }
    files *file=complete_files(name);
    if(file==NULL){
        puts("Faild to creat directory");
        return;
    }
    hote->content_files=realloc(hote->content_files,(sizeof(hote->content_files)+1)*sizeof(files));
    hote->content_files[sizeof(hote->content_files)-1]=*file;
    free(file);
}
