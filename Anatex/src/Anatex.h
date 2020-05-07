#ifndef ANATEX_H_INCLUDED
#define ANATEX_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

#include "Queue.h"
#include "Trie.h"

using namespace std;

class Anatex{
    private:
        Trie *stopwords;
        Trie *wikibase;

    public:
        Anatex();
        ~Anatex();

        void initAnatex();
        void anatex();

    private:
        void initStopWords(ifstream& stopwords);
        void initWikiBase(ifstream& wikibase);
        int writeFile(ofstream& file, string word, int posicao);
        string concatString(Queue queue);
        string buildLink(string key, string word);
        string standart(string str);
};

#endif // ANATEX_H_INCLUDED
