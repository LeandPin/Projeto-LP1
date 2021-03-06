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
            cout << "Área de supervisão: "<<func[i]->getAreaSupervisao() << endl;
            cout << "Área de formação: "<<func[i]->getAreaFormacao() << endl;
            cout << "Formação Academica: "<<func[i]->getFormacaoAcademica() << endl;
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
    string aux, acesso;
    int tipo, cont = 0;
    double sal;
    int item;
    for (int i = 0; i < func.size(); i++) 
    {
        if(cod == func[i]->getCodigo())
        {
            cont++;
            cout << "O que você seja editar :"<< endl;
            cout<<" 1. Endereço"<< endl;
            cout<<" 2. Telefone"<< endl;
            cout<<" 3. Salário"<< endl;
            cout<<" 4. Foto"<< endl;
            cout<<" 5. Cargo"<< endl;
            cout<<" 6. Nome"<< endl;
            cout<<" 7. Data de ingresso"<< endl;
            cout<<" 8. Código"<< endl;
            cout<<" 9. Cancelar"<< endl;
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
                cin.ignore();
                cout << "Selecione o novo cargo do Funcionário: " << endl;
                cout<<" 1. Operador" << endl;
                cout<<" 2. Gerente"<< endl;
                cout<<" 3. Diretor"<< endl;
                cout<<" 4. Presidente"<< endl;
                cin >> tipo;
                switch (tipo)
                {
                case 1:
                    func[i]->setPercent(0.05);
                    break;
                case 2:
                    func[i]->setPercent(0.1);
                    break;
                case 3:
                    func[i]->setPercent(0.2);
                    break;
                case 4:
                    func[i]->setPercent(0.3);
                    break;
                default:
                    cout<<"Digito errado"<<endl;
                    break;
                }
                func[i]->setTipo(tipo);
                break;
            case 6:
                cin.ignore();
                cout << "Digite o novo nome:" << endl;
                getline(cin, aux);
                func[i]->setNome(aux);
                break;
            case 7:
                cin.ignore();
                cout << "Digite a nova data de ingressão:" << endl;
                cout << "Exemplo: 01/10/2001"<<endl;
                getline(cin, aux);
                func[i]->setData(aux);
                break;
            case 8:
                cin.ignore();
                cout << "Digite o novo código:" << endl;
                getline(cin, aux);
                while (!disponibilidadeCod(aux,func))
                {   
                    cout << "---Código em uso---"<<endl;
                    cout << "Digite o código do Funcionário: " << endl;
                    getline(cin, aux);
                }
                acesso = "mv ../Fotos/"+func[i]->getCodigo()+".png ../Fotos/"+aux+".png";
                system(acesso.c_str());
                func[i]->setCodigo(aux);
                break;
            case 9:
                return 1;
                break;
            default:
                break;
            }
        }
    }
    if (cont == 0)
    {
        cin.ignore();
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
void GerenciaFuncionario::AumentarSalarios(vector <Funcionario *> func)
{
    for (int i = 0; i < func.size(); i++) 
    {
        func[i]->aumentarSalario();
    }
}
int GerenciaFuncionario::disponibilidadeCod(string cod, vector <Funcionario *> func)
{
    int cont=0;
    for (int i = 0; i < func.size(); i++) 
    {
        if(cod == func[i]->getCodigo())
        { 
            cont++;
        }
    }
    if (cont == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
vector<string>  GerenciaFuncionario::ImprimirFolhaSalario(vector <Funcionario *> func, int opc, int mesOUano, vector<string> codi, string cod)
{
    string codFolhaCalc;
    int aux, rDias, rHorasEx;
    double sal;
    
    switch (opc)
    {
    case 1://Func
        system("clear||cls");
        for (int i = 0; i < func.size(); i++) 
        {
            if(cod == func[i]->getCodigo())
            {
                //caso o vector esteja vazio
                if (codi.size() <= 0)
                {
                    if(mesOUano == 2) //28 dias
                    {
                        cout<<"Calculando folha salário do mês "+to_string(mesOUano)+" pela primeira vez:"<<endl;   
                        rDias = rand() % 29;
                    }
                    else if (mesOUano == 4 ||mesOUano == 6 || mesOUano == 9 || mesOUano == 11 )//30
                    {
                        cout<<"Calculando folha salário do mês "+to_string(mesOUano)+" pela primeira vez:"<<endl;   
                        rDias = rand() % 31;
                    }
                    else if (mesOUano > 0 && mesOUano < 13)//31 dias
                    {
                        cout<<"Calculando folha salário do mês "+to_string(mesOUano)+" pela primeira vez:"<<endl;   
                        rDias = rand() % 32;
                    }
                }
                else
                {      
                    for (int j = 0; j < codi.size(); j++)
                    {   
                        
                        if(func[i]->getCodigo()+"m"+to_string(mesOUano) == codi[j])
                        {
                            cout<< "Folha do mês "+to_string(mesOUano)+" já calculada :"<< endl;
                        }
                    }
                    if(mesOUano == 2) //28 dias
                    {
                        cout<<"Calculando folha salário do mês "+to_string(mesOUano)+" pela primeira vez:"<<endl;   
                        rDias = rand() % 29;
                    }
                    else if (mesOUano == 4 ||mesOUano == 6 || mesOUano == 9 || mesOUano == 11 )//30
                    {
                        cout<<"Calculando folha salário do mês "+to_string(mesOUano)+" pela primeira vez:"<<endl;   
                        rDias = rand() % 31;
                    }
                    else if (mesOUano > 0 && mesOUano < 13)//31 dias
                    {
                        cout<<"Calculando folha salário do mês "+to_string(mesOUano)+" pela primeira vez:"<<endl;   
                        rDias = rand() % 32;
                    }
                }

                rHorasEx = rand() % 131;
                codFolhaCalc = cod+"m"+to_string(mesOUano);
                codi.push_back(codFolhaCalc);
                codi.push_back(to_string(rDias));
                codi.push_back(to_string(rHorasEx));
                
                if(mesOUano <13)//mensal
                {
                    for (int j = 0; j < codi.size(); j++)
                    {   
                        if(func[i]->getCodigo()+"m"+to_string(mesOUano) == codi[j])
                        {
                            cout <<"Empregado: "+func[i]->getNome()<<endl;
                            cout.precision(2);
                            cout <<"Salário base: R$" << fixed<<(func[i]->getSalario())<<endl;
                            sal = (((func[i]->getSalario()/30)/8)*stoi(codi[j+2]))*2;
                            cout<<"Acréssimo de R$" <<fixed<<sal<< +" devido a "+codi[j+2]+"h00min de horas extras."<<endl;
                            sal = sal + func[i]->getSalario();
                            cout<<"Descontos:"<<endl;
                            cout<<"INSS: "<<endl;
                            if(sal <= 1212)
                            {   
                                cout << "7,5% -> R$"<<fixed<<sal * 0.075<<endl;
                                codi.push_back(to_string(sal *0.075));                            
                                sal -= sal * 0.075;
                            }
                            else if(sal <= 2427.35)
                            {                                                
                                cout << "9% -> R$"<<fixed<<sal * 0.09<<endl;                            
                                codi.push_back(to_string(sal * 0.09));
                                sal -= sal * 0.09;        
                            }
                            else if(sal <= 3641.03)
                            {                                        
                                cout << "12% -> R$"<<fixed<<sal * 0.12<<endl;
                                codi.push_back(to_string(sal* 0.12));
                                sal -= sal * 0.12;
                            }
                            else
                            {                                                
                                cout << "14% -> R$"<<fixed<<sal * 0.14<<endl; 
                                codi.push_back(to_string(sal * 0.14));                           
                                sal -= sal * 0.14;        
                            }
                            cout<<"IRRF: "<<endl;
                            if (sal < 1903.99)
                            {
                                cout << "0% -> R$"<<fixed<<0<<endl;
                                codi.push_back(to_string(0));                                                       
                            }
                            else if(sal > 1903.99 && sal <= 2826.65)
                            {                               
                                cout << "7,5% -> R$"<<fixed<<sal * 0.075<<endl;  
                                codi.push_back(to_string(sal * 0.075));                                                     
                                sal -= sal * 0.075;
                            }
                            else if(sal<= 3751.05)
                            {                                                        
                                cout << "15% -> R$"<<fixed<<sal * 0.15<<endl;        
                                codi.push_back(to_string(sal * 0.15));                           
                                sal -= sal * 0.15;                    
                            }
                            else if(sal <= 4664.68)
                            {                                                
                                cout << "12% -> R$"<<fixed<<sal * 0.225<<endl;
                                codi.push_back(to_string(sal * 0.225));                           
                                sal -= sal * 0.225;
                            }
                            else
                            {                                                        
                                cout << "14% -> R$"<<fixed<<sal * 0.227<<endl;                            
                                codi.push_back(to_string(sal * 0.227));                           
                                sal -= sal * 0.227;
                            }
                            cout << "O salário liquido é de: R$" <<fixed<<sal<<endl;
                            cout << "O total de dias de trabalho são: "+codi[j+1]<<endl;
                            codi.push_back(to_string(sal));
                            return codi;
                        }
                    }    
                }
                else//anual
                {
                    double salF = 0, descInssT=0, descIrrfT=0, acresF = 0;
                    int dT =0, hrET = 0;
                    for (int j = 0; j < codi.size(); j++)
                    {   
                        for ( int p = 1; p < 13; p++)
                        {
                            if(func[i]->getCodigo()+"m"+to_string(p) == codi[j])
                            {
                                dT += stoi(codi[j+1]);//Dias totais
                                hrET += stoi(codi[j+2]);//Horas extras totais
                                descInssT += stod(codi[j+3]);//Desc inss total
                                descIrrfT += stod(codi[j+4]);//Desc inss total
                                salF += stod(codi[j+5]);//salario total
                            }
                        }                                                
                    }
                    acresF = salF-(func[i]->getSalario()*12)-descInssT-descIrrfT;
                    cout <<"Empregado: "+func[i]->getNome()<<endl;
                    cout.precision(2);
                    cout <<"Salário base (anual): R$" << fixed<<((func[i]->getSalario())*12)<<endl;                    
                    cout<<"Acréssimo de R$" <<fixed<<acresF<< +" devido a "<<hrET<<"h00min de horas extras no ano."<<endl;                    
                    cout<<"Descontos totais:"<<endl;
                    cout<<"INSS: "<<endl;
                    cout<<"R$"<<fixed<<descInssT<<endl;
                    cout<<"IRRF: "<<endl;
                    cout<<"R$"<<fixed<<descIrrfT<<endl;
                    cout << "O salário liquido é de: R$" <<fixed<<salF<<endl;
                    cout << "O total de dias de trabalho são: "<<dT<<endl;

                }
                   
            }
        }
        break;
    
    case 2://Empresa
        break;
    
    default:
        break;
    }
    return codi;        
}