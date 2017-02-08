#include <stdio.h>
#include <stdlib.h>
#include "message.h"
#include <string.h>
#include <time.h>
#include "filesOperations.h"

void showMsg(int msgID) {
    //return "Show Message";
}

void deleteMsg(int msgID) {
    //return "Delete Message";
}

void createMessage(sMessage *message, char folderName[MAXLENGTH50], sFolders *folders) {

    char nameNtxt[MAXLENGTH50];
    strcpy(myTxt, "");
    
    sprintf(name, "%i_EDA1_email.txt", message->messageID);
    sprintf(nameNtxt, "%i_EDA1_email", message->messageID);
    
    //strcpy(name,message.messageID);

    //strcpy(name,"_EDA1_email.txt");

    // strcat(message.messageID, name);

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strcat(myTxt, "Date: ");
    strcat(myTxt, asctime(timeinfo));
    strcat(myTxt, "Message-ID: <");
    strcat(myTxt, name);
    strcat(myTxt, "> \n");
    strcat(myTxt, "Subject: ");
    strcat(myTxt, message->subject);
    strcat(myTxt, " \n");
    strcat(myTxt, "To: ");
    strcat(myTxt, message->to);
    strcat(myTxt, " \n");
    strcat(myTxt, "Cc: ");
    strcat(myTxt, message->to);
    strcat(myTxt, " \n\n");
    strcat(myTxt, message->text);
    strcat(myTxt, " \n\n");
    strcat(myTxt, message->sender);

    char abs[MAXLENGTH50];
    strcpy(abs, "");
    strcat(abs, "EMDB/");
    strcat(abs, name);

    fp = fopen(abs, "wt");

    //printf("%s", abs);

    fprintf(fp, myTxt);

    /* fprintf(fp, "Date: ");
     fprintf(fp, asctime (timeinfo));
     fprintf(fp, "Message-ID: <");
     fprintf(fp, name);
     fprintf(fp, "> \n");
     fprintf(fp, "Subject: ");
     fprintf(fp, message.subject);
     fprintf(fp, "\n");
     fprintf(fp, "To: ");
     fprintf(fp, message.sender);
     fprintf(fp, "\n");
     fprintf(fp, "Cc: ");
     fprintf(fp, message.sender);
     fprintf(fp, "\n\n");
     fprintf(fp, message.subject);
     fprintf(fp, "\n\n");
     fprintf(fp, message.sender);*/
    //strcat(myTxt, message.sender);
    //strcat(myTxt, "\n");
    //strcat(myTxt, message.subject);
    //strcat(myTxt, "\n");

    fclose(fp);
    
    addMessage(folders, nameNtxt, folderName);
        
}

void addMessage(sFolders *folders, char messageName[MAXLENGTH50],
    char folderName[MAXLENGTH50]) {

    int j = 0;
    for (int i = 0; i < folders->numFolders; i++) {
        if(strcmp(folderName, folders->folder[i].folderName) == 0){
            if( folders->folder[i].numMessages == MAXMESSAGES){
                printf("Numero màximo de mensajes excedido en esta carpeta (%i)", MAXMESSAGES);
            }else{
                j = folders->folder[i].numMessages;
                folders->folder[i].numMessages = j + 1;
//                strcat(messageName, "/n");
                //for (int e= 0; e <= folders->folder[i].numMessages; e++){
                   // if(strcmp("", folders->folder[i].messageName[e].messageName) == 0){
                   //     strcpy(folders->folder[i].messageName[e].messageName, messageName);
                   // } else if (e == folders->folder[i].numMessages){
                        strcpy(folders->folder[i].messageName[j].messageName, messageName);
                   // }
                //}
                folders->messageID = folders->messageID + 1;
                break;
            }
        }else{
            if (i == folders->numFolders - 1){
                printf("No existe la carpeta");
                break;
            }
        }
    }
    
    //eliminateJumpsMsg(folders, folderName);
}

void deleteMessage(sFolders *folders, char messageName[MAXLENGTH50]){
    int e = 0, numMsg;
    eliminateJumpsMsg(folders, "Outbox");
    for (int i = 0; i < folders->numFolders; i++) {
        if(strcmp("Outbox", folders->folder[i].folderName) == 0){
            if( folders->folder[i].numMessages == 0){
                printf("No hay mensajes en esa carpeta");
            } else {
                int numMsg = folders->folder[i].numMessages;
                for (int j = 0; j < numMsg; j++) {
                    if(strcmp(folders->folder[i].messageName[j].messageName, messageName) == 0){
                        numMsg = folders->folder[i].numMessages;
                        folders->folder[i].numMessages = numMsg - 1;
                        strcpy(folders->folder[i].messageName[j].messageName, "NULL");
                        printf("El mensaje existe, borrado correcto");
                    }else{
                        if(strcmp(folders->folder[i].messageName[j].messageName, "NULL") == 0){
                            numMsg++;
                            e--;
                        }
                        e++;
                        if (e == folders->folder[i].numMessages){
                            printf("No existe el mensaje");
                            break;
                        }
                    }
                }
            }
        }
    }
}

void inputNewMsg(sMessage *message, sFolders *folders, char folderName[MAXLENGTH50]) {
    //char c[50];
    //char d[50];
    //printf();

    message->messageID = folders->messageID + 1;

    printf("Introduce destinatario: ");
    readChain(message->to, MAXLENGTH50);

    printf("Introduce Asunto: ");
    readChain(message->subject, MAXLENGTH1000);

    printf("Escriba el mensaje: ");
    readChain(message->text, MAXLENGTH1000);

    printf("Firme con su nombre: ");
    readChain(message->sender, MAXLENGTH50);

    printf("Datos introducidos correctamente \n");

    createMessage(message, folderName, folders);
}

void moveMsg(int msgId, char folderName[50]) {
    // return "Move Message";
}

void searchInMsg(char searchParam[100]) {
    //   return "Search in Message";
}

void deleteMsgInFolder(int msgID, char folderName[50]) {

}