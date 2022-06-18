#ifndef PRESIDENTE_H
#define PRESIDENTE_H
#include "Funcionario.h"

#pragma once

class Presidente : public Funcionario
{
public:
    Presidente();
    ~Presidente();
    void setAreaFormacao(string formacao);
    void setFormacaoAcademica(string graduacao);
    string getAreaFormacao();
    string getFormacaoAcademica();

    void FolhaSalarial(){}

private:
    string AreaFormacao;
    string FormacaoAcademica;
};

#endif