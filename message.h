/* 
 * File:   message.h
 * Author: u140172
 *
 * Created on 24 de enero de 2017, 12:48
 */

#ifndef MESSAGE_H

#define	MESSAGE_H
#define MAXLENGTH50 50
#define MAXLENGTH500 500
#define MAXLENGTH18 18

int numMsg;
FILE *fp;
    
time_t rawtime;
struct tm * timeinfo;

char name[MAXLENGTH50];
char myTxt[MAXLENGTH500];


typedef struct{
    int messageID;
    char to[MAXLENGTH50];
    char sender[MAXLENGTH50];
    char text[MAXLENGTH500];
    char cc[MAXLENGTH50];
    char subject[MAXLENGTH500];
    char date[MAXLENGTH18];
}sMessage;

#endif	/* MESSAGE_H */

