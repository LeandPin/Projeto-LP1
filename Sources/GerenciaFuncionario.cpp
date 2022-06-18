#include "../Headers/GerenciaFuncionario.h"


GerenciaFuncionario::GerenciaFuncionario()
{

}
GerenciaFuncionario::~GerenciaFuncionario()
{

}

void GerenciaFuncionario::ExibirRegistro(string cod, vector <Funcionario *> func)
{
    int aux = 0;
    for (int i = 0; i < func.size(); i++) 
    {
        if(cod == func[i]->getCodigo())
        {       
            aux++;        
            switch (func[i]->getTipo())
            {
            case 1:
                cout << "Cargo : Operador" << endl;
                break;
            case 2:
                cout << "Cargo : Gerente" << endl;
                break;
            case 3:
                cout << "Cargo : Diretor"<< endl;
                break;
            case 4:
                cout << "Cargo : Presidente"<< endl;
                break;
            default:
                break;
            }
            cout << "Código: "<<func[i]->getCodigo() << endl;
            cout << "Nome: "<<func[i]->getNome() << endl;
            cout << "Telefone: "<<func[i]->getTelefone() << endl;
            cout << "Data de admissão: "<<func[i]->getData() << endl;
            cout << "Endereço: "<<func[i]->getEnd() << endl;
            cout << "Salário: "<<func[i]->getSalario() << endl;
            cod = "open ../Fotos/"+cod+".png";
            system(cod.c_str());
        }
    }
    if (aux == 0)
    {
        cout << "Nenhum funcionário encontrado" << endl;
    }
}

int GerenciaFuncionario::EditarDados(string cod, vector <Funcionario *> func)
{
    string aux;
    double sal;
    int item;
    for (int i = 0; i < func.size(); i++) 
    {
        if(cod == func[i]->getCodigo())
        {
            
            cout << "O que você seja editar :"<< endl;
            cout<<" 1. Endereço"<< endl;
            cout<<" 2. Telefone"<< endl;
            cout<<" 3. Salário"<< endl;
            cout<<" 4. Foto"<< endl;
            cout<<" 5. Cancelar"<< endl;
            cin >> item;
            system("clear||cls");
            
            switch (item)
            {
            case 1:
                cin.ignore();
                cout << "Digite o novo endereço do Funcionário seguindo a seguinte formatação: " << endl;
                cout << "R. dos pescadores, 301 - Ponta dos Seixas - João Pessoa/PB " << endl;
                cout << "Caso seja em avenida basta mudar o \"R.\" por \"Av.\" e se for apartamento basta colocar a abreviação \"Apto.\" seguida do número, exemplo: " << endl;
                cout << "Av. dos pescadores, 301 - Apto.401 - Ponta dos Seixas - João Pessoa/PB " << endl;
                getline(cin, aux);
                func[i]->setEnd(aux);
                break;
            
            case 2:
                cin.ignore();
                cout << "Digite o novo telefone:" << endl;
                getline(cin, aux);
                func[i]->setTelefone(aux);
                break;
            
            case 3:
                cin.ignore();
                cout << "Digite o novo salário do Funcionário: " << endl;
                cin >> sal;
                func[i]->setSalario(sal);
                break;
            case 4:
                return 4;
                break;
            case 5:
                return 1;
                break;
            default:
                break;
            }
        }
    }
    return 1;
}

vector <Funcionario *> GerenciaFuncionario::ExcluirRegistro(string cod, vector <Funcionario *> func)
{  
    for (int i = 0; i < func.size(); i++) {
        if(cod == func[i]->getCodigo())
        {
            if(func[i]->getTipo() < 3)
            {
                func.erase(func.begin()+i);
                cod = "rm ../Fotos/"+cod+".png";
                system(cod.c_str());
                cout << "Funcionário Excluido com sucesso"<<endl;
            }
            else
            {
                cout << "Cargo do funcionário não permite exclusão." << endl;
            }
        }
    }
    return func;
}

void GerenciaFuncionario::ExibirListaGeral(vector <Funcionario *> func)
{
    int aux;
    cout << "Escolha a operação que você deseja realizar:"<< endl;
            cout<<" 1. Exibir lista de um cargo especifico" << endl;
            cout<<" 2. Exibir lista geral"<< endl;
            cout<<" 3. Cancelar"<< endl;
    cin >> aux;
    cin.ignore();
    switch (aux)
    {
    case 1:
        cout << "Qual o cargo:"<< endl;
            cout<<" 1. Operador" << endl;
            cout<<" 2. Gerente"<< endl;
            cout<<" 3. Diretor" << endl;
            cout<<" 4. Presidente"<< endl;
            cin >> aux;
            cin.ignore();
            for (int i = 0; i < func.size(); i++) 
            {
                if (func[i]->getTipo() == aux)
                {
                    switch (func[i]->getTipo())
                    {
                    case 1:
                        cout << "Operador - ";
                        break;
                    case 2:
                        cout << "Gerente - ";
                        break;
                    case 3:
                        cout << "Diretor - ";
                        break;
                    case 4:
                        cout << "Presidente - ";
                        break;
                    default:
                        break;
                    }
                    cout << "Código: "<<func[i]->getCodigo() << " - "<< "Nome: "<<func[i]->getNome() << " - Salário: "<<func[i]->getSalario()<<endl;
                }
            }
            cin.ignore();
            break;
    case 2:
        for (int i = 0; i < func.size(); i++) 
        {
            
            switch (func[i]->getTipo())
            {
            case 1:
                cout << "Operador - ";
                break;
            case 2:
                cout << "Gerente - ";
                break;
            case 3:
                cout << "Diretor - ";
                break;
            case 4:
                cout << "Presidente - ";
                break;
            default:
                break;
            }
            cout << "Código: "<<func[i]->getCodigo() << " - "<< "Nome: "<<func[i]->getNome() << " - Salário: "<<func[i]->getSalario()<<endl;
        }   
        cin.ignore();
        break;
    case 3:
        return;
        break;
    default:
        break;
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
        for (int i = 0; i < func.size(); i++) 
        {
            if(func[i]->getNome().find(aux) != string ::npos )
            {
                switch (func[i]->getTipo())
                {
                case 1:
                    cout << "Operador - ";
                    break;
                case 2:
                    cout << "Gerente - ";
                    break;
                case 3:
                    cout << "Diretor - ";
                    break;
                case 4:
                    cout << "Presidente - ";
                    break;
                default:
                    break;
                }
                cont ++;
                cout << "Código: "<<func[i]->getCodigo() << endl;
                cout << "Nome: "<<func[i]->getNome() << endl;
                cout << "Telefone: "<<func[i]->getTelefone() << endl;
                cout << "Data de admissão: "<<func[i]->getData() << endl;
                cout << "Endereço: "<<func[i]->getEnd() << endl;
                cout << "Salário: "<<func[i]->getSalario() << endl;
            }
        }
        break;
        
    case 2:
        system("clear||cls");
        cin.ignore();
        cout << "Digite a data de ingressão que vai ser buscada: " << endl;
        cout << "Pode ser dia, mês , ano ou até mesmo a data completa" << endl;
        getline(cin, aux);

        for (int i = 0; i < func.size(); i++) 
        {
            if(func[i]->getData().find(aux) != string ::npos )
            {
                switch (func[i]->getTipo())
                {
                case 1:
                    cout << "Operador - ";
                    break;
                case 2:
                    cout << "Gerente - ";
                    break;
                case 3:
                    cout << "Diretor - ";
                    break;
                case 4:
                    cout << "Presidente - ";
                    break;
                default:
                    break;
                }
                cont ++;
                cout << "Código: "<<func[i]->getCodigo() << endl;
                cout << "Nome: "<<func[i]->getNome() << endl;
                cout << "Telefone: "<<func[i]->getTelefone() << endl;
                cout << "Data de admissão: "<<func[i]->getData() << endl;
                cout << "Endereço: "<<func[i]->getEnd() << endl;
                cout << "Salário: "<<func[i]->getSalario() << endl;
            }
        }
        break;
    
    case 3:

     system("clear||cls");
        cin.ignore();
        cout << "Digite o Endereço do Funcionário a ser buscado: " << endl;
       
        getline(cin, aux);

        for (int i = 0; i < func.size(); i++) 
        {
            if(func[i]->getEnd().find(aux) != string ::npos )
            {
                switch (func[i]->getTipo())
                {
                case 1:
                    cout << "Operador - ";
                    break;
                case 2:
                    cout << "Gerente - ";
                    break;
                case 3:
                    cout << "Diretor - ";
                    break;
                case 4:
                    cout << "Presidente - ";
                    break;
                default:
                    break;
                }
                cont ++;
                cout << "Código: "<<func[i]->getCodigo() << endl;
                cout << "Nome: "<<func[i]->getNome() << endl;
                cout << "Telefone: "<<func[i]->getTelefone() << endl;
                cout << "Data de admissão: "<<func[i]->getData() << endl;
                cout << "Endereço: "<<func[i]->getEnd() << endl;
                cout << "Salário: "<<func[i]->getSalario() << endl;
            }
        }
        break;
    case 4:
        return;
        break;
    default:
        break;
    }
    if(cont == 0)
    {
      cout << "Nenhum Funcionario Encontrado" << endl;
    }
}

void GerenciaFuncionario::CalcularFolhaSalarial()
{

}
void GerenciaFuncionario::ImprimirFolhaSalarial()
{
    
}