#include <stdio.h>
#include <stdlib.h>
#include "message.h"
#include "filesOperations.h"
#include <string.h>
#include "errors.h"

void deleteFolder(char folderName[MAXLENGTH50], sFolders *folders, sList *msgList) { //sirve para borrar una carpeta y tmb sus correos si no estan en otra
    int confirmation = 2;
    int pass = 1, exists = 0, repeated = 0;

    typedef struct {
        char messageN[MAXLENGTH50];
    } sMensajeFo;

    typedef struct {
        sMensajeFo mensajes[MAXLENGTH18];
        int nMefo;
    } sMensajesFo;

    sMensajesFo mesFo;
    char messageNameTmp1[MAXLENGTH50];

    for (int i = 0; i < folders->numFolders; i++) {
        if (strcmp(folderName, folders->folder[i].folderName) == 0) {
            exists = 1;
            mesFo.nMefo = 0;
            for (int a = 0; a < folders->folder[i].numMessages; a++) {
                strcpy(mesFo.mensajes[a].messageN, folders->folder[i].messageName[a].messageName);
                mesFo.nMefo++;
            }

            if (folders->folder[i].private == TRUE) {
                printf("Carpeta privada no se puede borrar!!!\n");
            } else {
                if (folders->folder[i].numMessages != 0) {
                    while (pass != 0) {
                        printf("Estas seguro que quieres borrar la carpeta? \n\t1-Si \n\t0-No \n\t");
                        scanf("%i", &confirmation);
                        if (confirmation == 1 || confirmation == 0) {
                            pass = 0;
                        } else {
                            pass = 1;
                        }
                    };
                    if (confirmation == 1) {
                        printf("Carpeta borrada \n");
                        

                        for (int a = 0; a < mesFo.nMefo; a++) {
                            for (int e = 0; e < folders->numFolders; e++) {
                                if (strcmp(folders->folder[e].folderName, folderName) != 0) {
                                    for (int u = 0; u < folders->folder[e].numMessages; u++) {
                                        if (strcmp(folders->folder[e].messageName[u].messageName, mesFo.mensajes[a].messageN) == 0) {
                                            repeated++;
                                        }
                                    }
                                }
                            }

                            if (repeated == 0) {
                                sprintf(messageNameTmp1, "<%s>", mesFo.mensajes[a].messageN);
                                deleteMessageFromList(msgList, messageNameTmp1);
                                sprintf(messageNameTmp1, "EMDB/%s.txt", mesFo.mensajes[a].messageN);
                                remove(messageNameTmp1);
                                
                            }
                            repeated = 0;
                        }
                        
                        strcpy(folders->folder[i].folderName, "NULL");

                    } else {
                        printf("Carpeta no borrada \n");
                    }
                } else {
                    printf("Carpeta borrada \n");
                    strcpy(folders->folder[i].folderName, "NULL");
                }

            }
        } else {
            if (i == folders->numFolders - 1 && exists == 0) {
                printf("No existe esa carpeta!!! \n");
            }
        }
    }
}

void setPrivateOPublic(sFolders *folders) { //Sirve para definir la privacidad de las carpetas
    for (int i = 0; i < folders->numFolders; i++) {
        if (strcmp(folders->folder[i].folderName, "Inbox") == 0
                || strcmp(folders->folder[i].folderName, "Outbox") == 0) {
            folders->folder[i].private = TRUE;
        } else {
            folders->folder[i].private = FALSE;
        }
    }
}

void createFolder(char folderName[MAXLENGTH50], sFolders *folders) { //Sirve para crear la carpeta

    int repeat = FALSE;

    if (folders->numFolders == MAXFOLDERS) {
        printf("Numero de carpetas superado!!");
    } else {
        for (int i = 0; i < folders->numFolders; i++) {
            if (strcmp(folderName, folders->folder[i].folderName) == 0) {
                printf("No se puede repetir el nombre!!!\n");
                repeat = TRUE;
            }
        }
        if (repeat == FALSE) {
            strcpy(folders->folder[folders->numFolders].folderName, folderName);
            folders->folder[folders->numFolders].numMessages = 0;
            folders->numFolders++;
            folders->folder[folders->numFolders].private = FALSE;
            printf("Carpeta creada con exito!!!\n");
        }
    }
}