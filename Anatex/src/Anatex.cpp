#include <dirent.h>
#include <stdlib.h>

#include "Anatex.h"

/******************* Encapsulated *******************/
Queue *openDirectory();
/// ///////////////////////////////////////////// ///


Anatex::Anatex(){
    this->stopwords = new Trie();
    this->wikibase = new Trie();
}

Anatex::~Anatex(){
    //dest
}

void Anatex::initAnatex(){

    ifstream stopwords("../database/stopwords.txt");
    if(!stopwords){
        cout << "ERRO 1.1: Falha ao acessar banco de stopwords" << endl;
        return;
    }
    ifstream wikibase("../database/wikibase.txt");
    if(!wikibase){
        cout << "ERRO 1.2: Falha ao acessar database" << endl;
        return;
    }
    cout << "Carregando banco de stopwords..." << endl;
    initStopWords(stopwords);
    stopwords.close();
    cout << "Banco de stopwords carregada!" << endl << "Carregando database..." << endl;
    initWikiBase(wikibase);
    wikibase.close();
    cout << "database carregada!" << endl;
}

void Anatex::initStopWords(ifstream& stopwords){
    string word;

    while(!stopwords.eof()){
        getline(stopwords, word);
        word = standart(word);
        this->stopwords->addTrie(word);
    }
}

void Anatex::initWikiBase(ifstream& wikibase){
    string key;

    while(!wikibase.eof()){
        getline(wikibase, key);
        key = standart(key);
//        // se for uma stopword não insere na wikibase
//        if(this->stopwords->searchTrie(key))
//            continue;

        this->wikibase->addTrie(key);
    }
}

void Anatex::anatex(){
//    Queue *queue = openDirectory();
//
//    while(!queue){
//        cout << "ERRO 02: Arquivo(s) não encontrado(s)!" << endl << "Por favor verifique se foi adicionado arquivos na pasta de entrada" << endl;
//        cout << "../input/" << endl;
//        queue = openDirectory();
//    }
//
//    List ptr = queue->start;

//    while(ptr){
        ifstream file("../input/entrada.html"); //ptr->info.c_str()
        /*while*/if(!file){
//            cout << "ERRO 1.3: Falha ao acessar o seguinte arquivo: " << ptr->info << endl;
//            ptr = ptr->next;
//            queue->desenqueue();

            // fim de fila, nenhum arquivo aberto
            //if(!ptr){
                //this->stopwords->cleanup(stopwords->root);
                this->wikibase->cleanup(wikibase->root);
                exit(0);
            //}

            //ifstream file(ptr->info.c_str());
        }

        int i = 0;
        string outFileName = "../output/saida.html";
        ofstream output(outFileName.c_str());

        TrieNode node;
        string wordFile, str;
        Queue key, text;

        while(!file.eof()){
            do{
                // pega uma palavra
                file >> wordFile;
                if(file.eof())
                    break;
                //cout << "String não padronizada: " << wordFile << endl;
                str = standart(wordFile);
                //cout << "String padronizada: " << str << endl;
                //cout << "Pega palavra do arquivo: " << str << endl;
                // se for uma stopword não procura na wikibase
                if(this->stopwords->searchTrie(str)){
                    i = writeFile(output, str, i);
                    continue;
                }
                //cout << "Busca na árvore" << endl;
                node = this->wikibase->searchTrie(str);
                if(!node)
                    i = writeFile(output, wordFile, i);
            }while(!node && !file.eof()); //não encontrou palavra, leia próxima palavra
            do{
                //guarda a string encontrada e procura por outras que possam estar relacionadas na mesma expressão ou palavra composta
                key.enqueue(str);
                text.enqueue(wordFile);
                file >> wordFile; // próxima palavra
                if(file.eof())
                    break;
                str = standart(wordFile);
                str = " " + str;
                node = this->wikibase->searchTrie(node, str.c_str()); //busca nova palavra a partir de node

            }while(node && !file.eof()); //enquanto está sendo encontradas palavras pertencentes à mesma expressão
            if(file.eof())
                    break;
            string textFile = concatString(text);
            string link = buildLink(concatString(key), textFile);
            i = writeFile(output, link, i);
            key.cleanup();
            text.cleanup();
        }
        file.close();
        output.close();
        //ptr = ptr->next;
        //queue->desenqueue();
    //}
}

string Anatex::buildLink(string key, string word){
    string  link  ("<a href=\"http://pt.wikipedia.org/wiki/") ;

    for(int i = 0; i < (int)key.length(); i++)
    {
        if(key[i] == ' ')
            key[i] = '_';
    }

    link = link + key + "\">" + word + "</a>";
    return link;
}

string Anatex::concatString(Queue queue){
    List lt = queue.start;
    string *str= new string(*lt->info);
    lt = lt->next;
    while(lt != NULL){
        *str = *str + (*lt->info);
        lt = lt->next;
    }
    return *str;
}

int Anatex::writeFile(ofstream& file, string word, int pos){
    cout << "Escrevendo: " << ">>>" << word << "<<<" << " na saida" << endl;
    word.push_back(' ');
    file.write(word.c_str(),word.size());
    return pos = pos + word.size();
}

string Anatex::standart(string str){

    int i = 0;
    bool isBig = true;

    while (str[i] != '\0')
    {
        if(!( ( (int)str[i] >= 65   && (int)str[i] <= 90  )    ||
              ( (int)str[i] >= 192  && (int)str[i] <= 214 )    ||
              ( (int)str[i] >= 216  && (int)str[i] <= 222 )    ||

              ( (int)str[i] >= 33   && (int)str[i] <= 47    )  ||
              ( (int)str[i] >= 58   && (int)str[i] <= 64    )  ||
              ( (int)str[i] >= 91   && (int)str[i] <= 96    )  ||
              ( (int)str[i] >= 123  && (int)str[i] <= 126   )  ||
              ( (int)str[i] >= 161  && (int)str[i] <= 191   )



            )
          )
        {
                isBig = false;
                break;
        }
        i++;
    }

    if(!isBig)
    {
        i = 0;
        while (str[i] != '\0')
            {
                if( ( (int)str[i] >= 65   && (int)str[i] <= 90  )  ||
                    ( (int)str[i] >= 192  && (int)str[i] <= 214 )  ||
                    ( (int)str[i] >= 216  && (int)str[i] <= 222 )
                  )
                    str[i] = str[i] + 32;
                i++;
            }
    }

    return str;
}

/// ////////////////////////////// Encapsulated ////////////////////////////////////// ///

Queue *openDirectory(){
    DIR *pDIR;
    struct dirent *entry;
    string aux;
    Queue *inputs = new Queue();

    pDIR = opendir("../input/");
    if( pDIR ){
        entry = readdir(pDIR);

        while(entry){
            aux = entry->d_name;
            if( (aux != "." )  &&  (aux != "..") ){
                inputs->enqueue(entry->d_name);
                aux = "../input/" + aux;
            }
        }
        closedir(pDIR);
    }
    return inputs;
}

/// //////////////////////////////////////////////////////////////////////////////// ///
