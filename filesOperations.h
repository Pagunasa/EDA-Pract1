/* 
 * File:   filesOperations.h
 * Author: u140172
 *
 * Created on 24 de enero de 2017, 12:48
 */

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

#endif	/* FILESOPERATIONS_H */

