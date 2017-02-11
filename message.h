/* 
 * File:   message.h
 * Author: u140172
 *
 * Created on 24 de enero de 2017, 12:48
 */

#ifndef MESSAGE_H

#define	MESSAGE_H
#define MAXLENGTH50 50
#define MAXLENGTH1000 1000
#define MAXLENGTH18 18

int numMsg;
//FILE *fp;
    
//time_t rawtime;
//struct tm * timeinfo;



char name[MAXLENGTH50];
char myTxt[MAXLENGTH1000];

typedef struct{
    char day[MAXLENGTH18];
    char month[MAXLENGTH18];
    char nDay[MAXLENGTH18];
    char hour[MAXLENGTH18];
    char year[MAXLENGTH18];
}sDateTime;

typedef struct{
    int messageID;
    char messageName[MAXLENGTH50];
    char to[MAXLENGTH50];
    char sender[MAXLENGTH50];
    char body[MAXLENGTH1000];
    char cc[MAXLENGTH50];
    char subject[MAXLENGTH1000];
    sDateTime date;
}sMessage;

typedef struct{
    sMessage messages;
    int next;
    int prev;
}sLsMsg;

typedef struct{
    sLsMsg lsMessages[MAXLENGTH18];
    int first;
    int empty;
}sList; 

#endif	/* MESSAGE_H */

