/* 
 * File:   main.c
 * Author: u140172
 *
 * Created on 18 de enero de 2017, 11:07
 */

#include <stdio.h>
#include <stdlib.h>
#include "message.h"
//#include "messageOperations.c"

/*
 * 
 */
int main(int argc, char** argv) {

    createFolder("Inbox");
    
    sMessage Message;
    char c[50] = "HOLAAA QUE TAL??";
    char d[50] = "Pagunasa";
    
    Message.messageID = 5;
    strcpy(Message.subject, c);
    strcpy(Message.sender, d);
    
    createMessage(Message);

    
   
    
    return (EXIT_SUCCESS);
}

