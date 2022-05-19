#include "nao_acertou.hpp"

bool nao_acertou(std::string& palavra_secreta, const std::map<char, bool>& CHUTOU){
    for(char letra : palavra_secreta){
        if(CHUTOU.find(letra) == CHUTOU.end() || !CHUTOU.at(letra)){
            return true;
        }
    }
    return false;
}