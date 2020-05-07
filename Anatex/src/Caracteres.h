/*
+--------------------------------------------------------------------------------------+
|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                     |
|Institute for Exact Sciences - ICE                                                    |
|Computer Science Degree                                                               |
|Project: Qual � o Bicho?                        				                       |
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
    Fun��o que converte a string passada como par�metro para o padr�o adotado:
        - Primeira letra MAI�SCULA, o restante min�scula;
        - N�meros viram letras;
        - letras acentuadas s�o aceitas;
        - S� � permito ainda h�fens e espa�os.
    Par�metros:
        - Ponteiro para a string que ser� padronizada
        - Tamanho da string
    Retorno: String padronizada
*/
char* padronizaString(char *str, int tam);

/**
    Procedimento que l� uma string do prompt e a padroniza se poss�vel.
    Par�metros:
        - Ponteiro para a vari�vel que ser� salva a string
        - Tamanho m�ximo da string
*/
void leia(char *str, int strTAM);

/**
    Fun��o que escolhe randomicamente uma linha de uma Matriz de strings
    Par�metros:
        - Matriz de strings
        - N�mero de linhas da Matriz
    Retorno: Ponteiro para uma das linhas da Matriz
*/
char* randomFrase(char str[][50], int numFrases);

#endif
