#include <stdlib.h>
#include "Queue.h"

Queue::Queue(){
    this->start = NULL;
    this->end = NULL;
}

Queue::~Queue(){
    //dest
}

bool Queue::search(string str){
    List list;
    for(list = this->start; list != NULL; list = list->next)
        if ((*list->info).compare(str))
            return true;
    return false;
}

void Queue::enqueue(string str){
    List node = (List)malloc(sizeof(struct t_list));

    if(!node) exit(0); //throw node;

    node->next = NULL;

    //cout << "String inserida na fila: " << str << endl;
    node->info = new string (str);
    //node->info = str;


    if (this->end)
        this->end->next = node;
    else
        this->start = node;
    this->end = node;
}

void Queue::desenqueue(){
    List list;

    if(!this->start)
        return;

    list = this->start;
    this->start = list->next;

    if (!this->start)
        this->end = NULL;

    free(list);
    list = NULL;
}

void Queue::cleanup(){
    List aux = this->start;
    while(aux){
        this->start = aux->next;
        free(aux);
        aux = this->start;
    }
    this->start = NULL;
    this->end = NULL;
}
