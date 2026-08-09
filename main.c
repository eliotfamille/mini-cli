#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
#include "fonction.h"

int main(int argc, char *argv[])
{
    int chois;
    do{
        printf("[0]: exit\t[1]: creat directory\t[2]: creat ");
        switch(chois){
            case 0:
                puts("Exit");
                return false;
                break;
            default :
                puts("Invalide chois");
                break;
        }
    }while(true);
    return 0;
}
