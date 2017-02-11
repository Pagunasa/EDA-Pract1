
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "message.h"
#include "filesOperations.h"
#include "errors.h"

void closeFile(FILE fp) {
    //fclose(fp);
}

void editOptions(char newoptionsvalues) {
    //    return "message";

}

void openOptions(sFolders *folders) {
    char temp1[MAXLENGTH50];
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
            //fscanf(optionsFile, "%s", folders.folder[i].folderName);
            fgets(temp1, MAXLENGTH50, optionsFile);
            /* i++;
             fgets(folders.folder[i].folderName, MAXLENGTH50, optionsFile);
             printf("%s", folders.folder[i].folderName);
             i++;*/

            if (strcmp(temp1, "\n") == 0 || strcmp(temp1, "\r\n") == 0) {
                /*j = i;
                fgets(temp1, MAXLENGTH50, optionsFile);
                sscanf(temp1, "%s %s", temp2, strFinal);
                i--;
               // printf("%s \n", temp2);
                
                strcpy(temp1, folders.folder[i].folderName);
                  
                for (int i = 0; i <= j; i++){
                    if(strcmp(folders.folder[i].folderName, temp1) == 0){
                        fgets(folders.folder[i].messageName[e].messageName, MAXLENGTH50, optionsFile);
                       // fgets(folders.folder[i].messageName[e], MAXLENGTH50, optionsFile);
                        printf("%s",folders.folder[i].messageName[e].messageName);
                        e++;
                    }
                }
                
                e = 0;*/
            } else {
                //printf("%s", temp1);
                /*if (sscanf(temp1, "%s %s %s", temp2, strFinal, strFinal1)){
                    if(strcmp(strFinal1, "Messages:") == 1){
                         strcpy(folders.folder[i].folderName, temp1);
                        printf("Pasando %s", folders.folder[i].folderName);
                    } 
                }*/

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
                        //eliminateJumps(folders);   


                        //printf("%s", folders->folder[i].folderName);  
                    }
                } else if (strstr(temp1, "Messages:") != NULL) {
                    sscanf(temp1, "%s", temp2);
                    //strcat(temp2, "\r\n");
                    //printf("%s \n", temp2);  
                }
                i++;
            }

            //AAQUIII IVAAA

        }
    }

    printf(COLOR_GREEN "Load complete \n" COLOR_RESET);

}

void saveOptions(sFolders *folders) {

    char temp[MAXLENGTH50];
    strcpy(temp, "");
    strcpy(myTxt, "");

    strcat(myTxt, "\n\n");
    strcat(myTxt, "Folders:\n");
    for (int i = 0; i < folders->numFolders; i++) {
        strcat(myTxt, folders->folder[i].folderName);
        strcat(myTxt, "\n");
    }
    strcat(myTxt, "\n");
    for (int i = 0; i < folders->numFolders; i++) {
        // eliminateJumps(folders);
        if (strcmp(folders->folder[i].folderName, "NULL") != 0) {
            strcat(temp, folders->folder[i].folderName);
            strcat(temp, " Messages: \n");
            strcat(myTxt, temp);
            strcpy(temp, "");
            int numMsg = folders->folder[i].numMessages;
            for (int j = 0; j < numMsg; j++) {
                if (strcmp(folders->folder[i].messageName[j].messageName, "NULL") != 0) { //ESTA BIEN CREO
                    strcat(myTxt, folders->folder[i].messageName[j].messageName);
                    strcat(myTxt, "\n");
                } else if (strcmp(folders->folder[i].messageName[j].messageName, "NULL") == 0) { //  ESTO NSE PUEDE QUITAR
                    numMsg++;
                }
            }
            strcat(myTxt, "\n\n");
        }
    }
    strcat(myTxt, "\n\n");
    strcat(myTxt, "End");

    fp = fopen("EMDB/EMconfig.txt", "wt");
    fprintf(fp, "messageID: %i", folders->messageID);
    fprintf(fp, myTxt);
    fclose(fp);
}

void eliminateJumps(sFolders *folders) {
    for (int i = 0; i < folders->numFolders; i++) {
        for (int e = 0; e < strlen(folders->folder[i].folderName); e++) {
            if (folders->folder[i].folderName[e] == '\n' || folders->folder[i].folderName[e] == '\r') {
                folders->folder[i].folderName[e] = '\0';
            }
        }
    }
}

void eliminateJumpsMsg(sFolders *folders, char folderName[MAXLENGTH50]) {
    eliminateJumps(folders);
    for (int i = 0; i < folders->numFolders; i++) {
        //for (int e = 0; e < strlen(folders->folder[i].folderName); e++) {
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
        //}
    }
}

FILE* OpenFile(char filename[MAXLENGTH50]) {

    /* FILE *fs;
    
     fs = fopen(filename,"wt");
    
     if (fs == NULL){ //Comprobamos si el archivo se ha abierto y en su caso negativo avisamos al usuario
         printf("Error al abrir el fichero\n");
         return fs;
     } else {
         return fs;
     }*/
}

//AAQUIII IVAAA

//for (int j = 0; j < i; j++){
// if(strcmp(options.folders[i].folderName, )){
//   printf("Hola");
// }     
// }
/*for (int j = 0; j < i; j++){
   if(strcmp(options.folders[j].folderName, options.folders[i].folderName) ==  0
     || strcmp(options.folders[j].folderName, "Messages:") == 0){
                   i--;
                   printf("%s \n", options.folders[i].folderName);

                   //while(feof(optionsFile) == 0){
                   //        fscanf(optionsFile, "%s", options.folders[i].folderName);
                   //        printf("%s \n", options.folders[i].folderName); 
                   //    }
                       
                   }
   }*/
//for (int i = 0; i < 2; i++){
//printf("%s", folders->folder[i].folderName);  
//     for (int j = 0; j < 2; j++){
//printf("%s", folders->folder[i].messageName[j].messageName);  
//     }
// }