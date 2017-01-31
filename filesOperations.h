/* 
 * File:   filesOperations.h
 * Author: u140172
 *
 * Created on 24 de enero de 2017, 12:48
 */

#ifndef FILESOPERATIONS_H
#define	FILESOPERATIONS_H

#define MAXLENGTH20 20
#define MAXFOLDERS 5
#define MAXMESSAGES 4
#define MAXMSGFOLDER 4

typedef struct{ 
    char folderName[MAXLENGTH20];
    int posicio[MAXMSGFOLDER];
    int private;
    sMessage;
    
}sfolders; 

/*typedef struct{
    char messageName[MAXLENGTH20];
} sMessageName[MAXMESSAGES];

typedef struct{
    char folderName[MAXLENGTH20];
    sMessageName messages;
} sFolders[MAXFOLDERS];

//typedef struct{
//    char folderName[MAXLENGTH20];
//} sFoldersName;

typedef struct{
    int idMessage;
    //sFoldersName foldersName[MAXFOLDERS];
    sFolders folders;
} sOptions;


#endif	/* FILESOPERATIONS_H */

