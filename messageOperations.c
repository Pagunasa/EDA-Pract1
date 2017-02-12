#include <stdio.h>
#include <stdlib.h>
#include "message.h"
#include <string.h>
#include <time.h>
#include "errors.h"
#include "filesOperations.h"

void showMsg(sList *msgList, char messageName[MAXLENGTH50]) {
    //    for (int i = 0; i < folders->numFolders; i++) {
    for (int e = 0; e < MAXLENGTH18; e++) {
        if (strcmp(messageName, msgList->lsMessages[e].messages.messageName) == 0) {
            printf("%s \n\n", msgList->lsMessages[e].messages.body);
        }
    }
    //    }
}

void chargeMessages(sList *msgList, sFolders *folders) { //carga los mensajes de emoptions a la lista de mensajes 

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
                    } else if (strcmp(temp, "Subject:") == 0) {
                        fscanf(message, "%s", temp);
                        strcpy(msgList->lsMessages[pos].messages.subject, temp);
                        bodySender++;
                    } else if (strcmp(temp, "To:") == 0) {
                        fgets(temp, MAXLENGTH1000, message);
                        strcpy(msgList->lsMessages[pos].messages.to, temp);
                        bodySender++;
                    } else if (strcmp(temp, "Cc:") == 0) {
                        fgets(temp, MAXLENGTH1000, message);
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
                        strcpy(msgList->lsMessages[pos].messages.body, bodyTemp);
                        strcpy(msgList->lsMessages[pos].messages.sender, senderTemp);
                    }
                }
                fclose(message);
                pos++;
            }



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

    strcpy(message->messageName, nameNtxt);

    time_t rawtime;
    struct tm * timeinfo;
    
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
    
    FILE *fp;
    fp = fopen(abs, "wt");
    fprintf(fp, myTxt);

    fclose(fp);

    addMessage(folders, nameNtxt, folderName);

}

void addMessageToList(sMessage *message, sList *msgList) {
    int posEmpty = msgList->empty;
    int nextEmpty = msgList->lsMessages[posEmpty].next;
    int posFirst = msgList->first;
    char messageNameTmp1[MAXLENGTH50];

    msgList->empty = nextEmpty;
    msgList->first = posEmpty;

    msgList->lsMessages[posFirst].next = posEmpty;
    msgList->lsMessages[posEmpty].prev = posFirst;
    msgList->lsMessages[posEmpty].next = -1;
    msgList->lsMessages[nextEmpty].prev = -1;

    sprintf(messageNameTmp1, "<%s>", message->messageName);

    strcpy(msgList->lsMessages[posEmpty].messages.messageName, messageNameTmp1);
    strcpy(msgList->lsMessages[posEmpty].messages.body, message->body);
    strcpy(msgList->lsMessages[posEmpty].messages.cc, message->cc);

    strcpy(msgList->lsMessages[posEmpty].messages.date.day, message->date.day);
    strcpy(msgList->lsMessages[posEmpty].messages.date.hour, message->date.hour);
    strcpy(msgList->lsMessages[posEmpty].messages.date.month, message->date.month);
    strcpy(msgList->lsMessages[posEmpty].messages.date.nDay, message->date.nDay);
    strcpy(msgList->lsMessages[posEmpty].messages.date.year, message->date.year);

    strcpy(msgList->lsMessages[posEmpty].messages.sender, message->sender);
    strcpy(msgList->lsMessages[posEmpty].messages.subject, message->subject);
    strcpy(msgList->lsMessages[posEmpty].messages.to, message->to);
}

void addMessage(sFolders *folders, char messageName[MAXLENGTH50],
        char folderName[MAXLENGTH50]) {  //Añade un mensaje al srtuct de mensajes

    int j = 0;
    for (int i = 0; i < folders->numFolders; i++) {
        if (strcmp(folderName, folders->folder[i].folderName) == 0) {
            if (folders->folder[i].numMessages == MAXMESSAGES) {
                printf("Numero màximo de mensajes excedido en esta carpeta (%i)", MAXMESSAGES);
            } else {
                j = folders->folder[i].numMessages;
                folders->folder[i].numMessages = j + 1;
                strcpy(folders->folder[i].messageName[j].messageName, messageName);
                folders->messageID = folders->messageID + 1;
                break;
            }
        } else {
            if (i == folders->numFolders - 1) {
                printf("No existe la carpeta");
            }
        }
    }
}

void deleteMessageFromList(sList *msgList, char messageName[MAXLENGTH50]) { //Borra un mensaje de la lista
    for (int e = 0; e < MAXLENGTH18; e++) {
        if (strcmp(messageName, msgList->lsMessages[e].messages.messageName) == 0) {
            
            int prevMsg = msgList->lsMessages[e].prev;
            int nextMsg = msgList->lsMessages[e].next;
            int fristMsg = msgList->first;
            int fristEmpty = msgList->empty;
            int nextToEmpty;
            int nexte = e + 1;

            do {
                nextToEmpty = msgList->lsMessages[fristEmpty].next;
                fristEmpty++;
            } while (msgList->lsMessages[nextToEmpty].next != -1);

            if (e == fristMsg) {
                msgList->first = msgList->lsMessages[e].prev;
            }

            if (e == 0) {
                msgList->lsMessages[nextMsg].prev = -1;
            } else {
                msgList->lsMessages[prevMsg].next = msgList->lsMessages[e].next;
                if (fristEmpty == nexte) {

                } else {
                    msgList->lsMessages[nextMsg].prev = msgList->lsMessages[e].prev;
                }
            }

            msgList->empty = e;
            msgList->lsMessages[fristEmpty].next = e;
            msgList->lsMessages[e].next = -1;
            msgList->lsMessages[e].prev = fristEmpty;
            msgList->lsMessages[e].messages.messageID = -1;
            strcpy(msgList->lsMessages[e].messages.messageName, "EMPTY_MESSAGE");
        }
    }
}

void deleteMessage(sFolders *folders, sList *msgList, char messageName[MAXLENGTH50], char foldername[MAXLENGTH50]) { //Sirve para borrar el mensaje dependiendo de las condiciones
    int e = 0, repeat = 0;
    int confirmation, pass = 1;

    char messageNameTmp[MAXLENGTH50];
    char messageNameTmp1[MAXLENGTH50];

    eliminateJumpsMsg(folders, foldername);
    for (int i = 0; i < folders->numFolders; i++) {
        if (strcmp(foldername, folders->folder[i].folderName) == 0) {
            if (folders->folder[i].numMessages == 0) {
                printf("No hay mensajes en esa carpeta");
            } else {
                int numMsg = folders->folder[i].numMessages;
                for (int j = 0; j < numMsg; j++) {
                    if (strcmp(folders->folder[i].messageName[j].messageName, messageName) == 0) {

                        sprintf(messageNameTmp1, "<%s>", messageName);
                        showMsg(msgList, messageNameTmp1);

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
                                    deleteMessageFromList(msgList, messageNameTmp1);
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

void inputNewMsg(sMessage *message, sFolders *folders, char folderName[MAXLENGTH50]) { //Introducir la información para crear un mensaje

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

void searchInMsg(sList *msgList, char searchParam[MAXLENGTH50]) { //Sirve para buscar una cadena en todos los correos en los que este se veran por pantalla
    int chrono = 0, end = 0, isInside = 0;
    int pos = msgList->first;

    while (end != 1) {
        
        isInside = 0;
        if (strstr(msgList->lsMessages[pos].messages.body, searchParam) != 0) {
            isInside++;
        }
        if (strstr(msgList->lsMessages[pos].messages.cc, searchParam) != 0) {
            isInside++;
        }
        if (strstr(msgList->lsMessages[pos].messages.messageName, searchParam) != 0) {
            isInside++;
        }
        if (strstr(msgList->lsMessages[pos].messages.sender, searchParam) != 0) {
            isInside++;
        }
        if (strstr(msgList->lsMessages[pos].messages.subject, searchParam) != 0) {
            isInside++;
        }
        if (strstr(msgList->lsMessages[pos].messages.to, searchParam) != 0) {
            isInside++;
        }
        if (strstr(msgList->lsMessages[pos].messages.date.day, searchParam) != 0) {
            isInside++;
        }
        if (strstr(msgList->lsMessages[pos].messages.date.hour, searchParam) != 0) {
            isInside++;
        }
        if (strstr(msgList->lsMessages[pos].messages.date.month, searchParam) != 0) {
            isInside++;
        }
        if (strstr(msgList->lsMessages[pos].messages.date.nDay, searchParam) != 0) {
            isInside++;
        }
        if (strstr(msgList->lsMessages[pos].messages.date.year, searchParam) != 0) {
            isInside++;
        }
        
        if (isInside != 0) {
            printf("%i-%s-%i-%s -> Ref: %s\n", chrono, msgList->lsMessages[pos].messages.sender,
                    strlen(msgList->lsMessages[pos].messages.subject), msgList->lsMessages[pos].messages.date.day,
                    msgList->lsMessages[pos].messages.messageName);
            chrono++;
        }

        if (msgList->lsMessages[pos].prev == -1) {
            end = 1;
        }
        
        pos = msgList->lsMessages[pos].prev;
    }
}