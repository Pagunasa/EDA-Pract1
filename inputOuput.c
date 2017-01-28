#include <stdio.h>
#include <stdlib.h>
#include "message.h"

void inputInt(int integer){
    
}
outputPass(){
//    return "OK";
}

outputError(){
//    return "Error";
}

void inputNewMsg(sMessage message){
    char c[50];
    char d[50];
    //printf();
    
    message.messageID = 5;
    
   printf("Introduce destinatario: ");
   scanf("%s", message.to);
   fgets(c, MAXLENGTH50, stdin);
    
    printf("Introduce Asunto: ");
    scanf("%s",message.subject);
    fgets(c, MAXLENGTH50, stdin);
       
    printf("Escriba el mensaje: ");
    scanf("%s", message.text);
    fgets(c, MAXLENGTH500, stdin);
    
    printf("Firme con su nombre: ");
    scanf("%s", message.sender);
    fgets(c, MAXLENGTH50, stdin);
    
    createMessage(message);
}

void inputString(char caracter){
}


