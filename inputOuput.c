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
   readChain(message.to, MAXLENGTH50);
   
   printf("Introduce Asunto: ");
   readChain(message.subject, MAXLENGTH500);

   printf("Escriba el mensaje: ");
   readChain(message.text, MAXLENGTH500);

   printf("Firme con su nombre: ");
   readChain(message.sender, MAXLENGTH50);

   printf("Introduccion de datos correcta");
   
    createMessage(message);
}

int readChain(char *cad, int n) { 
    int i, c; 

    c=getchar(); 
    if (c == EOF) { 
        cad[0] = '\0'; 
        return 0; 
    } 

    if (c == '\n') 
        i = 0; 
    else { 
        cad[0] = c; 
        i = 1; 
    } 

    for (; i < n-1 && (c=getchar())!=EOF && c!='\n'; i++) 
       cad[i] = c; 

    cad[i] = '\0'; 

    if (c != '\n' && c != EOF) 
        while ((c = getchar()) != '\n' && c != EOF); 

    return 1; 
}

void inputString(char caracter){
}


