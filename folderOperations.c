#include <stdio.h>
#include <stdlib.h>

char deleteFolder(char folderName[50]) {

    remove(folderName);
    int ret = remove(folderName);
    if (ret == 0) {
        printf("La carpeta se ha podido borrar");
    } else {
        printf("La carpeta no se ha podido borrar");
    }
}
//    return "Delete Folder";


char createFolder(char folderName[50]) {

    mkdir(folderName, 0777);

    //  return "Create Folder";
}