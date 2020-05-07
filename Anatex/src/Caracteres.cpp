/*
+--------------------------------------------------------------------------------------+
|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                     |
|Institute for Exact Sciences - ICE                                                    |
|Computer Science Degree                                                               |
|Project: Qual é o Bicho?                        				                       |
|Professor: Bernardo Martins Rocha                    bernardomartinsrocha@ice.ufjf.br |
|Students......: Douglas Coelho Braga de Oliveira     dcoelhobo@gmail.com              |
|                Igor Freitas Couto                   igor.fcouto@gmail.com            |
|                Mauro Correia Vieira                 mauroccvieira@gmail.com          |
|Created in......:October/25/2012                                                      |
|Objective: This file manages the characters and strings                               |
+--------------------------------------------------------------------------------------+
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <Caracteres.h>

/**
    Padroniza a string passada como parâmetro
*/
char* padronizaString(char *str, int tam){
    int i;
    for(i = 0; i < tam - 1; i++){
        //se o caracter é diferente de 'espaço em branco', de 'hífen (-)' e de 'letras normais e acentuadas'
        if(str[i] == 13 || (str[i] > 32 && str[i] < 45) || (str[i] > 45 && str[i] < 65) ||
          (str[i] > 90 && str[i] < 97) || (str[i] > 122 && str[i] < 192))
        {
            if(str[i] >= 48 && str[i] <= 57){   //numeros (0-9)
                switch(str[i]){
                    case '1': str[i] = 'I'; break;
                    case '2': str[i] = 'Z'; break;
                    case '3': str[i] = 'E'; break;
                    case '4': str[i] = 'A'; break;
                    case '5': str[i] = 'S'; break;
                    case '6': str[i] = 'G'; break;
                    case '7': str[i] = 'T'; break;
                    case '8': str[i] = 'B'; break;
                    case '9': str[i] = 'P'; break;
                    case '0': str[i] = 'O'; break;
                    default:; //default
                }
            }
            else    return 0;
        }
        if(i > 0 && str[i] >= 65 && str[i] <= 90)   //se letra maiuscula no meio da palavra
            str[i] += 32;
        else if(i == 0 && str[i] >= 97 && str[i] <= 122)    //se letra miniscula no primeiro caracter
            str[i] -= 32;
    }
    str[i] = '\0';
    return str;
}

/**
    Lê uma string do prompt e a padroniza
*/
void leia(char *str, int strTAM){
    fflush(stdin);
    fgets(str, strTAM, stdin);
    if(padronizaString(str, strlen(str)) == 0){
        printf("\aERRO 06: Foi encontrado um caracter inv lido!\nPor favor utilize apenas Letras, Espa‡os e/ou H¡fens!\n\n");
        exit(0);
    }
}


/**
    Retorna um ponteiro para uma das linhas da matriz passada por parâmetro
*/
char* randomFrase(char str[][50], int numFrases){
    srand ( time(NULL) );
    return str[(rand() % numFrases)];
}
