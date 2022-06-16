#ifndef GERENCIAFUNCIONARIO_H
#define GERENCIAFUNCIONARIO_H
<<<<<<< HEAD
#include "../Headers/Funcionario.h"
=======
#include "Funcionario.h"
#include <iostream>
>>>>>>> 727e520f1744852b093e2f8366dd2de07c0cf00e
#include <vector>
#include <string>

#pragma once

class GerenciaFuncionario : public Funcionario 
{
public:
    GerenciaFuncionario();
    ~GerenciaFuncionario();
<<<<<<< HEAD
    void BuscaFuncionario(int tipobusca,string cod);
    string EditarDados();
    void ExcluirRegistro(string codigo);
    void ExibirRegistro();
    void ExibirListaGeral(vector <Funcionario*>* func);
    void ExibirListaTipo();
=======
    void BuscaFuncionario(string cod,vector <Funcionario *> func);
    string EditarDados();
    void ExcluirRegistro(string cod);
    void ExibirRegistro(string cod, vector <Funcionario *> func);
    void ExibirLista(vector <Funcionario *> func);
>>>>>>> 727e520f1744852b093e2f8366dd2de07c0cf00e
    void Busca();
    virtual void CalcularFolhaSalarial();
    void ImprimirFolhaSalarial();

    private:
   

};

#endif