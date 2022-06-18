#include "../Headers/Gerente.h"

Gerente::Gerente()
{
    tipo = 2;
    percent = 0.1;
}
Gerente::~Gerente()
{

}
void Gerente::setAreaSupervisao(string supervisao)
{
    AreaSupervisao = supervisao;
}
string Gerente::getAreaSupervisao()
{
    return AreaSupervisao;
}
void Gerente::aumentarSalario()
{
    Salario+=Salario*percent;
}

 
