#include "../Headers/Diretor.h"

Diretor::Diretor()
:Funcionario()
{

}

Diretor::~Diretor()
{

}

void Diretor::CalcularFolhaSalarial(){

}

void Diretor::setAreaFormacao(string formacao){
  AreaFormacao = formacao;
}
void Diretor::setAreaSupervisao(string supervisao){
 AreaSupervisao =supervisao;
}
string Diretor::getAreaFormacao(){
 return AreaFormacao;
}
string Diretor::getAreaSupervisao(){
 return AreaFormacao;
}

void Diretor::ExibirLista(){

 ExibirRegistro();
 }

void Diretor::BuscaDiretor(string cod){
  if(getNome().find(cod) != string ::npos ){
    ExibirRegistro();
  }else
   cout << "Funcionario não cadastrado!";
}

void Diretor::ExibirRegistro(){
cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
cout << "\n---Dados do Diretores: " <<Nome <<"\n" <<endl;
cout <<"Nome:" << Nome <<" Código: "<< Codigo << " Endereço: " << Endereco << " Telefone: " << Telefone << endl;
cout << "Designação: " << Designacao << " Data de Ingresso: " << Dia <<"/" << Mes <<"/"<<Ano << " Salário: " << Salario << endl;
cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
 }