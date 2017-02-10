#include <stdio.h>
#include <stdlib.h>
#include "message.h"
#include "filesOperations.h"

listMsgs(char folderName[MAXLENGTH50], sList *msgList, sFolders *folders) {
    int chrono = 0;
    for (int i = 0; i < folders->numFolders; i++) {
        if (strcmp(folderName, folders->folder[i].folderName) == 0) {
            for (int z = 0; z <= folders->folder[i].numMessages; z++) {
                for (int a = 0; a < MAXLENGTH18; a++) {
                    if (strcmp(folders->folder[i].messageName[z].messageName, 
                            msgList->lsMessages[a].messages.messageName) == 0) {
                        printf("%i-%s-%i-%s\n", chrono, msgList->lsMessages[a].messages.sender,
                                strlen(msgList->lsMessages[a].messages.subject), msgList->lsMessages[a].messages.date.day);
                        chrono++;
                    }
                }
            }
        }


    }

    //return "listMsgs";
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