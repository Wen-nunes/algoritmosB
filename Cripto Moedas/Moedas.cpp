#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "struct.h"

#include "metodos.h"

int main() {
    Criptomoeda* vetor = nullptr;
    int totalCriptomoedas = 0;
    int capacidade = 0; 

    carregarCriptomoedas(vetor, totalCriptomoedas, capacidade);

    int opcao;

    do {
        cout << "MENU" << endl;
        cout << "1 - Cadastrar Criptomoeda" << endl;
        cout << "2 - Atualizar Valor" << endl;
        cout << "3 - Remover Criptomoeda" << endl;
        cout << "4 - Listar Criptomoedas" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                Cadastrar(vetor, totalCriptomoedas, capacidade);
                salvarCriptomoedas(vetor, totalCriptomoedas);
                break;
            case 2:
                atualizar(vetor, totalCriptomoedas);
                salvarCriptomoedas(vetor, totalCriptomoedas);
                break;
            case 3:
                remover(vetor, totalCriptomoedas);
                salvarCriptomoedas(vetor, totalCriptomoedas);
                break;
            case 4:
                listar(vetor, totalCriptomoedas);
                carregarCriptomoedas(vetor, totalCriptomoedas, capacidade);
                break;
            case 5:
                cout << "Obrigado por usar nosso sistema..." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
        }
    } while (opcao != 5);

    delete[] vetor; 

    return 0;
}