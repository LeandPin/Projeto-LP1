#include "../Headers/Gerente.h"

Gerente::Gerente()
{
    tipo = 2;
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

 
