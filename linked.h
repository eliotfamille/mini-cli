#ifndef LINKED_H
#define LINKED_H
#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    struct list *one;
    struct list *two;
    char name;
}list;

void show(list *tab);
void push(list *head,char a);
#endif
