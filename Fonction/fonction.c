#include "fonction.h"

folder *root=NULL;
int i_pwd=0;
int i_pwd_find=0;
char **pwd=NULL;
char **pwd_find=NULL;

// if a foldere is in the directory
bool find_folder(folder* hote, char to_find[])
{
    for(int i=0; i<sizeof(hote->content_folder); i++){
        if(hote->content_folder[i].name_folder==to_find)
            return true;
    }
    return false;
}
// if a file is in the directory
bool find_text(folder* hote, char name[])
{
    if(hote->content_text_in!=NULL){
        for(int i=0; i<sizeof(hote->content_text_in); i++){
            if(hote->content_folder[i].name_folder==name){
                return true;
            }
        }
    }
    return false;
}

// show content_folder
void list(folder* hote)
{
    if(hote->content_folder!=NULL){
        for(int i=0; i<sizeof(hote->content_folder); i++){
            printf("[%s]\n",hote->content_folder[i].name_folder);
        }
    }
    if(hote->content_text_in!=NULL){
        for(int i=0; i<sizeof(hote->content_text_in); i++){
            printf("%s.txt\n",hote->content_text_in[i].name_text);
        }
    }
}


// access to an folder
void cd(folder* hote, char *name)
{
    if(find_folder(hote,name)){
        i_pwd++;
        pwd=realloc(pwd,i_pwd*sizeof(char*));
        int i=0;
        while(hote->content_folder[i].name_folder!=name){i++;}
        pwd[i_pwd]=name;
        *root=hote->content_folder[i];
    }
    else{
        puts("Files not found");
        return;
    }
}

// search
void search(folder *hote, char name[])
{
    i_pwd_find++;
    pwd_find=realloc(pwd_find,i_pwd_find*sizeof(char*));
    pwd_find[sizeof(pwd_find)-1]=name;

    if(hote==NULL){
        i_pwd_find--;
        pwd_find=realloc(pwd_find,i_pwd_find*sizeof(char*));
        return;
    }
    if(hote->name_folder==name){
        for(int i=0; i<sizeof(pwd_find);i++){
            printf("%s/",pwd_find[i]);
        }
        free(pwd_find);
        i_pwd_find=0;
        return;
    }
    if(find_folder(hote,name)){
        for(int i=0; i<sizeof(pwd_find);i++){
            printf("%s/",pwd_find[i]);
        }
        printf("%s.txt",name);
        free(pwd_find);
        i_pwd_find=0;
        return;
    }
    for(int i=0;i<sizeof(hote->content_folder);i++){
        search(&hote->content_folder[i],name);
    }
    free(pwd_find);
    i_pwd_find=0;
}

// creat_text
void touch(folder* hote, text *file)
{
    if(find_text(hote,file->name_text)){
        puts("Alraidy exist");
        return;
    }
    hote->content_text_in=realloc(hote->content_text_in,(sizeof(text)+1)*sizeof(text));
    if(hote->content_text_in==NULL){
        puts("Failde redemetion");
        return;
    }
    hote->content_text_in[sizeof(hote->content_text_in)-1]=file;
}
// creat_directory
void mkdir(folder* hote, char name[])
{
    if(find_folder(hote,name)){
        puts("File alraidy exist");
        return;
    }
    folder *fold=complete_folder(name);
    if(fold==NULL){
        puts("Faild to creat directory");
        return;
    }
    hote->content_folder=realloc(hote->content_folder,(sizeof(hote->content_folder)+1)*sizeof(folder));
    hote->content_folder[sizeof(hote->content_folder)-1]=*file;
    free(fold);
}
