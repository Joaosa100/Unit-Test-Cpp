#pragma once
#define Lance_hpp
#include "Usuario.hpp"
#include <string>

class Lance
{
private:
    Usuario usuario;
    float valor;
public:
    Lance(Usuario usuario, float valor);
    float recuperaValor() const;
    std::string recuperaNomeUsuario() const;
};