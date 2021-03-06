/* 
 * File:   inputOuput.c
 *  * Autors:
    Guillem Martinez 196310
    Oriol Bernier 193518
    Sandra Rodriguez 192860
 * Funcionalidad para leer los espacios y no dejarlos definidos como el siguiente string o char
 * Created on 24 de enero de 2017, 12:48
 */

#include <stdio.h>
#include <stdlib.h>
#include "message.h"

int readChain(char *cad, int n) { //funcion que utilizamos para la poder cojer los espacios en blanco a la hora de crear el mensaje
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

