#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../src/Avaliador.hpp"
#include <iostream>

TEST_CASE("Deve recuperar maior lance de leilao em ordem crescente"){
    // preparando ambiente (arrange)
    Lance primeiroLance(Usuario("Fulano de tal"), 1000);
    Lance segundoLance(Usuario("Beltrano"), 2000);
    Leilao leilao("Fiat 147 0km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    Avaliador leiloeiro;

    // executando codigo a ser testado (act)
    leiloeiro.avalia(leilao);

    // verificando (assert)
    REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
    
    /*
    parte nao mais necessaria para verificacao
    float valorEsperado = 2000;

    if (valorEsperado == leiloeiro.recuperaMaiorValor()){
        std::cout << "TESTE OK" << std::endl;
    } else{
        std::cout << "TESTE FALHOU" << std::endl;
    }
    */
    //std::cout << leiloeiro.recuperaMaiorValor() << std::endl;

    //return 0;
}