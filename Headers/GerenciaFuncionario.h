#ifndef GERENCIAFUNCIONARIO_H
#define GERENCIAFUNCIONARIO_H
#include "../Headers/Funcionario.h"
#include <vector>
#include <string>

#pragma once

class GerenciaFuncionario
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
    vector<string> ImprimirFolhaSalario(vector <Funcionario *> func, int opc, int mesOUano,vector<string> codi, string cod);
    int disponibilidadeCod(string cod, vector <Funcionario *> func);

};

#endif