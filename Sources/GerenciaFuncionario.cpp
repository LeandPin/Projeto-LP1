#include "../Headers/GerenciaFuncionario.h"


GerenciaFuncionario::GerenciaFuncionario()
{

}
GerenciaFuncionario::~GerenciaFuncionario()
{

}
<<<<<<< HEAD
void GerenciaFuncionario::BuscaFuncionario(int tipobusca,string cod) 
{
    //Função Apenas com lógica implementada, aqui realiza a busca parcial, com uso da função find.//
    
    //Para realizar a busca com código, é só comparar com == o parametro e o objeto referente ao codigo do func//
    int cont;
 for (int i = 0; i < 1; i++)

    {
     if(1)
     {
=======
void GerenciaFuncionario::BuscaFuncionario(string cod,  vector <Funcionario *> func) 
{
    //Função Busca Parcialmente Pelo nome
        int cont =0;
      for (int i = 0; i < func.size(); i++) {
    if(func[i]->getNome().find(cod) != string ::npos ){
>>>>>>> 727e520f1744852b093e2f8366dd2de07c0cf00e
      cont ++;
    cout << "Código: "<<func[i]->getCodigo() << endl;
    cout << "Nome: "<<func[i]->getNome() << endl;
    cout << "Telefone: "<<func[i]->getTelefone() << endl;
    cout << "Data de admissão: "<<func[i]->getData() << endl;
    cout << "Salário: "<<func[i]->getSalario() << endl;
    
     }
          
    }
    if(cont == 0){
    cout << "Funcionario não encontrado" << endl;
    }
<<<<<<< HEAD

=======
      
>>>>>>> 727e520f1744852b093e2f8366dd2de07c0cf00e
}
void GerenciaFuncionario::ExibirRegistro(string cod, vector <Funcionario *> func)
{
    for (int i = 0; i < func.size(); i++) {
        if(cod == func[i]->getCodigo())
        {
            cout << "Código: "<<func[i]->getCodigo() << endl;
            cout << "Nome: "<<func[i]->getNome() << endl;
            cout << "Telefone: "<<func[i]->getTelefone() << endl;
            cout << "Data de admissão: "<<func[i]->getData() << endl;
            cout << "Salário: "<<func[i]->getSalario() << endl;
            cod = "open ../Fotos/"+cod+".png";
            system(cod.c_str());
        /*if (func[i]->getTipo() == 2)
                cout << " - Per: " << ((Consultor*)func[i])->getPercentual();*/
        }
    }
}

string GerenciaFuncionario::EditarDados()
{
}
<<<<<<< HEAD
void GerenciaFuncionario::ExibirListaGeral(vector <Funcionario*>* func)
{
   
    for(int i = 0; i < func->size(); i++){
       cout <<"Exibindo Nome do Funcionário: "<< endl;
        
    }
}

void ExibirListaTipo(){
    
=======
void GerenciaFuncionario::ExcluirRegistro(string cod)
{
    
}

void GerenciaFuncionario::ExibirLista(vector <Funcionario *> func)
{
    for (int i = 0; i < func.size(); i++) 
    {
        cout << "Código: "<<func[i]->getCodigo() << " - "<< "Nome: "<<func[i]->getNome() << endl;
    }
>>>>>>> 727e520f1744852b093e2f8366dd2de07c0cf00e
}
void GerenciaFuncionario::Busca()
{

}
void GerenciaFuncionario::CalcularFolhaSalarial()
{

}
void GerenciaFuncionario::ImprimirFolhaSalarial()
{
    
}