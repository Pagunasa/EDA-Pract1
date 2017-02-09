#include <stdio.h>
#include <stdlib.h>
#include "message.h"


listMsgs(int folderName){

//return "listMsgs";
}

listFolder (){
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