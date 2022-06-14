#ifndef GERENCIAFUNCIONARIO_H
#define GERENCIAFUNCIONARIO_H
#include "../Headers/Diretor.h"
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
    void ExcluirRegistro(string codigo);
    virtual void ExibirRegistro();
    virtual void ExibirLista();
    void Busca();
    virtual void CalcularFolhaSalarial();
    void ImprimirFolhaSalarial();

};

#endif