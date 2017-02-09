#include <stdio.h>
#include <stdlib.h>
#include "message.h"
#include "filesOperations.h"
#include <string.h>
#include "errors.h"

void deleteFolder(char folderName[MAXLENGTH50], sFolders *folders) {
    int confirmation;
    int pass = 1, exists = 0;
    
    for (int i = 0; i < folders->numFolders; i++) {
        if (strcmp(folderName, folders->folder[i].folderName) == 0) {
            exists = 1;
            if (folders->folder[i].private == TRUE) {
                printf("Carpeta privada no se puede borrar!!!\n");
            } else {
                while(pass != 0){
                    printf("Estas seguro que quieres borrar la carpeta? \n\t1-Si \n\t0-No \n\t");
                    scanf("%i", &confirmation);
                    if(confirmation == 1 || confirmation == 0){
                        pass = 0;
                    }else{
                        pass = 1;
                    }
                };
                if (confirmation == 1) {
                    printf("Carpeta borrada \n");
                } else {
                    printf("Carpeta no borrada \n");
                }
            }
            //folders->folder[i].folderName
        } else {
            if (i == folders->numFolders-1 && exists == 0) {
                printf("No existe esa carpeta!!! \n");
            }
        }
    }
    //    remove(folderName);
    //    int ret = remove(folderName);
    //    if (ret == 0) {
    //        printf("La carpeta se ha podido borrar");
    //    } else {
    //        printf("La carpeta no se ha podido borrar o no existe\n");
    //    }
}
//    return "Delete Folder";

void setPrivateOPublic(sFolders *folders) {
    for (int i = 0; i < folders->numFolders; i++) {
        if (strcmp(folders->folder[i].folderName, "Inbox") == 0
                || strcmp(folders->folder[i].folderName, "Outbox") == 0) {
            folders->folder[i].private = TRUE;
        } else {
            folders->folder[i].private = FALSE;
        }
    }
}

void createFolder(char folderName[MAXLENGTH50], sFolders *folders) {
    /*FILE * fp;
    fp = fopen ("EMconfig.txt", "w+");
    fprintf(fp, "%s",folderName);*/
    //printf("%s",folders->folder[numFolders].folderName);

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


    //   fclose(fp);
    //   return(0); 
    //  return "Create Folder";
}