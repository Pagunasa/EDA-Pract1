/* 
 * File:   main.c
 * Author: u140172
 *
 * Created on 18 de enero de 2017, 11:07
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "message.h"
//#include "messageOperations.c"

void createMsg() { 
    sMessage message;
    inputNewMsg(message);
}

menu(int option) {
    switch (option) {
        case 1:
            createMsg();
            break;
        case 2:
            
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        default:
            break;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {

    //createFolder("Inbox");
    int option = 0; 
  
    do{
        writeMenu();
        
        printf("Introduce Opcion: ");
        scanf("%d",&option);

        menu(option);
    } while(option != 10);

    return (EXIT_SUCCESS);
}

