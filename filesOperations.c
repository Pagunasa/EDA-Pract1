
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "message.h"
#include "filesOperations.h"


void closeFile(FILE fp){
    //fclose(fp);
}

void editOptions(char newoptionsvalues){
//    return "message";
    
}

void openOptions(sFolders *folders){
    char temp1[MAXLENGTH50];
    char temp2[MAXLENGTH50] = "";

    int i = 0;
    int j = 0;
    int e = 0;
    
    FILE * optionsFile;
    
    optionsFile = fopen("EMDB/EMconfig.txt", "r");
    
    if (optionsFile == NULL){
        printf("El archivo no existe \n");
    }else{
        printf("El archivo existe \n");
        
       fscanf(optionsFile, " %s %d ", temp1, &folders->messageID);
       fscanf(optionsFile, "%s", temp1);

       while(feof(optionsFile) == 0){       
            //fscanf(optionsFile, "%s", folders.folder[i].folderName);
            fgets(temp1, MAXLENGTH50, optionsFile);
           /* i++;
            fgets(folders.folder[i].folderName, MAXLENGTH50, optionsFile);
            printf("%s", folders.folder[i].folderName);
            i++;*/
            
            if (strcmp(temp1, "\n") == 0 || strcmp(temp1, "\r\n") == 0){
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
                
                if (strstr(temp1, "Messages:") == NULL && strstr(temp1, "End") == NULL){
                    if(strcmp(temp2, "") != 0){
                        j = 0;
                        for (int i = 0; i <= MAXMESSAGES; i++){
                            if (strstr(folders->folder[i].folderName, temp2)){
                                do{
                                    if (strcmp(temp1, "\n") == 0 || strcmp(temp1, "\r\n") == 0){
                                        if(strcmp(temp1, "\r\n") == 0){
                                            e = 1 ;
                                            i = MAXMESSAGES;          
                                        }else{
                                            fgets(temp1, MAXLENGTH50, optionsFile);
                                        }
                                    }else{
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
                        numFolders++;
                        //printf("%s", folders->folder[i].folderName);  
                    }
                }else if(strstr(temp1, "Messages:") != NULL){
                    sscanf(temp1, "%s", temp2);
                    //strcat(temp2, "\r\n");
                    //printf("%s \n", temp2);  
                }
                i++;
            }

            //AAQUIII IVAAA
            
            }
        }

    printf("Load complete \n");
    
    }


void saveOptions(sFolders *folders){

    strcat(myTxt, "\n\n");
    strcat(myTxt, "Folders:\n");
    for(int i=0; i < numFolders; i++){
        strcat(myTxt, folders->folder[i].folderName);
    }
    strcat(myTxt, "\n");
    for(int i=0; i < numFolders; i++){
        strcat(myTxt, folders->folder[i].folderName);
        for(int j=0; j <  folders->folder[i].numMessages; j++){
            strcat(myTxt, folders->folder[i].messageName[j].messageName);
        }
        strcat(myTxt, "\n");
    }
    strcat(myTxt, "\n\n");
    strcat(myTxt, "End");
    
    fp = fopen ("EMconfig.txt", "wt");
    fprintf(fp, "messageID: %i", folders->messageID);
    fprintf(fp, myTxt);
    fclose(fp);
}

void addMessage(sFolders *folders, char messageName[MAXLENGTH50], 
        char folderName[MAXLENGTH50]){
        int j = 0;
        for(int i=0; i < numFolders; i++){
            /*if(strcmp(folderName, folders->folder[i].folderName) == 0){
                j = folders->folder[i].numMessages + 1;
                folders->folder[i].numMessages = j;
                strcpy(folders->folder[i].messageName[j].messageName, messageName);  
            }else{
                printf("No existe la carpeta");
            }*/
        }
}

FILE* OpenFile(char filename[MAXLENGTH50]){
    
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