/* 
 * File:   main.h
 * Author: u140172
 *
 * Created on 24 de enero de 2017, 12:48
 */

#include <stdio.h>
#include "filesOperations.h"
#include "message.h"
#include <stdlib.h>
#ifndef MAIN_H
#define	MAIN_H

void jumpsInMsgOut(sFolders *folders);
void searchInMain(sList *msgList);
void showMsgMain(sFolders *folders, sList *msgList);
void createMsgMain(sFolders *folders, sList *msgList);
void createMsgMainInFolder(sFolders *folders, sList *msgList);
void deleteMsgMain(sFolders *folders, sList *msgList);
void deleteFolderMain(sFolders *folders, sList *msgList);
void deleteMsgMainInFolder(sFolders *folders, sList *msgList);
void createFolderMain(sFolders *folders);
void listMsgMain(sFolders *folders, sList *msgList);
void menu(int option, sFolders *folders, sList *msgList);


void writeMenu() {
    printf("Bienvenidos a correo \n");
    printf("Elija una opcion \n");
    printf("1-\t Crear correo \n");
    printf("2-\t Listar correo \n");
    printf("3-\t Visualizar correo \n");
    printf("4-\t Borrar correo \n");
    printf("5-\t Crear carpeta \n");
    printf("6-\t Borrar carpeta \n");
    printf("7-\t Añadir un correo a una carpeta \n");
    printf("8-\t Borrar un correo de una carpeta \n");
    printf("9-\t Buscar en un correo una cadena de caracteres \n");
    printf("10-\t Salir \n"); 
    
}



#endif	/* MAIN_H */

