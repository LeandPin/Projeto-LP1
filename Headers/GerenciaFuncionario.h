#ifndef GERENCIAFUNCIONARIO_H
#define GERENCIAFUNCIONARIO_H
#include "Funcionario.h"
#include <iostream>
#include <vector>
#include <string>

#pragma once

class GerenciaFuncionario : public Funcionario 
{
public:
    GerenciaFuncionario();
    ~GerenciaFuncionario();
    void BuscaFuncionario(string cod);
    string EditarDados();
    void ExcluirRegistro(string cod);
    void ExibirRegistro(string cod, vector <Funcionario *> func);
    void ExibirLista(vector <Funcionario *> func);
    void Busca();
    virtual void CalcularFolhaSalarial();
    void ImprimirFolhaSalarial();

};

#endif