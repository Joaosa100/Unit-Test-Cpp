#include "catch2.hpp"
#include "../src/Leilao.hpp"
#include "../src/Usuario.hpp"

TEST_CASE("Leilao nao deve receber lances consecutivos do mesmo usuario"){
    Leilao leilao("Fiat 147 0km");
    Usuario beltrano("Beltrano de tal");

    Lance primeiroLance(beltrano, 1000);
    Lance segundoLance(beltrano, 1500);

    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    REQUIRE(1 == leilao.recuperaLances().size());
    REQUIRE(1000 == leilao.recuperaLances()[0].recuperaValor());
}