#ifndef DIRETOR_H
#define DIRETOR_H
#include "Funcionario.h"

#pragma once

class Diretor : public Funcionario
{
public:
    Diretor();
    ~Diretor();
    void CalcularFolhaSalarial();
    void ExibirRegistro();
    void ExibirLista();
    void setAreaFormacao(string formacao);
    void setAreaSupervisao(string supervisao);
    void BuscaDiretor(string cod);
    string getAreaFormacao();
    string getAreaSupervisao();
    void ImprimirFolhaSalarial();
    


private:
string AreaFormacao;
string AreaSupervisao;


};

#endif