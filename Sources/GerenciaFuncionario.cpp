#include "../Headers/GerenciaFuncionario.h"


GerenciaFuncionario::GerenciaFuncionario()
{

}
GerenciaFuncionario::~GerenciaFuncionario()
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
            cod = "open ../Fotos/"+cod+".png";
            system(cod.c_str());
        /*if (func[i]->getTipo() == 2)
                cout << " - Per: " << ((Consultor*)func[i])->getPercentual();*/
        }
    }
}

void GerenciaFuncionario::EditarDados(string cod, vector <Funcionario *> func)
{
    string aux;
    int item;
    for (int i = 0; i < func.size(); i++) {
        if(cod == func[i]->getCodigo())
        {
            system("clear||cls");
            cout << "O que você seja editar :"<< endl;
            cout<<" 1. Nome"<< endl;
            cout<<" 2. Telefone"<< endl;
            cin >> item;
            system("clear||cls");
            
            switch (item)
            {
            case 1:
                cin.ignore();
                cout << "Digite o novo nome:" << endl;
                getline(cin, aux);
                func[i]->setNome(aux);
                break;
            case 2:
                cin.ignore();
                cout << "Digite o novo telefone:" << endl;
                getline(cin, aux);
                func[i]->setTelefone(aux);
                break;
            default:
                break;
            }
        /*if (func[i]->getTipo() == 2)
                cout << " - Per: " << ((Consultor*)func[i])->getPercentual();*/
        }
    }
}

vector <Funcionario *> GerenciaFuncionario::ExcluirRegistro(string cod, vector <Funcionario *> func)
{  
    for (int i = 0; i < func.size(); i++) {
        if(cod == func[i]->getCodigo())
        {
            func.erase(func.begin()+i);
        }
    }
    return func;
}

void GerenciaFuncionario::ExibirListaGeral(vector <Funcionario *> func)
{
    for (int i = 0; i < func.size(); i++) 
    {
        cout << "Código: "<<func[i]->getCodigo() << " - "<< "Nome: "<<func[i]->getNome() << endl;
    }
}

void GerenciaFuncionario::Busca(int tipo, vector <Funcionario *> func)
{
    int cont = 0;
    string aux;
    switch (tipo)
    {
    case 1:
        system("clear||cls");
        cin.ignore();
        cout << "Digite o nome que vai ser buscado: " << endl;
        getline(cin, aux);
        break;
    case 2:
        system("clear||cls");
        cin.ignore();
        cout << "Digite a data de ingressão que vai ser buscada: " << endl;
        cout << "Pode ser dia, mês , ano ou até mesmo a data completa" << endl;
        getline(cin, aux);
        break;
    default:
        break;
    }

    for (int i = 0; i < func.size(); i++) 
    {
        if(func[i]->getNome().find(aux) != string ::npos )
        {
            cont ++;
            cout << "Código: "<<func[i]->getCodigo() << endl;
            cout << "Nome: "<<func[i]->getNome() << endl;
            cout << "Telefone: "<<func[i]->getTelefone() << endl;
            cout << "Data de admissão: "<<func[i]->getData() << endl;
            cout << "Salário: "<<func[i]->getSalario() << endl;
        }
    }
    if(cont == 0)
    {
        cout << "Funcionario não encontrado" << endl;
    }

}

void GerenciaFuncionario::CalcularFolhaSalarial()
{

}
void GerenciaFuncionario::ImprimirFolhaSalarial()
{
    
}