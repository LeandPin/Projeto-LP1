#include "../Headers/Presidente.h"

Presidente::Presidente()
{

}

Presidente::~Presidente()
{

}
void Presidente::setAreaFormacao(string formacao){
 AreaFormacao = formacao;
}
void Presidente::setFormacaoAcademica(string graduacao)
{
 FormacaoAcademica = graduacao;
}
string Presidente::getAreaFormacao(){
 return AreaFormacao;
}
string Presidente::getFormacaoAcademica(){
    return FormacaoAcademica;
}

void  Presidente::CalcularFolhaSalarial(){

}

void Presidente::ExibirRegistro(){
cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
cout << "\n---Dados do Diretor: " <<Nome <<"\n" <<endl;
cout <<"Nome:" << Nome <<" Código: "<< Codigo << " Endereço: " << Endereco << " Telefone: " << Telefone << endl;
cout << "Designação: " << Designacao << " Data de Ingresso: " << Dia <<"/" << Mes <<"/"<<Ano << " Salário: " << Salario << endl;
cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
 }

void Presidente::ExibirLista(){
    ExibirRegistro();
}