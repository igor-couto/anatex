#include "Anatex.h"

int main () {
    Anatex *teste = new Anatex();
    teste->initAnatex();
    teste->anatex();
/*
    //Gravar Arquivo
    ofstream arquivoSaida;

    arquivoSaida.open("corrigido.txt");
    //ler Arquivo
    ifstream arquivoEntrada;

    arquivoEntrada.open("original.txt");

    if(!arquivoEntrada.is_open()){
        cout << "erro arquivo nao pode ser aberto";
    }else{
        string linha;
        while(true){
            if(arquivoEntrada.eof()){
                break;
            }else{
                getline(arquivoEntrada, linha);
                //Testa Linha
                bool teste = true;
                for(int cont = -500 ; cont < 500 ; cont++) {
                    arquivoSaida<<hex<<cont<<endl;
                }
                for(int cont = 0 ; cont < linha.length() ; cont++) {
                    if ((int)linha[cont]>255) teste = false;
                    if ((int)linha[cont]<0) teste = false;
                }
                if (teste) {
                    arquivoSaida<<linha<<endl;
                }

            }
        }

    }

    arquivoEntrada.close();
    arquivoSaida.close();
*/
    return 0;
}
