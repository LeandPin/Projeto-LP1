#include "../Headers/Gerente.h"

Gerente::Gerente()
{

}

Gerente::~Gerente()
{

}

void Gerente::CalcularFolhaSalarial(){

}
void Gerente::setAreaSupervisao(string supervisao){
AreaSupervisao = supervisao;
}
string Gerente::getAreaSupervisao(){
 return AreaSupervisao;
}

void Gerente::ExibirRegistro(){
cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
cout << "\n---Dados dos Gerentes: " <<Nome <<"\n" <<endl;
cout <<"Nome:" << Nome <<" Código: "<< Codigo << " Endereço: " << Endereco << " Telefone: " << Telefone << endl;
cout << "Designação: " << Designacao << " Data de Ingresso: " << Dia <<"/" << Mes <<"/"<<Ano << " Salário: " << Salario << endl;
cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
 }

void Gerente::ExibirLista(){
    ExibirRegistro();
}

 
