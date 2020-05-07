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
|Objective: This is the header of the file which manages the characters and strings    |
+--------------------------------------------------------------------------------------+
*/

#ifndef CARACTERES_H_INCLUDE
#define CARACTERES_H_INCLUDE

/**
    Função que converte a string passada como parâmetro para o padrão adotado:
        - Primeira letra MAIÚSCULA, o restante minúscula;
        - Números viram letras;
        - letras acentuadas são aceitas;
        - Só é permito ainda hífens e espaços.
    Parâmetros:
        - Ponteiro para a string que será padronizada
        - Tamanho da string
    Retorno: String padronizada
*/
char* padronizaString(char *str, int tam);

/**
    Procedimento que lê uma string do prompt e a padroniza se possível.
    Parâmetros:
        - Ponteiro para a variável que será salva a string
        - Tamanho máximo da string
*/
void leia(char *str, int strTAM);

/**
    Função que escolhe randomicamente uma linha de uma Matriz de strings
    Parâmetros:
        - Matriz de strings
        - Número de linhas da Matriz
    Retorno: Ponteiro para uma das linhas da Matriz
*/
char* randomFrase(char str[][50], int numFrases);

#endif
