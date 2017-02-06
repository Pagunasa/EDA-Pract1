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


void createMsg(sFolders folders) { 
    sMessage message;
    inputNewMsg(&message, &folders, "Outbox");
    saveOptions(&folders);
}
/*
 * 
 */
int main(int argc, char** argv) {
    sFolders folders;
    openOptions(&folders);
//saveOptions(&folders);
//addMessage(&folders, "6_EMemail", "Outbox"); 
    saveOptions(&folders);
    saveOptions(&folders);
//
//    for (int i = 0; i < numFolders; i++){
//        printf("%s", folders.folder[i].folderName);
//        printf("\n");
//        for (int j = 0; j < folders.folder[i].numMessages; j++){
//            printf("%s", folders.folder[i].messageName[j].messageName);  
//
//        }
//    }
    
    int option = 0; 
  
    do{
        writeMenu();
        
        printf("Introduce Opcion: ");
        scanf("%d",&option);

        menu(option, folders);
    } while(option != 10);

    return (EXIT_SUCCESS);
}

menu(int option, sFolders folders) {
    char folderName[MAXLENGTH50], messageName[MAXLENGTH50];

    switch (option) {
        case 1:
            //crear correo
            createMsg(folders);
            break;
        case 2:
            //listar correos
            break;
        case 3:
            //visualizar correo
            break;
        case 4:
            //Borrar correo
            printf("Introduce el nombre del correo:");
            scanf(" %s", messageName);
            deleteMessage(&folders, messageName);
            saveOptions(&folders);
            //openOptions(&folders);
            //saveOptions(&folders);

//            for (int i = 0; i < numFolders; i++){
//                printf("%s", folders.folder[i].folderName);
//                printf("\n");
//                for (int j = 0; j < folders.folder[i].numMessages; j++){
//                   printf("%s", folders.folder[i].messageName[j].messageName);  
//
//                }
//            }
            break;
        case 5:
            //crearCarpeta
            printf("Introduce el nombre de la carpeta:");
            scanf(" %s", folderName);
            createFolder(folderName);
            break;
        case 6:
            //Borrar carpeta
            printf("Introduce el nombre de la carpeta:");
            scanf(" %s", folderName);
            deleteFolder(folderName);
            break;
        case 7:
            //Añadir un correo a una carpeta
            break;
        case 8:
            //Borrar un correo de una carpeta
            break;
        case 9:
            //Buscar una cadena
            break;
        case 10:
            //salir
            printf("Gracias por usar el programa");
            saveOptions(&folders);
            break;
        default:
            //Mensaje de que opcion mal introducida
            printf("No existe esa opción \n");
            break;
    }
}

