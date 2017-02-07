#include <stdio.h>
#include <stdlib.h>
#include "message.h"
#include "filesOperations.h"
#include <string.h>


char deleteFolder(char folderName[MAXLENGTH50]){
    remove(folderName);
    int ret = remove(folderName);
    if (ret == 0) {
        printf("La carpeta se ha podido borrar");
    } else {
        printf("La carpeta no se ha podido borrar o no existe\n");
    }
}
//    return "Delete Folder";


char createFolder(char folderName[MAXLENGTH50], sFolders *folders) {
   /*FILE * fp;
   fp = fopen ("EMconfig.txt", "w+");
   fprintf(fp, "%s",folderName);*/
   //printf("%s",folders->folder[numFolders].folderName);
    
    int repeat = FALSE;
    
    if (numFolders == MAXFOLDERS){
        printf("Numero de carpetas superado!!");
    }else{
        for(int i= 0; i< numFolders; i++){
          if(strcmp(folderName, folders->folder[i].folderName) == 0){
              printf("No se puede repetir el nombre!!!");
              repeat = TRUE;
            }  
        }
        
        if(repeat == FALSE){
            strcpy(folders->folder[numFolders].folderName, folderName);   
            folders->folder[numFolders].numMessages = 0;
            numFolders++;
            folders->folder[numFolders].private = FALSE;
        }
    }

 
//   fclose(fp);
//   return(0); 
   //  return "Create Folder";
}