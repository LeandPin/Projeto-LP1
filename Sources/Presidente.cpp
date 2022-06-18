#include "../Headers/Presidente.h"

Presidente::Presidente()
{
    tipo = 4;
    percent = 0.3;
}
Presidente::~Presidente()
{

}
void Presidente::setAreaFormacao(string formacao)
{
    AreaFormacao = formacao;
}
void Presidente::setFormacaoAcademica(string graduacao)
{
    FormacaoAcademica = graduacao;
}
string Presidente::getAreaFormacao()
{
    return AreaFormacao;
}
string Presidente::getFormacaoAcademica()
{
    return FormacaoAcademica;
}
void Presidente::aumentarSalario()
{
    Salario+=Salario*percent;
}