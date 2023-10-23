#include<string>
#include<iostream>
#include<ctime>

using namespace std;

#define TAM = 10

int main(){
    typedef struct {
        struct tm data; 
        char nome[100];
        int idade;
        float peso;
        float altura;
        float imc;
        int urgencia;
        char resultado[30];
    } Atendimento;
    
    Atendimento vetor(TAM);    
    int opcao, x, valor;
    char letra;
    int i=0;
    

    do{
        system("cls");
        cout<<"MENU! \n";
        cout<<"1 - Cadastro de Nova Triagem.\n";
        cout<<"2 - Consulte Triagem.\n";
        cout<<"3 - Pesquise Triagem.\n";
        cout<<"4 - Sair do Sistema.\n";
        cout<<"Opcao: \n";
        cin>> opcao;

        switch (opcao){
            case 1:
                cout<<"Cadastro!\n";
                if (Atendimento == TAM){
                    cout<<"Sistema Lotado!";
                    break;
                }
                else{
                    time_t t = time(NULL);
                    data = localtime(&t);

                    cout<<"Digite o Nome: ";
                    cin>>nome;
                    nome = nome.upper;
                }

            
        }
    }

}
