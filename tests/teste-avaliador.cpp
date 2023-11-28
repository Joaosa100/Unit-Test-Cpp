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
}
//infelizmente tivemos que duplicar codigo.
TEST_CASE("Deve recuperar maior lance de leilao em ordem decrescente"){
    // preparando ambiente (arrange)
    Lance primeiroLance(Usuario("Fulano de tal"), 2000);
    Lance segundoLance(Usuario("Beltrano"), 1000);
    Leilao leilao("Fiat 147 0km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    Avaliador leiloeiro;

    // executando codigo a ser testado (act)
    leiloeiro.avalia(leilao);

    // verificando (assert)
    REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
}