#include "../Headers/Diretor.h"

Diretor::Diretor():Funcionario()
{
  tipo = 3;
}
Diretor::~Diretor()
{

}
void Diretor::setAreaFormacao(string formacao){
  AreaFormacao = formacao;
}
void Diretor::setAreaSupervisao(string supervisao){
 AreaSupervisao = supervisao;
}
string Diretor::getAreaFormacao(){
 return AreaFormacao;
}
string Diretor::getAreaSupervisao(){
 return AreaFormacao;
}
