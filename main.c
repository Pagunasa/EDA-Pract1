/* 
 * File:   main.c
 * Author: u140172
 *
 * Created on 18 de enero de 2017, 11:07
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "filesOperations.h"
#include "message.h"

void jumpsInMsgOut(sFolders *folders) {
    for (int i = 0; i < folders->numFolders; i++) {
        if (folders->folder[i].numMessages != 0) {
            eliminateJumpsMsg(folders, folders->folder[i].folderName);
        }
    }
}

void createMsgMain(sFolders *folders) {
    if (folders->folder[1].numMessages < MAXMESSAGES) {
        sMessage message;
        inputNewMsg(&message, folders, "Outbox");
        jumpsInMsgOut(folders);
        saveOptions(folders);
    } else {
        printf("Numero de mensajes maximos superado!! \n");
    }
}

void deleteMsgMain(sFolders *folders) {
    char messageName[MAXLENGTH50];
    printf("Introduce el nombre del correo:");
    scanf(" %s", messageName);
    deleteMessage(folders, messageName);
    jumpsInMsgOut(folders);
    saveOptions(folders);
}

void deleteFolderMain(sFolders *folders) {
    char folderName[MAXLENGTH20];
    printf("Introduce el nombre de la carpeta:");
    scanf(" %s", folderName);
    deleteFolder(folderName, folders);
}

void createFolderMain(sFolders *folders) {
    char folderName[MAXLENGTH20];
    // int Pass;
    //    do {
    printf("Introduce el nombre de la carpeta:");
    scanf("%s", folderName);
    // readChain(folderName, MAXLENGTH20);
    //        if (strstr(folderName, " ") == 0) {
    //            Pass = FALSE;
    //            printf("No se permiten espacios en el nombre\n");
    //        } else {
    //            Pass = TRUE;
    //        }
    //    } while (Pass != TRUE);
    createFolder(folderName, folders);
    jumpsInMsgOut(folders);
    saveOptions(folders);
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    sFolders folders;
    sList msgList;
    
    openOptions(&folders);
    eliminateJumps(&folders);
    jumpsInMsgOut(&folders);
    setPrivateOPublic(&folders);
    
//    for (int i = 0; i < folders.numFolders; i++){
//            printf("%s", folders.folder[i].folderName);
//            printf("\n");
//            for (int j = 0; j < folders.folder[i].numMessages; j++){
//                printf("%s", folders.folder[i].messageName[j].messageName);  
//    
//            }
//        }

    
    inicializeList(&msgList);
    chargeMessages(&msgList, &folders);
//    
//    printf("Empty: %i\n", msgList.empty);
    
    //printf("FirstMsg: %i\n", msgList.first);
    //saveOptions(&folders);
    //addMessage(&folders, "6_EMemail", "Outbox"); 
    // for (int i = 0; i < numFolders; i++){
    //      eliminateJumpsMsg(&folders, folders.folder[i].folderName);
    //  }

    //  saveOptions(&folders);
    //saveOptions(&folders);
    //
//        for (int i = 0; i < folders.numFolders; i++){
//            printf("%s", folders.folder[i].folderName);
//            printf("\n");
//            for (int j = 0; j < folders.folder[i].numMessages; j++){
//                printf("%s", folders.folder[i].messageName[j].messageName);  
//    
//            }
//        }

    int option = 0;

    do {
        writeMenu();

        printf("Introduce Opcion: ");
        scanf("%d", &option);

        menu(option, &folders);
    } while (option != 10);

    return (EXIT_SUCCESS);
}

menu(int option, sFolders *folders) {
    char messageName[MAXLENGTH50];


    switch (option) {
        case 1:
            //crear correo
            createMsgMain(folders);
            break;
        case 2:
            //listar correos
            break;
        case 3:
            //visualizar correo
            break;
        case 4:
            //Borrar correo
            deleteMsgMain(folders);
//            printf("Introduce el nombre del correo:");
//            scanf(" %s", messageName);
//            deleteMessage(folders, messageName);
//            //            for (int i = 0; i < folders->numFolders; i++) {
//            //                eliminateJumpsMsg(folders, folders->folder[i].folderName);
//            //            }
//            jumpsInMsgOut(folders);
//            saveOptions(folders);
            //openOptions(&folders);
            //saveOptions(&folders);

            //            for (int i = 0; i < numFolders; i++){
            //                printf("%s", folders->folder[i].folderName);
            //                printf("\n");
            //                printf("%i", folders->folder[i].numMessages);
            //                for (int j = 0; j < folders->folder[i].numMessages; j++){
            //                   printf("%s", folders->folder[i].messageName[j].messageName); 
            //                   printf("\n");
            //                }
            //            }
            break;
        case 5:
            //crearCarpeta
            createFolderMain(folders);
            break;
        case 6:
            //Borrar carpeta
            deleteFolderMain(folders);
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
            jumpsInMsgOut(folders);
            saveOptions(folders);
            break;
        default:
            //Mensaje de que opcion mal introducida
            printf("No existe esa opción \n");
            break;
    }
}


