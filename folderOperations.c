#include <stdio.h>
#include <stdlib.h>

char deleteFolder(char folderName[50]){
    return "Delete Folder";
}

char createFolder(char folderName[50]){
    mkdir(folderName,0777);

    return "Create Folder";
}