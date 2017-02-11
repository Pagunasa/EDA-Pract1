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

void searchInMain(sList *msgList) {
    char searchParam[MAXLENGTH50];
    printf("Introduce el nombre del parametro: ");
    scanf("%s", searchParam);
    searchInMsg(msgList, searchParam);
}

void showMsgMain(sFolders *folders, sList *msgList) {
    listAllMsgs(msgList);
    char messageName[MAXLENGTH50];
    printf("Introduce el nombre del correo: ");
    scanf("%s", messageName);
    showMsg(msgList, messageName);
}

void createMsgMain(sFolders *folders, sList *msgList) {
    if (folders->folder[1].numMessages < MAXMESSAGES) {
        sMessage message;
        inputNewMsg(&message, folders, "Outbox");
        jumpsInMsgOut(folders);
        addMessageToList(message, msgList);
        saveOptions(folders);
    } else {
        printf("Numero de mensajes maximos superado!! \n");
    }
}

void createMsgMainInFolder(sFolders *folders, sList *msgList) {
    if (folders->folder[1].numMessages < MAXMESSAGES) {

        char folderName[MAXLENGTH20];
        printf("Introduce el nombre de la carpeta:");
        scanf(" %s", folderName);


        sMessage message;
        inputNewMsg(&message, folders, folderName);
        jumpsInMsgOut(folders);
        addMessageToList(message, msgList);
        saveOptions(folders);
    } else {
        printf("Numero de mensajes maximos superado!! \n");
    }
}

void deleteMsgMain(sFolders *folders, sList *msgList) {
    char messageName[MAXLENGTH50];
    printf("Introduce el nombre del correo:");
    scanf(" %s", messageName);
    deleteMessage(folders, msgList, messageName, "Outbox");
    jumpsInMsgOut(folders);
    saveOptions(folders);
}

void deleteFolderMain(sFolders *folders, sList *msgList) {
    char folderName[MAXLENGTH20];
    printf("Introduce el nombre de la carpeta:");
    scanf(" %s", folderName);
    deleteFolder(folderName, folders, msgList);
    saveOptions(folders);
}

void deleteMsgMainInFolder(sFolders *folders, sList *msgList) {
    char folderName[MAXLENGTH20];
    char messageName[MAXLENGTH50];

    printf("Introduce el nombre de la carpeta:");
    scanf(" %s", folderName);
    listMsgs(folderName, msgList, folders);

    printf("Introduce el nombre del correo:");
    scanf(" %s", messageName);
    deleteMessage(folders, msgList, messageName, folderName);

    jumpsInMsgOut(folders);
    saveOptions(folders);
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

void listMsgMain(sFolders *folders, sList *msgList) {
    char folderName[MAXLENGTH20];

    printf("Introduce el nombre de la carpeta:");
    scanf("%s", folderName);

    listMsgs(folderName, msgList, folders);
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
    inicializeList(&msgList);
    chargeMessages(&msgList, &folders);

    //    for (int i = 0; i < folders.numFolders; i++){
    //            printf("%s", folders.folder[i].folderName);
    //            printf("\n");
    //            for (int j = 0; j < folders.folder[i].numMessages; j++){
    //                printf("%s", folders.folder[i].messageName[j].messageName);  
    //    
    //            }
    //        }



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

        menu(option, &folders, &msgList);
    } while (option != 10);

    return (EXIT_SUCCESS);
}

menu(int option, sFolders *folders, sList *msgList) {
    char messageName[MAXLENGTH50];


    switch (option) {
        case 1:
            //crear correo
            createMsgMain(folders, msgList);

            break;
        case 2:
            //listar correos
            listMsgMain(folders, msgList);
            break;
        case 3:
            //visualizar correo
            showMsgMain(folders, msgList);
            break;
        case 4:
            //Borrar correo
            listMsgs("Outbox", msgList, folders);
            deleteMsgMain(folders, msgList);
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
            deleteFolderMain(folders, msgList);
            break;
        case 7:
            //Añadir un correo a una carpeta
            createMsgMainInFolder(folders, msgList);
            break;
        case 8:
            //Borrar un correo de una carpeta
            deleteMsgMainInFolder(folders, msgList);
            break;
        case 9:
            //Buscar una cadena
            searchInMain(msgList);
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


