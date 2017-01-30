
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

void openOptions(sOptions options){
    char temporal[MAXLENGTH50];
   
    int i = 0;
    int j = 0;
    
    FILE * optionsFile;
    
    optionsFile = fopen("EMconfig.txt", "r");
    
    if (optionsFile == NULL){
        printf("El archivo no existe \n");
    }else{
        printf("El archivo existe \n");
        
        fscanf(optionsFile, "%s %d", temporal, &options.idMessage);
        fscanf(optionsFile, "%s", temporal);

        while(feof(optionsFile) == 0){       
            
            fscanf(optionsFile, "%s", options.folders[i].folderName);
            i++;

            for (int j = 0; j < i; j++){
                 if(strcmp(options.folders[j].folderName, options.folders[i].folderName) ==  0
                    || strcmp(options.folders[j].folderName, "Messages:") == 0){
                    i--;
                    printf("%s \n", options.folders[i].folderName);

                    //while(feof(optionsFile) == 0){
                    //        fscanf(optionsFile, "%s", options.folders[i].folderName);
                    //        printf("%s \n", options.folders[i].folderName); 
                    //    }
                       
                    }
                }
            }
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
