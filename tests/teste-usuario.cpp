#include "catch2.hpp"
#include "../src/Usuario.hpp"

TEST_CASE("Usuario informar apenas primeiro nome"){
    Usuario fulano("Fulano de Tal");

    std::string primeiroNome = fulano.recuperaPrimeiroNome();

    REQUIRE("Fulano" == primeiroNome);
}