#ifndef OPERADOR_H
#define OPERADOR_H
#include "Funcionario.h"

#pragma once

class Operador : public Funcionario
{
public:
    Operador();
    ~Operador();
    void ExibirLista();
    void ImprimirFolhaSalarial();
    void CalcularFolhaSalarial();
    

private:

};

#endif