#include <stdlib.h>
#include <iostream>

#include "Trie.h"

#define SIZE 190

using namespace std;

/************ Definition the functions encapsulated ***************/

TrieNode searchNodeInsertion(TrieNode node, const char **key);

//Alocação
TrieNode allocateNode();
TrieNode *allocateSon();

//Hashings
int keyPosition(unsigned char key);
int hashTwo(unsigned char key);
int hashOne(unsigned char key);

/************************** Methods of the class *************************/

//Construtor and Destrutor
Trie::Trie(){
    this->root = NULL;
    this->root = createNode();
}
Trie::~Trie(){
    //dest
}


TrieNode Trie::createNode(){
    TrieNode node;
    try{
        node = allocateNode();
    }
    catch(TrieNode t){
        cout << "FATAL ERROR: Memória Insuficiente!" << endl;
        cleanup(this->root);
        exit(0);
    }

    node->isKey = false;
    node->son = NULL;
    return node;
}

TrieNode Trie::searchTrie(string key){
    return searchTrie(this->root, key.c_str());
}

TrieNode Trie::addTrie(string key){
    return addTrie(this->root, key.c_str());
}


TrieNode Trie::searchTrie(TrieNode node, const char *key){
    if(!node)
        return NULL;
    // Folha mas não chegou ao fim da chave, ou chegou ao fim da chave mas ela não é chave
    if((!node->son && *key != '\0') || (*key == '\0' && !node->isKey))
        return NULL;
    // Encontrou chave (fim de string) e realmente é uma chave
    if(*key == '\0' && node->isKey)
        return node;

    int posKey = keyPosition((unsigned char)*key);
    // Foi encontrado uma quebra de linha ou um caracter inválido
    if(posKey == -2)
        return searchTrie(node, ++key);

    return searchTrie(node->son[posKey], ++key);
}

TrieNode Trie::addTrie(TrieNode node, const char* key){

    TrieNode nodeInsert = searchNodeInsertion(node, &key);

    // Chave Já se encontra na Trie
    if(!nodeInsert)
        return node;

    TrieNode aux = nodeInsert;
    while(*key != '\0'){
        int posKey = keyPosition((unsigned char)*key);
        if(posKey == -2){
            ++key;
            continue;
        }
        if(!aux->son){
            try{
                aux->son = allocateSon();
            }catch (TrieNode *t){
                cout << "FATAL ERROR: Memória Insuficiente!" << endl;
                cout << *key << endl;
                cleanup(this->root);
                exit(0);
            }

        }
        nodeInsert = createNode();
        aux->son[posKey] = nodeInsert;
        ++key;
        aux = aux->son[posKey];
    }
    aux->isKey = true;
    return aux;
}

// Remove Function
void Trie::cleanup(TrieNode node){
    if(!node) return;
    if(!node->son){
        free(node);
        node = NULL;
        return;
    }
    for(int i = 0; i < SIZE; i++){
        if(!node->son[i])
            continue;
        cleanup(node->son[i]);
    }
}


/************ Implementing the functions encapsulated ***************/

TrieNode searchNodeInsertion(TrieNode node, const char **key){
    //Folha
    if(!node->son)
        return node;
    // Chegou ao final da string
    if(**key == '\0'){
        // E já é chave
        if(node->isKey)
            return NULL;
        // Não é chave, mas existe a correspondência na árvore
        else{
            node->isKey = true;
            return NULL;
        }
    }

    int posKey = keyPosition((unsigned char)**key);
    // Foi encontrado uma quebra de linha ou um caracter inválido
    if(posKey == -2){
        ++(*key);
        return searchNodeInsertion(node, key);
    }
    // Não existe a correspondencia do caracter atual nos filhos do nó atual
    if(!node->son[posKey])
        return node;
    ++(*key);
    return searchNodeInsertion(node->son[posKey], key);
}

TrieNode allocateNode(){
    TrieNode node =  ((TrieNode)malloc(sizeof(struct t_trieNode))); // new struct t_trieNode;
    if (!node) throw node;

    return node;
}

TrieNode *allocateSon(){
    TrieNode* son =  ((TrieNode*)malloc(SIZE * sizeof(struct t_trieNode))); // new struct t_trieNode* [SIZE];

    if(!son) throw son;

    for(int i = 0; i < SIZE; i++)
        son[i] = NULL;
    return son;
}

int keyPosition(unsigned char key){
    if(key >= 32 && key <= 126) //primeira parte da tabela
        return hashOne(key);
    else if(key >= 161 && key <= 255) //segunda parte da tabela
        return hashTwo(key);
    else if(key == 10 || key == 13) //quebra de linha ou carriage return, ignora
        return -2;
    //pelos testes realizados nunca entrará neste bloco, mas de toda forma, caso aconteça, o caracter será ignorado
    else{
        cout << "ERRO 02: Invalid character found" << " Int: " << key << " Char: " << key << endl;
        return -2;
    }
}

int hashOne(unsigned char key){ // 1º bloco de caractéres imprimíveis da codificação ISO-8849-1
    return key - 32;
}

int hashTwo(unsigned char key){ //2º bloco de caractéres imprimíveis da codificação ISO-8849-1
    return key - 66;
}
