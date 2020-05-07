#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED
// Estrutura principal, a árvore trie.
using namespace std;

struct t_trieNode{ // Nó da árvore Trie
    bool isKey; // Indica se nesse nó representa o fim de uma palavra
    struct t_trieNode **son; //vetor para os filhos
};
typedef struct t_trieNode * TrieNode;

class Trie{ //Árvore trie
    public:
        TrieNode root;

        Trie();
        ~Trie();

        TrieNode createNode();// Inicializa Nó

        TrieNode searchTrie(string key);// função de busca na árvore
        TrieNode searchTrie(TrieNode node, const char *key);

        TrieNode addTrie(string key); //Função de inserção
        TrieNode addTrie(TrieNode node, const char *key);

        void cleanup(TrieNode node);

};

#endif // TRIE_H_INCLUDED
