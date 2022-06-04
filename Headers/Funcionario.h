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
    void setEndereco(string endereco);
    void setTelefone(string telefone);
    void setDia(string dia);
    void setDesignacao(string design);
    void setSalario(double salario);
    void setMes(string mes);
    void setAno(string ano);
    string getCodigo();
    string getNome();
    string getEndereco();
    string getTelefone();
    string getDia();
    string getDesignacao();
    string getMes();
    string getAno();
    double getSalario();
   

protected:
    string Codigo, Nome, Endereco, Telefone;
    string Dia, Mes, Ano, Designacao;
    double Salario;

private:
};

#endif