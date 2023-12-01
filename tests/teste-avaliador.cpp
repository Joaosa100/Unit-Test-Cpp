#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../src/Avaliador.hpp"
#include <iostream>

Leilao emOrdemCrescente(){
    Lance primeiroLance(Usuario("Fulano de tal"), 1000);
    Lance segundoLance(Usuario("Beltrano"), 2000);
    Leilao leilao("Fiat 147 0km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    return leilao;
}

Leilao emOrdemDecrescente(){
    Lance primeiroLance(Usuario("Fulano de tal"), 2000);
    Lance segundoLance(Usuario("Beltrano"), 1000);
    Leilao leilao("Fiat 147 0km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    return leilao;
}

TEST_CASE("Avaliador"){
    // preparando ambiente (arrange)
    Avaliador leiloeiro;

    SECTION("Leiloes ordenados"){
        Leilao leilao = GENERATE(emOrdemCrescente(), emOrdemDecrescente());

        SECTION("Deve recuperar maior lance de leilao"){


            // executando codigo a ser testado (act)
            leiloeiro.avalia(leilao);

            // verificando (assert)
            REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
        }

        SECTION("Deve recuperar menor lance de leilao"){
            // preparando ambiente (arrange)
            Leilao leilao = GENERATE(emOrdemCrescente(), emOrdemDecrescente());
            Avaliador leiloeiro;

            // executando codigo a ser testado (act)
            leiloeiro.avalia(leilao);

            // verificando (assert)
            REQUIRE(1000 == leiloeiro.recuperaMenorValor());
        }

    }
    
    SECTION("Deve recuperar os 3 maiores lances"){
        // preparando ambiente (arrange)
        Lance primeiroLance(Usuario("Fulano de tal"), 1000);
        Lance segundoLance(Usuario("Beltrano"), 2000);
        Lance terceiroLance(Usuario("Ciclano"), 1500);
        Lance quartoLance(Usuario("Avulso"), 2500);
        Leilao leilao("Fiat 147 0km");
        leilao.recebeLance(primeiroLance);
        leilao.recebeLance(segundoLance);
        leilao.recebeLance(terceiroLance);
        leilao.recebeLance(quartoLance);

        Avaliador leiloeiro;

        // executando codigo a ser testado (act)
        leiloeiro.avalia(leilao);

        // verificando (assert)
        std::vector<Lance> maiores3Lances = leiloeiro.recupera3MaioresLances();
        REQUIRE (3 == maiores3Lances.size());
    }
}

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