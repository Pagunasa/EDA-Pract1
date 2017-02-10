#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "message.h"
#include "filesOperations.h"

void listMsgs(char folderName[MAXLENGTH50], sList *msgList, sFolders *folders) {
    int chrono = 1, inFolder = 0;
    for (int i = 0; i < folders->numFolders; i++) {
        if (strcmp(folderName, folders->folder[i].folderName) == 0) {
            if (folders->folder[i].numMessages == 0)printf(COLOR_RED "No hay mensajes" COLOR_RESET);
            inFolder = 1;
            for (int z = 0; z < folders->folder[i].numMessages; z++) {
                for (int a = 0; a < MAXLENGTH18; a++) {
                    if (strcmp(folders->folder[i].messageName[z].messageName,
                            msgList->lsMessages[a].messages.messageName) == 0) {
                        printf("%i-%s-%i-%s Ref: %s\n", chrono, msgList->lsMessages[a].messages.sender,
                                strlen(msgList->lsMessages[a].messages.subject), msgList->lsMessages[a].messages.date.day,
                                msgList->lsMessages[a].messages.messageName);
                        chrono++;
                        if (msgList->lsMessages[a].next == -1) {
                            a = MAXLENGTH18;
                        }
                    }
                }
            }
            //i = folders->numFolders;
        }//else if(inFolder == 0){
        //            printf(COLOR_RED "No existe la carpeta\n" COLOR_RESET);
        //        }
        inFolder = 0;
    }
}

void listAllMsgs(sList *msgList) {
    int chrono = 1;
    for (int a = 0; a < MAXLENGTH18; a++) {
        printf("%i-%s-%i-%s Ref: %s\n", chrono, msgList->lsMessages[a].messages.sender,
                strlen(msgList->lsMessages[a].messages.subject), msgList->lsMessages[a].messages.date.day,
                msgList->lsMessages[a].messages.messageName);
        chrono++;
        if (msgList->lsMessages[a].next == -1) {
            a = MAXLENGTH18;
        }
    }
}

listFolder() {
    //  return"Array of folders";

}

void inicializeList(sList *msgList) {
    msgList->empty = 0;
    msgList->first = -1;

    for (int i = 0; i < MAXLENGTH18; i++) {
        if (i == 0) {
            msgList->lsMessages[i].prev = -1;
        } else {
            msgList->lsMessages[i].prev = i - 1;
        }
        if ((i + 1) == MAXLENGTH18) {
            msgList->lsMessages[i].next = -1;
        } else {
            msgList->lsMessages[i].next = i + 1;
        }
    }
}