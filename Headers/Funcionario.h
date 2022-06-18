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
    string getEnd();
    string getCodigo();
    string getNome();
    string getTelefone();
    string getData();
    double getSalario();
    virtual void setAreaFormacao(string formacao)=0;
    virtual void setFormacaoAcademica(string graduacao)=0;
    virtual getAreaFormacao()=0;
    virtual string getFormacaoAcademica()=0;
    virtual void setAreaSupervisao(string supervisao)=0;
    virtual string getAreaSupervisao()=0;
    


    void setTipo(int tipo);
    int getTipo();

protected:
    int tipo;
    float percent;
    string Codigo, Nome, Telefone;
    string data, endereco;
    double Salario;
    string AreaFormacao;
    string FormacaoAcademica;
    string AreaSupervisao;


private:
};

#endif