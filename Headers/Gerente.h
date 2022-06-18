#ifndef GERENTE_H
#define GERENTE_H
#include "Funcionario.h"

#pragma once

class Gerente : public Funcionario
{
public:
    Gerente();
    ~Gerente();
    void setAreaSupervisao(string supervisao);
    string getAreaSupervisao();

    void FolhaSalarial(){}

private:

    string AreaSupervisao;

};

#endif