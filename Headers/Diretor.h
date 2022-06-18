#ifndef DIRETOR_H
#define DIRETOR_H
#include "Funcionario.h"

#pragma once

class Diretor : public Funcionario
{
public:
    Diretor();
    ~Diretor();
    void setAreaFormacao(string formacao);
    void setAreaSupervisao(string supervisao);
    string getAreaFormacao();
    string getAreaSupervisao();

    


private:
    string AreaFormacao;
    string AreaSupervisao;

};

#endif