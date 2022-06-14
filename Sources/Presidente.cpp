#include "../Headers/Presidente.h"

Presidente::Presidente()
{

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