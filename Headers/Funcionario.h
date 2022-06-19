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
    void setEnd(string end);
    void setAreaSupervisao(string supervisao);
    void setAreaFormacao(string formacao);
    void setFormacaoAcademica(string graduacao);
    void setTipo(int tipo);
    void setPercent(double percent);
    string getEnd();
    string getCodigo();
    string getNome();
    string getTelefone();
    string getData();
    double getSalario();
    int getTipo();
    string getAreaSupervisao();
    string getAreaFormacao();
    string getFormacaoAcademica();

    virtual void aumentarSalario();

protected:
    int tipo;
    string Codigo, Nome, Telefone,AreaFormacao,FormacaoAcademica,AreaSup;
    string data, endereco;
    double Salario, percent;
};

#endif