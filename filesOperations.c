
#include <stdio.h>
#include <stdlib.h>
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
   
    int i, j;
    
    FILE * optionsFile;
    
    optionsFile = fopen("EMconfig.txt", "r");
    
    if (optionsFile == NULL){
        printf("El archivo no existe \n");
    }else{
        printf("El archivo existe \n");
        
        fscanf(optionsFile, "%s %d", temporal, &options.idMessage);
        
        while(feof(optionsFile) == 0){
            i++;
            fscanf(optionsFile, "%s", temporal);
            //printf("%s \n", temporal); 
            if(i > 2){
                fscanf(optionsFile, "%s", options.folders);
                printf("%s \n", options.folders);  
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
