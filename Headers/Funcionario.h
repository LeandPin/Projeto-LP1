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
    string Editarcodigo();
    string EditarEndereco();
    string EditarTelefone();
    string EditarIngressao();
    string EditarDesignacao();
    string EditarSalario();
    void setCodigo(string codigo);
    void setNome(string nome);
    void setEndereco(string endereco);
    void setTelefone(string telefone);
    void setDataIngressao(string ingressao);
    void setDesignacao(string design);
    void setSalario(double salario);
    string getCodigo();
    string getNome();
    string getEndereco();
    string getTelefone();
    string getIngressao();
    string getDesignacao();
    double getSalario();
    void ExcluirRegistro(string codigo);
    void ExibirRegistro(string codigo);
    void ExibirLista();
    void Busca();
    void CalcularFolhaSalarial();
    void ImprimirFolhaSalarial();

protected:
string Codigo, Nome, Endereco, Telefone;
string DataIngressao, Designacao;
double Salario;


private:

};

#endif