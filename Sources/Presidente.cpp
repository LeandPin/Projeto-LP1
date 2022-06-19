#include "../Headers/Presidente.h"

Presidente::Presidente()
{
    tipo = 4;
    percent = 0.3;
}
Presidente::~Presidente()
{

}

void Presidente::aumentarSalario()
{
    Salario+=Salario*percent;
}