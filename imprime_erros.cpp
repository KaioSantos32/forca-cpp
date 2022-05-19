#include "imprime_erros.hpp"
#include <iostream>


void imprime_erros(const std::vector<char>& CHUTES_ERRADOS){

    std::cout << "Chutes errados: ";
    for(char letra: CHUTES_ERRADOS){
        std::cout << letra << " ";
    }
    std::cout << std::endl;
}
