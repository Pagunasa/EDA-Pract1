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

sMessage inputNewMsg(){
    sMessage message;
    
    char c[50] = "HOLAAA QUE TAL??";
    char d[50] = "Pagunasa";

    message.messageID = 5;
    strcpy(message.subject, c);
    strcpy(message.sender, d);
    
    return message;
}

void inputString(char caracter){
}


