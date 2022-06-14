#include <iostream>
#include  <string.h>
#include <opencv2/opencv.hpp>
#include "../Headers/Diretor.h"
#include "../Headers/Funcionario.h"
#include "../Headers/Gerente.h"
#include "../Headers/Operador.h"
#include "../Headers/Presidente.h"
#include <vector>

using namespace cv;
using namespace std;

void CapturarRosto(String nome)
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
        cout<<"ERRO"<<endl;
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
                    break;
                    //return 0;
                }
                else // se não apertar nem s nem esc ele continua no loop
                {
                    continue;
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
        imwrite("../Fotos/"+nome+".png",facesCortadas[i]);
    }
}

int main()
{
    string nome = "RoertinhoDaTapioca";
    CapturarRosto(nome);



/*  string nome, codigo, endereco, telefone;
    string cargo;
    double salario;
    string procura;
    string Dia, mes, ano;
    
        Funcionario *diretor = new Diretor();

        vector <Funcionario> diretor;

  */      
    return 0;

}