#include "../Headers/Funcionario.h"

Funcionario::Funcionario()
{

}

Funcionario::~Funcionario()
{

}

void Funcionario::setCodigo(string codigo){

    Codigo = codigo;
}
void Funcionario::setNome(string nome){
    Nome = nome;
}
void Funcionario::setEndereco(string endereco){
 Endereco = endereco;
}
void Funcionario::setTelefone(string telefone){
    Telefone = telefone;
}
void Funcionario::setDia(string dia){
    Dia = dia;
   
}
void Funcionario::setDesignacao(string design){
        Designacao = design;
}
void Funcionario::setSalario(double salario){

    Salario = salario;

}
string Funcionario::getCodigo(){
    return Codigo;
}
string Funcionario::getNome(){
 return Nome;
}
string Funcionario::getEndereco(){
    return Endereco;
}
string Funcionario::getTelefone(){
    return Telefone;
}
string Funcionario::getDia(){
    return Dia;
}
string Funcionario::getDesignacao(){
 return Designacao;
}

void Funcionario::setMes(string mes){
         Mes = mes;
}
void Funcionario::setAno(string ano){
         Ano = ano;
}
string Funcionario::getMes(){
 return Mes;
}
string Funcionario::getAno(){
 return Ano;
}
double Funcionario::getSalario(){
    return Salario;
}

