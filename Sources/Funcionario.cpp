#include "../Headers/Funcionario.h"

Funcionario::Funcionario()
{

}

Funcionario::~Funcionario()
{

}

string Funcionario::Editarcodigo(){

}
string Funcionario::EditarEndereco(){

}
string Funcionario::EditarTelefone(){

}
string Funcionario::EditarIngressao(){

}
string Funcionario::EditarDesignacao(){

}
string Funcionario::EditarSalario(){

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
void Funcionario::setDataIngressao(string ingressao){
    DataIngressao = ingressao;
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
string Funcionario::getIngressao(){
    return DataIngressao;
}
string Funcionario::getDesignacao(){
 return Designacao;
}
double Funcionario::getSalario(){
    return Salario;
}

void Funcionario::ExcluirRegistro(string codigo){

}
void Funcionario::ExibirRegistro(string codigo){

}
void Funcionario::ExibirLista(){

}
void Funcionario::Busca(){

}
void Funcionario::CalcularFolhaSalarial(){

}
void Funcionario::ImprimirFolhaSalarial(){
    
}