#include "../Headers/Funcionario.h"

Funcionario::Funcionario()
{
    tipo = 1;
    percent = 0.05;
}
Funcionario::~Funcionario()
{

}
void Funcionario::setCodigo(string codigo)
{
    Codigo = codigo;
}
void Funcionario::setNome(string nome)
{
    Nome = nome;
}
void Funcionario::setTelefone(string telefone)
{
    Telefone = telefone;
}
void Funcionario::setData(string data)
{
    this -> data = data;   
}
void Funcionario::setSalario(double salario)
{

    Salario = salario;
}
void Funcionario::setEnd(string end)
{
    endereco = end;
}
void Funcionario::setTipo(int tipo)
{
    this->tipo = tipo;
}
string Funcionario::getEnd()
{
    return endereco;
}
string Funcionario::getCodigo()
{
    return Codigo;
}
string Funcionario::getNome()
{
    return Nome;
}
string Funcionario::getTelefone()
{
    return Telefone;
}
string Funcionario::getData()
{
    return data;
}
double Funcionario::getSalario()
{
    return Salario;
}
int Funcionario::getTipo() {
    return tipo;
}
void Funcionario::aumentarSalario()
{
    Salario+=Salario*percent;
}
void Funcionario::setPercent(double percent)
{
    this->percent = percent;
}
void Funcionario::setAreaFormacao(string formacao)
{
    AreaFormacao = formacao;
}
void Funcionario::setFormacaoAcademica(string graduacao)
{
    FormacaoAcademica = graduacao;
}
string Funcionario::getAreaFormacao()
{
    return AreaFormacao;
}
string Funcionario::getFormacaoAcademica()
{
    return FormacaoAcademica;
}
void Funcionario::setAreaSupervisao(string supervisao)
{   
    AreaSup = supervisao;
}
string Funcionario::getAreaSupervisao()
{
    return AreaSup;
}