#include "Avaliador.hpp"

void Avaliador::avalia(Leilao leilao){
    std::vector<Lance> lances = leilao.recuperaLances();
    Lance ultimoLance = lances.back();
    maiorValor = ultimoLance.recuperaValor();
}

float Avaliador::recuperaMaiorValor() const{
    return maiorValor;
}