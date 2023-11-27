#include "../src/Avaliador.hpp"
#include <iostream>

int main(){
    Lance primeiroLance(Usuario("Fulano de tal"), 1000);
    Lance segundoLance(Usuario("Beltrano"), 2000);
    Leilao leilao("Fiat 147 0km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    Avaliador leiloeiro;
    leiloeiro.avalia(leilao);

    std::cout << leiloeiro.recuperaMaiorValor() << std::endl;

    return 0;
}