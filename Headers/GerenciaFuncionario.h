#ifndef GERENCIAFUNCIONARIO_H
#define GERENCIAFUNCIONARIO_H
#include "../Headers/Funcionario.h"
#include <vector>
#include <string>

#pragma once

class GerenciaFuncionario : public Funcionario 
{
public:
    GerenciaFuncionario();
    ~GerenciaFuncionario();
    void BuscaFuncionario(int tipobusca,string cod);
    string EditarDados();
    void ExcluirRegistro(string codigo);
    void ExibirRegistro();
    void ExibirListaGeral(vector <Funcionario*>* func);
    void ExibirListaTipo();
    void Busca();
    virtual void CalcularFolhaSalarial();
    void ImprimirFolhaSalarial();

    private:
   

};

#endif