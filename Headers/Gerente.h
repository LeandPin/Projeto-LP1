#ifndef GERENTE_H
#define GERENTE_H
#include "Funcionario.h"

#pragma once

class Gerente : public Funcionario
{
public:
    Gerente();
    ~Gerente();
    void ExibirLista();
    void ImprimirFolhaSalarial();
    void CalcularFolhaSalarial();
    void setAreaSupervisao(string supervisao);
    string getAreaSupervisao();

private:
string AreaSupervisao;

};

#endif