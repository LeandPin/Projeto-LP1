#include "../Headers/Diretor.h"

Diretor::Diretor():Funcionario()
{
  tipo = 3;
  percent = 0.2;
}
Diretor::~Diretor()
{

}
void Diretor::aumentarSalario()
{
  Salario+=Salario*percent;
}

