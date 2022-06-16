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

void CapturarRosto(String cod)
{
    double scale = 1.0;
    Mat img;
    vector<Mat> facesCortadas;
    vector<Rect> facesRect;
    VideoCapture cap(0);
    CascadeClassifier face;

    face.load("../OpenCV_files/haarcascade_frontalface_alt.xml");


    if (!cap.isOpened()) //verifico se ela não está aberta
    {
        cout<<"ERRO: A camera não foi aberta"<<endl;
        //return -1; //caso ela não esteja disponível eu encerro meu programa  
    }
    else
    {
        while (true)
        {
            Mat frame; // crio uma matriz chamada frame
            cap >> frame; //Jogo os frames do video dentro da minha matriz frame

            imshow("Webcam", frame);//Exibo minha matriz 

            if(pollKey() >= 0) //Encerro a aplicação caso o usuário aperte alguma tecla
            {
                int k = waitKey(0);
                if(k == 's' || k == 'S') //se apertar s ele salva exatamente no frame que está sendo mostrado no display
                {
                    img = frame;
                    break;    
                }
                else if (k == 27) // se apertar esc ele encerra o programa
                {
                    continue;
                    //return 0;
                } 
            }
        }
        
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
    
    if (!fs.is_open()) {
        cout << "Erro ao abrir arquivo para escrita\n";
        return;
    }

    for (int i = 0; i < func.size(); i++) {
        fs << func[i]->getTipo() << endl;
        fs << func[i]->getCodigo() << endl;
        fs << func[i]->getNome() << endl;
        fs << func[i]->getTelefone() << endl;
        fs << func[i]->getData() << endl;
        fs << func[i]->getSalario() << endl;
        /*if (func[i]->getTipo() == 2)
            fs << ((Consultor*)func[i])->getPercentual() << endl;*/
    }
    fs.close();
}

vector<Funcionario *> LerArquivo() {
    vector<Funcionario *> func;
    Funcionario *f;
    fstream fs;
    int quant, tipo;
    string codigo, nome, telefone;
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
        fs >> salario;

        if (tipo == 1)
            f = new Funcionario();
        
        /*else if (tipo == 2) {
            fs >> per;
            f = new Consultor(per);
        }*/
        f ->setCodigo(codigo);
        f ->setNome(nome);
        f ->setTelefone(telefone);
        f ->setData(data);
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
    string codigo, nome, telefone;
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
    cout<<" 7. Busca Funcionário"<< endl;
    cin >> escolha;
    system("clear||cls");
    return escolha;
}

int main()
{
    string cod, compara;
    int opc;
    GerenciaFuncionario *gerenciador = new GerenciaFuncionario;
    vector<Funcionario*> funcionarios;
    funcionarios = LerArquivo();
    
    while (1)
    {
        int escolha = Menu();
        switch (escolha)
        {
        case 1:
            CadastrarFunc(&funcionarios);
            SalvarArquivo(funcionarios);
            break;
        case 2:
            cin.ignore();
            cout << "Digite o Codigo do Funcionário: " << endl;
            getline(cin,cod);
            gerenciador->ExibirRegistro(cod, funcionarios);
            cin.ignore();
            break;
        case 3:
            //Excluir Funcionário
            break;
        case 4:
            cin.ignore();
            gerenciador->ExibirListaGeral(funcionarios);
            cin.ignore();
            break;
        case 5:
            //Calcular folha salarial
            break;
        case 6:
            //Editar Funcionário
            break;
        case 7:
            cin.ignore();
            cout << "Digite 1 para buscar funcionário por nome, 2 por data de admissão" << endl;
            cin >> opc;
            cin.ignore();
            cout << "Digite para a busca" << endl;
            getline(cin, compara);
            gerenciador->BuscaFuncionario(opc,compara, funcionarios);
            cin.ignore();

            break;
        default:
            break;
        }
    }
    
    
    return 0;
}