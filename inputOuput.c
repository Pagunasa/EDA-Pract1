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
   // scanf("%[^\n]", message.to);
    fgets(c, MAXLENGTH50, stdin);
    
    /*printf("Introduce Asunto: ");
    scanf("%[^\n]", c);
       
    printf("Escriba el mensaje: ");
    scanf("%[^\n]", message.text);
    
    printf("Firme con su nombre: ");
    scanf("%[^\n]", message.sender);*/
    
    createMessage(message);
}

void inputString(char caracter){
}


