#pragma once
#define Avaliador_hpp
#include <stdio.h>
#include "Leilao.hpp"

class Avaliador
{
private:
    /*
    Isso 'e para evitar lixo de memoria e garantir que nao havera
    valores que ultrapassarao os limites do compilador, ou seja,
    maiorValor so tera valores acima do 'minimo' definido e 
    menorValor so tera valores abaixo do 'maximo' definido.
    leia-se:
    INT_MAX = Numero infinitamente grande
    INT_MIN = Numero infinitamente pequeno
    */
    float maiorValor = INT64_MIN;
    float menorValor = INT64_MAX;
    std::vector<Lance> maiores3Lances;
    static bool ordenaLances(const Lance&, const Lance&);
public:
    void avalia(Leilao);
    float recuperaMaiorValor() const;
    float recuperaMenorValor() const;
    std::vector<Lance> recupera3MaioresLances() const;
};