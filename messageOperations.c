#include <stdio.h>
#include <stdlib.h>
#include "message.h"
#include <string.h>
#include <time.h>
#include "errors.h"
#include "filesOperations.h"

void deleteMsg(int msgID) {
    //return "Delete Message";
}

void showMsg(sList *msgList, char messageName[MAXLENGTH50]) {
    //    for (int i = 0; i < folders->numFolders; i++) {
    for (int e = 0; e < MAXLENGTH18; e++) {
        if (strcmp(messageName, msgList->lsMessages[e].messages.messageName) == 0) {
            printf("%s \n\n", msgList->lsMessages[e].messages.body);
        }
    }
    //    }
}

void chargeMessages(sList *msgList, sFolders *folders) { //no se tien que duplicar 

    typedef struct {
        char name[MAXLENGTH50];
    } sName;

    typedef struct {
        sName name[MAXLENGTH18];
    } sCharNames;

    sCharNames charNames;

    FILE * message;
    char temp[MAXLENGTH1000], bodyTemp[MAXLENGTH1000], senderTemp[MAXLENGTH50];
    char day[MAXLENGTH18], nDay[MAXLENGTH18], month[MAXLENGTH18], hour[MAXLENGTH18], year[MAXLENGTH18];
    int pos = 0;
    int fristMsg;
    int isRepeat = 0, isSave = 0, bodySender = 0, isSender = 0;

    for (int i = 0; i < folders->numFolders; i++) {
        for (int j = 0; j < folders->folder[i].numMessages; j++) {

            strcpy(bodyTemp, "");

            for (int e = 0; e <= pos; e++) {
                if (strcmp(charNames.name[e].name, folders->folder[i].messageName[j].messageName) != 0) {

                    if (isRepeat == pos) {
                        strcpy(charNames.name[pos].name, folders->folder[i].messageName[j].messageName);
                        isSave = 1;
                    }
                    isRepeat++;

                } else {
                    printf(COLOR_RED "El mensaje ya ha sido introducido anteriormente!! \n" COLOR_RESET);

                }
            }

            if (isSave == 1) {
                char messageName[MAXLENGTH50];
                strcpy(messageName, "");
                sprintf(messageName, "EMDB/%s.txt", folders->folder[i].messageName[j].messageName);

                message = fopen(messageName, "r");

                fristMsg = msgList->first;
                msgList->empty = msgList->lsMessages[pos].next;
                msgList->first = msgList->lsMessages[pos + 1].prev;
                if (pos == 0) {
                    msgList->lsMessages[pos + 1].prev = msgList->lsMessages[pos].prev;
                    msgList->lsMessages[pos].next = -1;
                } else {
                    msgList->lsMessages[pos].next = -1;
                    msgList->lsMessages[pos - 1].next = pos;
                    msgList->lsMessages[pos].prev = msgList->first - 1;
                    msgList->lsMessages[pos + 1].prev = -1;
                }

                while (feof(message) == 0) {
                    fscanf(message, "%s", temp);
                    //fgets(temp, MAXLENGTH50, message);
                    if (strcmp(temp, "Date:") == 0) {
                        fscanf(message, "%s", day);
                        fscanf(message, "%s", month);
                        fscanf(message, "%s", nDay);
                        fscanf(message, "%s", hour);
                        fscanf(message, "%s", year);

                        strcpy(msgList->lsMessages[pos].messages.date.day, day);
                        strcpy(msgList->lsMessages[pos].messages.date.month, month);
                        strcpy(msgList->lsMessages[pos].messages.date.nDay, nDay);
                        strcpy(msgList->lsMessages[pos].messages.date.hour, hour);
                        strcpy(msgList->lsMessages[pos].messages.date.year, year);
                    } else if (strcmp(temp, "Message-ID:") == 0) {
                        fscanf(message, "%s", temp);
                        strcpy(msgList->lsMessages[pos].messages.messageName, temp);
                        bodySender++;
                        //strcpy(msgList->lsMessages[j].messages.messageID, temp);
                    } else if (strcmp(temp, "Subject:") == 0) {
                        fscanf(message, "%s", temp);
                        strcpy(msgList->lsMessages[pos].messages.subject, temp);
                        bodySender++;
                    } else if (strcmp(temp, "To:") == 0) {
                        fscanf(message, "%s", temp);
                        strcpy(msgList->lsMessages[pos].messages.to, temp);
                        bodySender++;
                    } else if (strcmp(temp, "Cc:") == 0) {
                        fscanf(message, "%s", temp);
                        strcpy(msgList->lsMessages[pos].messages.cc, temp);
                        bodySender++;
                    }

                    if (bodySender == 4) {

                        while (feof(message) == 0) {
                            fgets(temp, MAXLENGTH1000, message);
                            strcat(bodyTemp, temp);

                            if (strcmp(temp, "\r\n") == 0) {
                                isSender++;
                            }

                            if (isSender == 2) {
                                strcpy(senderTemp, temp);
                            }
                        }
                        //fscanf(message, "%s", temp);
                        strcpy(msgList->lsMessages[pos].messages.body, bodyTemp);
                        //                        fscanf(message, "%s", temp);
                        strcpy(msgList->lsMessages[pos].messages.sender, senderTemp);
                    }
                }
                fclose(message);
            }

            pos++;
            isRepeat = 0;
            isSender = 0;
            isSave = 0;
            bodySender = 0;
        }
    }
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
    strcat(myTxt, nameNtxt);
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
    strcat(myTxt, message->body);
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
        if (strcmp(folderName, folders->folder[i].folderName) == 0) {
            if (folders->folder[i].numMessages == MAXMESSAGES) {
                printf("Numero màximo de mensajes excedido en esta carpeta (%i)", MAXMESSAGES);
            } else {
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
        } else {
            if (i == folders->numFolders - 1) {
                printf("No existe la carpeta");
            }
        }
    }

    //eliminateJumpsMsg(folders, folderName);
}

void deleteMessageFromList(sList *msgList, char messageName[MAXLENGTH50]) {
    for (int e = 0; e < MAXLENGTH18; e++) {
        if (strcmp(messageName, msgList->lsMessages[e].messages.messageName) == 0) {
            //printf("%s \n\n", msgList->lsMessages[e].messages.body);

            //            if(e != 0){
            //                msgList->lsMessages[e-1].next = msgList->lsMessages[e].next;
            //            }else{
            //                msgList->lsMessages[e].next = -1;
            //            }  
            //            
            //            if (e = msgList->first){
            //                msgList->first = msgList->lsMessages[e].prev;
            //            }
            //            
            //            msgList->lsMessages[msgList->empty].prev = e;
            //            msgList->lsMessages[msgList->empty].next = e + 1;
            //            msgList->lsMessages[e].messages.messageID = -1;
            int ante = e - 1;
            int prevMsg = msgList->lsMessages[e].prev;
            int nextMsg = msgList->lsMessages[e].next;
            
            if (e = msgList->first){
                msgList->first = msgList->lsMessages[e].prev;
            }
            
            if (e != 0) {
                msgList->lsMessages[ante].next = msgList->lsMessages[e].next;
            }
            
            msgList->lsMessages[e].prev = msgList->empty;
            msgList->lsMessages[e + 1].prev = msgList->lsMessages[e].prev;
            msgList->lsMessages[msgList->empty].next = e;
            
            msgList->empty = e;
            
            msgList->lsMessages[e].messages.messageID = -1;

        }
    }
}

void deleteMessage(sFolders *folders, sList *msgList, char messageName[MAXLENGTH50], char foldername[MAXLENGTH50]) {
    int e = 0, repeat = 0;
    int confirmation, pass = 1;

    char messageNameTmp[MAXLENGTH50];
    eliminateJumpsMsg(folders, foldername);
    for (int i = 0; i < folders->numFolders; i++) {
        if (strcmp(foldername, folders->folder[i].folderName) == 0) {
            if (folders->folder[i].numMessages == 0) {
                printf("No hay mensajes en esa carpeta");
            } else {
                int numMsg = folders->folder[i].numMessages;
                for (int j = 0; j < numMsg; j++) {
                    if (strcmp(folders->folder[i].messageName[j].messageName, messageName) == 0) {

                        showMsg(msgList, messageName);

                        while (pass != 0) {
                            printf("Estas seguro que quieres borrar el correo? \n\t1-Si \n\t0-No \n\t");
                            scanf("%i", &confirmation);
                            if (confirmation == 1 || confirmation == 0) {
                                pass = 0;
                            } else {
                                pass = 1;
                            }
                        }

                        if (confirmation == 0) {
                            printf("Eliminación del mensaje cancelado \n");
                        } else {
                            sprintf(messageNameTmp, "EMDB/%s.txt", messageName);

                            for (int e = 0; e < folders->numFolders; e++) {
                                for (int a = 0; a < folders->folder[e].numMessages; a++) {
                                    if (strcmp(folders->folder[e].messageName[a].messageName, messageName) == 0)
                                        repeat++;
                                }
                            }

                            if (repeat <= 1) {
                                numMsg = remove(messageNameTmp);
                                if (numMsg == 0) {
                                    printf("Mensaje eliminado fisicamente\n");
                                    deleteMessageFromList(msgList, messageName);
                                } else {
                                    printf("Error no se pudo borrar\n");
                                }
                            }
                            numMsg = folders->folder[i].numMessages;
                            folders->folder[i].numMessages = numMsg - 1;
                            strcpy(folders->folder[i].messageName[j].messageName, "NULL");
                            printf("El mensaje existe, borrado correctamente \n");
                        }
                    } else {
                        if (strcmp(folders->folder[i].messageName[j].messageName, "NULL") == 0) {
                            numMsg++;
                            e--;
                        }
                        e++;
                        if (e == folders->folder[i].numMessages) {
                            printf("No existe el mensaje \n");
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
    readChain(message->body, MAXLENGTH1000);

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