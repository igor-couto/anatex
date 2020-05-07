#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED
// Estrutura principal, a �rvore trie.
using namespace std;

struct t_trieNode{ // N� da �rvore Trie
    bool isKey; // Indica se nesse n� representa o fim de uma palavra
    struct t_trieNode **son; //vetor para os filhos
};
typedef struct t_trieNode * TrieNode;

class Trie{ //�rvore trie
    public:
        TrieNode root;

        Trie();
        ~Trie();

        TrieNode createNode();// Inicializa N�

        TrieNode searchTrie(string key);// fun��o de busca na �rvore
        TrieNode searchTrie(TrieNode node, const char *key);

        TrieNode addTrie(string key); //Fun��o de inser��o
        TrieNode addTrie(TrieNode node, const char *key);

        void cleanup(TrieNode node);

};

#endif // TRIE_H_INCLUDED
