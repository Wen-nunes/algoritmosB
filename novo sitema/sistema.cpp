#include <string>
#include <iostream>
#include<stdlib.h>
#include <ctime>
using namespace std;

#include "struct.h"
#include "util.h"

#define TAM 10

int main()
{
    Veiculo vetor[TAM];
    inicializarVetor(vetor, TAM);

    int opcao;
    int quantidadeCarros;
    

    do
    {
        system("cls");
        cout << "MENU \n";
        cout << "1 - Entrar na garagem\n";
        cout << "2 - Listar veiculo\n";
        cout << "3 - Remover da garagem\n";
        cout << "4 - sair do sistema\n";
        cout << "5 - opcao\n";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
           quantidadeCarros = entradaGaragem(vetor, TAM, quantidadeCarros);
            break;
        case 2:
           listarGaragem(vetor, TAM, quantidadeCarros);
            break;
        case 3:
            quantidadeCarros = sairGaragem(vetor, TAM, quantidadeCarros);
            cout << "Retirada de veiculo\n";
            break;
        case 4:
            cout<<"Sair do sistema";
            break;

        }
        system("pause");
    } while (opcao != 4);
    return 1;
}