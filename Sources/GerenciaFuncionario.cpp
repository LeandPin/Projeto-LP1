#include "../Headers/GerenciaFuncionario.h"


GerenciaFuncionario::GerenciaFuncionario()
{

}
GerenciaFuncionario::~GerenciaFuncionario()
{

}
void GerenciaFuncionario::BuscaFuncionario(string cod) 
{
    
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
        /*if (func[i]->getTipo() == 2)
                cout << " - Per: " << ((Consultor*)func[i])->getPercentual();*/
        }
    }
}

string GerenciaFuncionario::EditarDados()
{
}
void GerenciaFuncionario::ExcluirRegistro(string cod)
{
    
}

void GerenciaFuncionario::ExibirLista(vector <Funcionario *> func)
{
    for (int i = 0; i < func.size(); i++) 
    {
        cout << "Código: "<<func[i]->getCodigo() << " - "<< "Nome: "<<func[i]->getNome() << endl;
    }
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