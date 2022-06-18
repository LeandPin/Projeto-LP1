#include "../Headers/Diretor.h"

Diretor::Diretor():Funcionario()
{
  tipo = 3;
  percent = 0.2;
}
Diretor::~Diretor()
{

}
void Diretor::setAreaFormacao(string formacao)
{
  AreaFormacao = formacao;
}
void Diretor::setAreaSupervisao(string supervisao)
{
  AreaSupervisao = supervisao;
}
void Diretor::aumentarSalario()
{
  Salario+=Salario*percent;
}

string Diretor::getAreaFormacao()
{
  return AreaFormacao;
}
string Diretor::getAreaSupervisao()
{
  return AreaFormacao;
}
