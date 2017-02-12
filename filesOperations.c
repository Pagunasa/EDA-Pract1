/* 
 * File:   filesOperations.c
 *  * Autors:
    Guillem Martinez 196310
    Oriol Bernier 193518
    Sandra Rodriguez 192860
 * Funcionalidades para cargar y guardar las opciones y eeliminar saltos de linias para las comparaciones
 * Created on 24 de enero de 2017, 12:48
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "message.h"
#include "filesOperations.h"
#include "errors.h"


void openOptions(sFolders *folders) { //sirve para abrir el fichero de opciones y guardar su información
    char temp1[MAXLENGTH50] = "";
    char temp2[MAXLENGTH50] = "";

    int i = 0;
    int j = 0;
    int e = 0;

    FILE * optionsFile;

    optionsFile = fopen("EMDB/EMconfig.txt", "r");

    if (optionsFile == NULL) {
        printf(COLOR_RED "El archivo no existe \n" COLOR_RESET);
    } else {
        printf(COLOR_GREEN "El archivo existe \n" COLOR_RESET);

        fscanf(optionsFile, " %s %d ", temp1, &folders->messageID);
        fscanf(optionsFile, "%s", temp1);
        folders->numFolders = 0;
        
        while (feof(optionsFile) == 0) {
            fgets(temp1, MAXLENGTH50, optionsFile);

            if (strcmp(temp1, "\n") == 0 || strcmp(temp1, "\r\n") == 0) {

            } else {
                if (strstr(temp1, "Messages:") == NULL && strstr(temp1, "End") == NULL) {
                    if (strcmp(temp2, "") != 0) {
                        j = 0;
                        eliminateJumps(folders);
                        for (int i = 0; i <= MAXMESSAGES; i++) {
                            if (strcmp(folders->folder[i].folderName, temp2) == 0) {
                                do {
                                    if (strcmp(temp1, "\n") == 0 || strcmp(temp1, "\r\n") == 0) {
                                        if (strcmp(temp1, "\r\n") == 0) {
                                            e = 1;
                                            i = MAXMESSAGES;
                                        } else {
                                            fgets(temp1, MAXLENGTH50, optionsFile);
                                        }
                                    } else {
                                        strcpy(folders->folder[i].messageName[j].messageName, temp1);
                                        folders->folder[i].numMessages = j + 1;
                                        j++;
                                        fgets(temp1, MAXLENGTH50, optionsFile);
                                        i = 0;
                                    }

                                } while (e != 1);
                            }

                        }
                    } else {
                        strcpy(folders->folder[i].folderName, temp1);
                        folders->folder[i].numMessages = 0;
                        folders->numFolders++;
                    }
                } else if (strstr(temp1, "Messages:") != NULL) {
                    sscanf(temp1, "%s", temp2);
                }
                i++;
            }
        }
    }

    printf(COLOR_GREEN "Load complete \n" COLOR_RESET);

}

void saveOptions(sFolders *folders) { //Sirve para guardar la configuración con los cambios anteriormente echos

    char temp[MAXLENGTH50] = "";
    strcpy(temp, "");
    strcpy(myTxt, "");

    strcat(myTxt, "\n\n");
    strcat(myTxt, "Folders:\n");
    for (int i = 0; i < folders->numFolders; i++) {
        if (strcmp(folders->folder[i].folderName, "NULL") != 0) {
            strcat(myTxt, folders->folder[i].folderName);
            strcat(myTxt, "\n");
        }
    }
    strcat(myTxt, "\n");
    for (int i = 0; i < folders->numFolders; i++) {
        if (strcmp(folders->folder[i].folderName, "NULL") != 0) {
            strcat(temp, folders->folder[i].folderName);
            strcat(temp, " Messages: \n");
            strcat(myTxt, temp);
            strcpy(temp, "");
            int numMsg = folders->folder[i].numMessages;
            for (int j = 0; j < numMsg; j++) {
                if (strcmp(folders->folder[i].messageName[j].messageName, "NULL") != 0) { 
                    strcat(myTxt, folders->folder[i].messageName[j].messageName);
                    strcat(myTxt, "\n");
                } else if (strcmp(folders->folder[i].messageName[j].messageName, "NULL") == 0) { 
                    numMsg++;
                }
            }
            strcat(myTxt, "\n\n");
        }
    }
    strcat(myTxt, "\n\n");
    strcat(myTxt, "End");
    
    FILE *fp;
    fp = fopen("EMDB/EMconfig.txt", "wt");
    fprintf(fp, "messageID: %i", folders->messageID);
    fprintf(fp, myTxt);
    fclose(fp);
}

void eliminateJumps(sFolders *folders) { //Elimina saltos de linias en carpetas
    for (int i = 0; i < folders->numFolders; i++) {
        for (int e = 0; e < strlen(folders->folder[i].folderName); e++) {
            if (folders->folder[i].folderName[e] == '\n' || folders->folder[i].folderName[e] == '\r') {
                folders->folder[i].folderName[e] = '\0';
            }
        }
    }
}

void eliminateJumpsMsg(sFolders *folders, char folderName[MAXLENGTH50]) { //ELimina saltos de linia en mensajes
    eliminateJumps(folders);
    for (int i = 0; i < folders->numFolders; i++) {
        if (strcmp(folderName, folders->folder[i].folderName) == 0) {
            for (int o = 0; o < folders->folder[i].numMessages; o++) {
                for (int a = 0; a < strlen(folders->folder[i].messageName[o].messageName); a++) {
                    if (folders->folder[i].messageName[o].messageName[a] == '\n' || folders->folder[i].messageName[o].messageName[a] == '\r'
                            || folders->folder[i].messageName[o].messageName[a] == ' ') {
                        folders->folder[i].messageName[o].messageName[a] = '\0';
                    }
                }
            }
        }
    }
}