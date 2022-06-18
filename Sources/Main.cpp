#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <opencv2/opencv.hpp>
#include "../Headers/GerenciaFuncionario.h"
#include "../Headers/Diretor.h"
#include "../Headers/Funcionario.h"
#include "../Headers/Gerente.h"
#include "../Headers/Presidente.h"

using namespace cv;
using namespace std;

//Não conseguir detectar rosto
void CapturarRosto(String cod)
{
    double scale = 1.0;
    Mat img;
    vector<Mat> facesCortadas;
    vector<Rect> facesRect;
    VideoCapture cap(0);
    CascadeClassifier face;

    face.load("../OpenCV_files/haarcascade_frontalface_alt.xml");


    if (!cap.isOpened()) 
    {
        cout<<"ERRO: A camera não foi aberta"<<endl;
    }
    else
    {
        while (true)
        {
            Mat frame; 
            cap >> frame; 
            imshow("Webcam", frame);
            if(pollKey() >= 0) 
            {
                int k = waitKey(0);
                if(k == 's' || k == 'S') //se apertar s ele salva exatamente no frame que está sendo mostrado no display
                {

                    img = frame;
                    break;    
                }
            }
        }
        destroyAllWindows();
    }
    
    resize(img, img, Size(img.size().width/scale,img.size().height/scale));
    face.detectMultiScale(img, facesRect, 1.1, 4, CASCADE_SCALE_IMAGE, Size(20, 20));
    
    for (size_t i = 0; i < facesRect.size(); i++)
    { 
        facesCortadas.push_back(img(facesRect[i]));
    }
    for (int i = 0; i < facesCortadas.size(); i++)
    {
        resize(facesCortadas[i], facesCortadas[i], Size(300,300));
        imwrite("../Fotos/"+cod+".png",facesCortadas[i]);
    }
}

void SalvarArquivo(vector<Funcionario *> func) {
    fstream fs;
    fs.open("dados.txt", fstream::out);
    
    if (!fs.is_open()) 
    {
        cout << "Erro ao abrir arquivo para escrita\n";
        return;
    }

    for (int i = 0; i < func.size(); i++) 
    {
        fs << func[i]->getTipo() << endl;
        fs << func[i]->getCodigo() << endl;
        fs << func[i]->getNome() << endl;
        fs << func[i]->getTelefone() << endl;
        fs << func[i]->getData() << endl;
        fs << func[i]->getEnd() << endl;
        fs << func[i]->getSalario() << endl;
    }
    fs.close();
}

vector<Funcionario *> LerArquivo() {
    vector<Funcionario *> func;
    Funcionario *f;
    fstream fs;
    int quant, tipo;
    string codigo, nome, telefone, end;
    string data;
    double salario;
    fs.open("dados.txt", fstream::in);
    
    if (!fs.is_open()) 
    {
        cout << "Erro ao abrir arquivo para leitura\n";
        return func;
    }
    
    while (!fs.eof()) {
        fs >> tipo;
        if (fs.eof())
        {
            break;
        }
        
        fs.ignore();
        getline(fs, codigo);
        getline(fs, nome);
        getline(fs, telefone);
        getline(fs, data);
        getline(fs, end);
        fs >> salario;

        switch (tipo) 
        {
            case 1:
                f = new Funcionario();
                break;
            
            case 2:
                f = new Gerente();
                break;
            
            case 3:
                f = new Diretor();
                break;
            
            case 4:
                f = new Presidente();
                break;
        }

        f->setTipo(tipo);
        f ->setCodigo(codigo);
        f ->setNome(nome);
        f ->setTelefone(telefone);
        f ->setData(data);
        f ->setEnd(end);
        f ->setSalario(salario);
        func.push_back(f);
    }
    
    fs.close();
    return func;
}

void CadastrarFunc(vector<Funcionario *>* func)
{
    system("clear||cls");
    cout << "Quantos Funcionários você deseja cadastrar" << endl;
    
    int quant, tipo;
    string codigo, nome, telefone, end;
    string data;
    double salario;
    Funcionario * f;
    cin >> quant;
    system("clear||cls");
    
    for (int i = 0; i < quant; i++) 
    {
        cout << "Qual tipo de Funcionários você deseja cadastrar" << endl;
        cout<<" 1. Operador" << endl;
        cout<<" 2. Gerente"<< endl;
        cout<<" 3. Diretor"<< endl;
        cout<<" 4. Presidente"<< endl;
        cout<<" 5. Voltar"<< endl;
        cin >> tipo;

        system("clear||cls");
        
        switch (tipo) {
            case 1:
                f = new Funcionario();
                break;
            case 2:
                f = new Gerente();
                break;
            case 3:
                f = new Diretor();
                break;
            case 4:
                f = new Presidente();
                break;
            case 5:
                return;
                break;
        }

        cin.ignore();

        cout << "Digite o código do Funcionário: " << endl;
        getline(cin, codigo);

        cout << "Digite o Nome do Funcionário: " << endl;
        getline(cin, nome);

        cout << "Digite o telefone para contato do Funcionário: " << endl;
        getline(cin, telefone);

        cout << "Digite a data de admissão do Funcionário: " << endl;
        getline(cin, data);

        cout << "Digite o endereço do Funcionário seguindo a seguinte formatação: " << endl;
        cout << "R. dos pescadores, 301 - Ponta dos Seixas - João Pessoa/PB " << endl;
        cout << "Caso seja em avenida basta mudar o \"R.\" por \"Av.\" e se for apartamento basta colocar a abreviação \"Apto.\" seguida do número, exemplo: " << endl;
        cout << "Av. dos pescadores, 301 - Apto.401 - Ponta dos Seixas - João Pessoa/PB " << endl;
        getline(cin, end);

        cout << "Digite o salário do Funcionário: " << endl;
        cin >> salario;

        system("clear||cls");
        cout << "Será realizado a captura da face do Funcioário cadastrado, intruções para a captura ser bem sucedida :"<< endl;
        cout << "1. Imagem nitida olhando para camêra com um boa iluminação" << endl;
        cout << "2. Digite qualquer tecla para estar capturando a foto"<<endl;
        cout << "3. Caso a foto ficou agradavél para você basta apertar a tecla \" S\" para estar salvando, caso a foto não tenha ficado agradável basta apertar qualquer tecla diferente de \"S\" para estar realizando uma nova captura" << endl;
        
        CapturarRosto(codigo);
        
        f ->setCodigo(codigo);
        f ->setNome(nome);
        f ->setTelefone(telefone);
        f ->setData(data);
        f->setEnd(end);
        f ->setSalario(salario);
        func->push_back(f);
        system("clear||cls");
    }
}

int Menu()
{
    system("clear||cls");
    int escolha;
    cout << "Escolha a operação que você deseja realizar:"<< endl;
    cout<<" 1. Cadastrar Funcionário" << endl;
    cout<<" 2. Exibir Funcionário"<< endl;
    cout<<" 3. Excluir Funcionário"<< endl;
    cout<<" 4. Exibir Lista de Funcionários"<< endl;
    cout<<" 5. Calcular folha salarial"<< endl;
    cout<<" 6. Editar Funcionário"<< endl;
    cout<<" 7. Buscar Funcionário"<< endl;
    cout<<" 8. Sair"<< endl;
    cin >> escolha;
    system("clear||cls");
    return escolha;
}

int main()
{
    string cod;
    int opc;
    GerenciaFuncionario *gerenciador = new GerenciaFuncionario;
    vector<Funcionario*> funcionarios;
    funcionarios = LerArquivo();
    
    while (1)
    {
        int escolha = Menu();
        switch (escolha)
        {
        case 1: //Cadastrar Funcionário //FALT CHECAR DISPONIBILIDADE DO COD
            CadastrarFunc(&funcionarios);
            SalvarArquivo(funcionarios);
            break;
        
        case 2: //Exibir Funcionário 
            cin.ignore();
            cout << "Digite o Codigo do Funcionário: " << endl;
            getline(cin,cod);
            gerenciador->ExibirRegistro(cod, funcionarios);
            cin.ignore();
            break;
        
        case 3: //Excluir Funcionário
            cin.ignore();
            cout << "Digite o Codigo do Funcionário que deseja excluir: " << endl;
            getline(cin,cod);
            cout << "Dados do funcionário que será EXCLUIDO: " << endl;
            gerenciador->ExibirRegistro(cod, funcionarios);
            cout << "Você realmente deseja excluir esse Funcionário ? " << endl;
            cout << "1. SIM " << endl;
            cout << "2. NÃO " << endl;
            cin >> opc;
            cin.ignore();
            if (opc == 1)
            {
                funcionarios = gerenciador->ExcluirRegistro(cod, funcionarios);
                SalvarArquivo(funcionarios);
                cin.ignore();
            }
            break;
        
        case 4: //Exibir Lista de Funcionário
            cin.ignore();
            gerenciador->ExibirListaGeral(funcionarios);
            break;
        
        case 5://Calcular folha salaria
            //Calcular folha salarial
            break;
        
        case 6://Editar Funcionário
            cin.ignore();
            cout << "Digite o Codigo do Funcionário que deseja editar: " << endl;
            getline(cin,cod);
            system("clear||cls");
            cout << "Dados do funcionário que será editado: " << endl;
            gerenciador->ExibirRegistro(cod, funcionarios);
            if(gerenciador->EditarDados(cod,funcionarios) == 4)
            {
                CapturarRosto(cod);
            }
            SalvarArquivo(funcionarios);
            break;
        
        case 7://Buscar Funcionário
            cin.ignore();
            cout << "Escolha a operação que você deseja realizar:"<< endl;
            cout<<" 1. Busca por nome" << endl;
            cout<<" 2. Busca por data de adimissão"<< endl;
            cout<<" 3. Busca por endereço"<< endl;
            cout<<" 4. Cancelar"<<endl;
            cin >> opc;
            gerenciador->Busca(opc, funcionarios);
            cin.ignore();
            break;
        
        case 8:
            return 0;
            break;

        default:
            break;
        }
    }
    
    return 0;
}