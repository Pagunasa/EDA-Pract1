/* 
 * File:   main.c
  *  * Autors:
    Guillem Martinez 196310
    Oriol Bernier 193518
    Sandra Rodriguez 192860
 * Main del programa donde se usan las funciones y definicion de funciones "Main" para dejar mas limpio el menu
 * Created on 18 de enero de 2017, 11:07
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "filesOperations.h"
#include "message.h"


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

void jumpsInMsgOut(sFolders *folders) {   //Llama  al eliminar el salto de los mensajes para todos
    for (int i = 0; i < folders->numFolders; i++) {
        if (folders->folder[i].numMessages != 0) {
            eliminateJumpsMsg(folders, folders->folder[i].folderName);
        }
    }
}

void searchInMain(sList *msgList){  //Sirve para llamar a la busqueda
    char searchParam[MAXLENGTH50];
    printf("Introduce el nombre del parametro: ");
    scanf("%s", searchParam);
    searchInMsg(msgList, searchParam);
}

void showMsgMain(sFolders *folders, sList *msgList) { //LLama al show message
    listAllMsgs(msgList);
    char messageName[MAXLENGTH50];
    printf("Introduce la Ref del correo (con <>): ");
    scanf("%s", messageName);
    showMsg(msgList, messageName);
}

void createMsgMain(sFolders *folders, sList *msgList) { //llama al crear mensaje por defecto se crea en OutBox
    if (folders->folder[1].numMessages < MAXMESSAGES) {
        sMessage message;
        inputNewMsg(&message, folders, "Outbox");
        jumpsInMsgOut(folders);
        addMessageToList(&message, msgList);
        saveOptions(folders);
    } else {
        printf("Numero de mensajes maximos superado!! \n");
    }
}

void createMsgMainInFolder(sFolders *folders, sList *msgList) { //llama al crear mensaje
    if (folders->folder[1].numMessages < MAXMESSAGES) {

        char folderName[MAXLENGTH20];
        printf("Introduce el nombre de la carpeta: ");
        scanf(" %s", folderName);


        sMessage message;
        inputNewMsg(&message, folders, folderName);
        jumpsInMsgOut(folders);
        addMessageToList(&message, msgList);
        saveOptions(folders);
    } else {
        printf("Numero de mensajes maximos superado!! \n");
    }
}

void deleteMsgMain(sFolders *folders, sList *msgList) { //llama al delete mensaje por defecto lo borra de outbox
    char messageName[MAXLENGTH50];
    printf("Introduce Ref del correo (sin <>): ");
    scanf("%s", messageName);
    deleteMessage(folders, msgList, messageName, "Outbox");
    jumpsInMsgOut(folders);
    saveOptions(folders);
}

void deleteFolderMain(sFolders *folders, sList *msgList) { //llama a borrar una carpeta
    char folderName[MAXLENGTH20];
    printf("Introduce el nombre de la carpeta: ");
    scanf(" %s", folderName);
    deleteFolder(folderName, folders, msgList);
    saveOptions(folders);
}

void deleteMsgMainInFolder(sFolders *folders, sList *msgList) { //llama al delete mensaje a una carpeta
    char folderName[MAXLENGTH20];
    char messageName[MAXLENGTH50];

    printf("Introduce el nombre de la carpeta: ");
    scanf(" %s", folderName);
    listMsgs(folderName, msgList, folders);

    printf("Introduce Ref del correo (sin <>):");
    scanf(" %s", messageName);
    deleteMessage(folders, msgList, messageName, folderName);

    jumpsInMsgOut(folders);
    saveOptions(folders);
}

void createFolderMain(sFolders *folders) { //llama al crear una carpeta
    char folderName[MAXLENGTH20];
    printf("Introduce el nombre de la carpeta: ");
    scanf("%s", folderName);
    createFolder(folderName, folders);
    jumpsInMsgOut(folders);
    saveOptions(folders);
}

void listMsgMain(sFolders *folders, sList *msgList) { //llama a listar todos los correos de una carpeta
    char folderName[MAXLENGTH20];

    printf("Introduce el nombre de la carpeta: ");
    scanf("%s", folderName);

    listMsgs(folderName, msgList, folders);
}

void menu(int option, sFolders *folders, sList *msgList) {
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


