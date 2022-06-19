#include "../Headers/Gerente.h"

Gerente::Gerente()
{
    tipo = 2;
    percent = 0.1;
}
Gerente::~Gerente()
{

}
void Gerente::aumentarSalario()
{
    Salario+=Salario*percent;
}