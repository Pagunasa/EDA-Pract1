#include <stdio.h>
#include <stdlib.h>
#include "message.h"


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


char createFolder(char folderName[50]) {
    
    printf(" %s", folderName);
    
    mkdir(folderName, 0777);
    

    //  return "Create Folder";
}