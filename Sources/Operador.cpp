#include "../Headers/Operador.h"

Operador::Operador()
{

}

Operador::~Operador()
{

}
void Operador::ExibirLista(){
ExibirRegistro();
}
void Operador::CalcularFolhaSalarial(){

}

void Operador::ExibirRegistro(){
cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
cout << "\n---Dados dos Operadores: " <<Nome <<"\n" <<endl;
cout <<"Nome:" << Nome <<" Código: "<< Codigo << " Endereço: " << Endereco << " Telefone: " << Telefone << endl;
cout << "Designação: " << Designacao << " Data de Ingresso: " << Dia <<"/" << Mes <<"/"<<Ano << " Salário: " << Salario << endl;
cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
 }

