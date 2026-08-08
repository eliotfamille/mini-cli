#include "linked.h"
#include <stdio.h>

void show(list *tab){
    if(tab==NULL)return;
    printf("%c/",tab->name);
    if(tab->one!=NULL)
        show(tab->one);
    if(tab->two!=NULL)
        show(tab->two);
    return;
}

void push(list *head,char a){

    list *new_nod=malloc(sizeof(list));
    new_nod->name=a;
    new_nod->one=NULL;
    new_nod->two=NULL;

    if(head->one==NULL){
        puts("add succecefully");
        head->one=new_nod;
    }
    else if(head->two==NULL){
        puts("add succecefully");
        head->two=new_nod;
    }else{
        puts("node plein");
    }
}
