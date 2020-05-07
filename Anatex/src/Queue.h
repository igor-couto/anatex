#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
#include <string>

// Foi implementado esta estrutura de fila para ser utilizada em dois processos diferentes no AnaTex:
//      1 - Tratar palavras compostas presentes no texto de entrada. Como por exemplo "Nova York"
//      2 - Abrir multiplos arquivos de entrada.

using namespace std;

struct t_list {
  string *info;
  struct t_list *next;
};
typedef struct t_list * List;


class Queue{
    public:
        List start;
        List end;

        Queue();
        ~Queue();

        bool    search(string str);
        void    enqueue(string str);
        void    desenqueue();

        void   cleanup();
};

#endif // QUEUE_H_INCLUDED

