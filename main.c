/* 
 * File:   main.c
 * Author: u140172
 *
 * Created on 18 de enero de 2017, 11:07
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "filesOperations.h"
#include "message.h"
//#include "messageOperations.c"

void createMsg() { 
    sMessage message;
    inputNewMsg(message);
}
/*
 * 
 */
int main(int argc, char** argv) {
    
    sFolders folders;
    openOptions(&folders);
    
    for (int i = 0; i < MAXFOLDERS; i++){
        printf("%s", folders.folder[i].folderName);
        for (int j = 0; j < MAXMESSAGES; j++){
            printf("%s", folders.folder[i].messageName[j].messageName);  
        }
    }
    
    int option = 0; 
  
    do{
        writeMenu();
        
        printf("Introduce Opcion: ");
        scanf("%d",&option);

        menu(option);
    } while(option != 10);

    return (EXIT_SUCCESS);
}

menu(int option) {
    char folderName[MAXLENGTH50];

    switch (option) {
        case 1:
            createMsg();
            break;
        case 2:
            
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("Introduce el nombre de la carpeta:");
            scanf(" %s", folderName);
            createFolder(folderName);
            break;
        case 6:
            printf("Introduce el nombre de la carpeta:");
            scanf(" %s", folderName);
            deleteFolder(folderName);
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        default:
            break;
    }
}

