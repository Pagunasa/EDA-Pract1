/* 
 * File:   filesOperations.h
 *  * Autors:
    Guillem Martinez 196310
    Oriol Bernier 193518
    Sandra Rodriguez 192860
 * Definicon de algunas de las variables prototipo del filesOperations y messageOperations y del structs para su uso.
 * Created on 24 de enero de 2017, 12:48
 */

#include "message.h"

#ifndef FILESOPERATIONS_H
#define	FILESOPERATIONS_H

#define MAXLENGTH50 50
#define MAXLENGTH20 20
#define MAXFOLDERS 4
#define MAXMESSAGES 4
#define MAXMSGFOLDER 4
#define TRUE 0
#define FALSE 1

int numFolders;

typedef struct{
    char messageName[MAXLENGTH50];
} sMessageName;

typedef struct{
    sMessageName messageName[MAXMESSAGES];
    char folderName[MAXLENGTH20];
    int posicio[MAXMSGFOLDER];
    int numMessages;
    int private;
}sFolder; 

typedef struct{
    int messageID;
    int numFolders;
    sFolder folder[MAXFOLDERS];
}sFolders;

void openOptions(sFolders *folders);
void saveOptions(sFolders *folders);
void eliminateJumps(sFolders *folders);
void eliminateJumpsMsg(sFolders *folders, char folderName[MAXLENGTH50]);
void deleteFolder(char folderName[MAXLENGTH50], sFolders *folders, sList *msgList);
void setPrivateOPublic(sFolders *folders);
void createFolder(char folderName[MAXLENGTH50], sFolders *folders);
int readChain(char *cad, int n);
void listMsgs(char folderName[MAXLENGTH50], sList *msgList, sFolders *folders);
void listAllMsgs(sList *msgList);
void inicializeList(sList *msgList);

void deleteMessage(sFolders *folders, sList *msgList, char messageName[MAXLENGTH50], char foldername[MAXLENGTH50]);
void inputNewMsg(sMessage *message, sFolders *folders, char folderName[MAXLENGTH50]);

void chargeMessages(sList *msgList, sFolders *folders);
void createMessage(sMessage *message, char folderName[MAXLENGTH50], sFolders *folders);

void addMessage(sFolders *folders, char messageName[MAXLENGTH50], char folderName[MAXLENGTH50]);

#endif	/* FILESOPERATIONS_H */

