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
   
    int EditarDados(string cod, vector <Funcionario *> func);
    vector <Funcionario *> ExcluirRegistro(string cod, vector <Funcionario *> func);
    void ExibirRegistro(string cod, vector <Funcionario *> func);
    void ExibirListaGeral(vector <Funcionario *> func);
    void Busca(int tipo, vector <Funcionario *> func);
    void AumentarSalarios(vector <Funcionario *> func);
    void ImprimirFolhaSalarial();
    int disponibilidadeCod(string cod, vector <Funcionario *> func);

    private:
   

};

#endif