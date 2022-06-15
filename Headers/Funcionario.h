#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>
#include <iostream>

using namespace std;

#pragma once

class Funcionario
{
public:
    Funcionario();
    ~Funcionario();
    void setCodigo(string codigo);
    void setNome(string nome);
    void setTelefone(string telefone);
    void setData(string data);
    void setSalario(double salario);
    int getTipo();
    string getCodigo();
    string getNome();
    string getTelefone();
    string getData();
    double getSalario();
   

protected:
    int tipo;
    string Codigo, Nome, Telefone;
    string data;
    double Salario;

private:
};

#endif