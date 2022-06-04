#include "../Headers/Diretor.h"

Diretor::Diretor()
:Funcionario()
{

}

Diretor::~Diretor()
{

}

void Diretor::CalcularFolhaSalarial(){

}

void Diretor::setAreaFormacao(string formacao){
  AreaFormacao = formacao;
}
void Diretor::setAreaSupervisao(string supervisao){
 AreaSupervisao =supervisao;
}
string Diretor::getAreaFormacao(){
 return AreaFormacao;
}
string Diretor::getAreaSupervisao(){
 return AreaFormacao;
}

void Diretor::ExibirLista(){

 ExibirRegistro();
 }

