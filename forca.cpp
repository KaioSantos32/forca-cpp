    #include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "letra_existe.hpp"
#include "imprime_cabecalho.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "adiciona_palavra.hpp"
#include "nao_acertou.hpp"

using namespace std;

string palavra_secreta; 
map<char, bool> chutou;
vector<char> chutes_errados;

int main () {
    imprime_cabecalho();

    palavra_secreta = sorteia_palavra();

    while(nao_acertou(palavra_secreta, chutou) && chutes_errados.size() < 5){
        imprime_erros(chutes_errados);

        imprime_palavra(palavra_secreta, chutou);

        // Ao passar as variaveis, é criado uma cópia e ela sera modificada
        // para passar a varavel real, na memoria ja alocada, é necessario 
        // passar com um ponteiro, representado por '&'
        chuta(&chutou, &chutes_errados);
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if(nao_acertou(palavra_secreta, chutou)){
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;

        cout << "Você deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        }
    }
    
    cin.get();
}