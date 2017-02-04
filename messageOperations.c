#include <stdio.h>
#include <stdlib.h>
#include "message.h"
#include <string.h>
#include <time.h>


void showMsg(int msgID){
    //return "Show Message";
}

void deleteMsg(int msgID){
    //return "Delete Message";
}

void createMessage(sMessage message){

    sprintf(name,"EMDB/%i_EDA1_email.txt",message.messageID);
    
    //strcpy(name,message.messageID);
    
    //strcpy(name,"_EDA1_email.txt");
    
   // strcat(message.messageID, name);

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    
    strcat(myTxt, "Date: ");
    strcat(myTxt, asctime (timeinfo));
    strcat(myTxt, "Message-ID: <");
    strcat(myTxt, name);
    strcat(myTxt, "> \n");
    strcat(myTxt, "Subject: ");
    strcat(myTxt, message.subject);
    strcat(myTxt, " \n");
    strcat(myTxt, "To: ");
    strcat(myTxt, message.to);
    strcat(myTxt, " \n");
    strcat(myTxt, "Cc: ");
    strcat(myTxt, message.to);
    strcat(myTxt, " \n\n");
    strcat(myTxt, message.text);
    strcat(myTxt, " \n\n");
    strcat(myTxt, message.sender);
   
    char abs[MAXLENGTH50];
    
    strcat(abs,"Outbox/");
    strcat(abs, name);
    
    fp = fopen(abs,"wt");
    
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
}

void inputNewMsg(sMessage message){
    //char c[50];
    //char d[50];
    //printf();
    
    message.messageID = 5;
    
   printf("Introduce destinatario: ");
   readChain(message.to, MAXLENGTH50);
   
   printf("Introduce Asunto: ");
   readChain(message.subject, MAXLENGTH1000);

   printf("Escriba el mensaje: ");
   readChain(message.text, MAXLENGTH1000);

   printf("Firme con su nombre: ");
   readChain(message.sender, MAXLENGTH50);

   printf("Datos introducidos correctamente \n");
   
   createMessage(message); 
}

void moveMsg(int msgId, char folderName[50]){
   // return "Move Message";
}

void searchInMsg(char searchParam[100]){
 //   return "Search in Message";
}

void deleteMsgInFolder(int msgID, char folderName[50]){
    
}