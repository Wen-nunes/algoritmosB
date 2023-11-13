#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "struct.h"

#include "metodos.h"

int main() {
    Laboratorios* vetor = nullptr;
    int totaldeSalas = 0;
    int totaldePessoas = 0;
    int salas = 0; 

    CarregarSalas(vetor, totaldeSalas, salas);

    int opcao;

    cout << "Quantas salas quer gerenciar: ";
    cin >> salas;

    vetor = new Laboratorios[salas];
    delete[] vetor; // Liberar memória alocada antes de sair

    do {
        cout << "MENU" << endl;
        cout << "1 - Cadastrar salas ou laboratorios" << endl;
        cout << "2 - Cadastrar pessoas autorizadas" << endl;
        cout << "3 - Autorização do uso de salas" << endl;
        cout << "4 - Listar de salas cadastradas" << endl;
        cout << "5 - Lista de pessoas autorizadas" << endl;
        cout << "6 - Remover autorização" << endl;
        cout << "7 - Deletar sala ou laboratorio" << endl;
        cout << "8 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                Cadastrar(vetor, totaldeSalas, salas);
                SalvarSalas(vetor, totaldeSalas);
                break;
            case 2:
                
                break;
            case 3:
                remover(vetor, totalCriptomoedas);
                salvarCriptomoedas(vetor, totalCriptomoedas);
                break;
            case 4:
                listar(vetor, totalCriptomoedas);
                break;
            case 5:
               
                break;
            case 6:
               
                break;
            case 7:
               
                break;
            case 8:
                cout << "Obrigado por usar nosso sistema..." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
        }
    } while (opcao != 5);

    delete[] vetor; 

    return 0;
}