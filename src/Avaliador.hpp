#pragma once
#define Avaliador_hpp
#include <stdio.h>
#include "Leilao.hpp"

class Avaliador
{
private:
    float maiorValor;
public:
    void avalia(Leilao);
    float recuperaMaiorValor() const;
};