#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

double calcularTempoEstacionado(string horaEntrada, string horaSaida)
{
    int horaEntradaHora, horaEntradaMinuto, horaSaidaHora, horaSaidaMinuto;
    sscanf(horaEntrada.c_str(), "%d:%d", &horaEntradaHora, &horaEntradaMinuto);
    sscanf(horaSaida.c_str(), "%d:%d", &horaSaidaHora, &horaSaidaMinuto);

    int minutosEntrada = horaEntradaHora * 60 + horaEntradaMinuto;
    int minutosSaida = horaSaidaHora * 60 + horaSaidaMinuto;

    int minutosEstacionado = minutosSaida - minutosEntrada;

    // Converter minutos para horas
    double horasEstacionado = static_cast<double>(minutosEstacionado) / 60.0;

    // Valor fixo de 8 reais por hora
    double valorPago = horasEstacionado * 8.0;

    return valorPago;
}

void inicializarVetor (Veiculo vetor[], int n) {
    for (int i = 0; i < n; i++) {
        vetor[i].placa = "";
        vetor[i].horaEntrada = "";
    }
}


int entradaGaragem(Veiculo vetor[], int TAM, int quantidadeCarros){

    string placa, hora;
    bool carroLocalizado;
    
     cout << "Cadastro de Veiculo\n";
            if (quantidadeCarros == TAM)
            {
                cout << "Garagem lotada!";

            }else
            {
                while (true)
                {
                    cout << "Informe a placa em minusculo: ";
                    cin >> placa;
                    if (placa.length() == 7)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Digite a placa corretamente a placa\n";
                    }
                }
                    time_t rawtime;
                        struct tm * horaEntrada;

                        time ( &rawtime );
                        horaEntrada = localtime ( &rawtime );
                        printf ( "data e hora de entrada: %s", asctime (horaEntrada) );

                carroLocalizado = false;
                for (int i = 0; i < TAM; i++)
                {
                    if (placa == vetor[i].placa)
                    {
                        cout << "Carro ja na garagem\n";
                        carroLocalizado = true;
                        break;
                    }
                }
                if (!carroLocalizado)
                {
                    for (int i = 0; i < TAM; i++)
                    {
                        if (vetor[i].placa == "")
                        {
                            vetor[i].placa = placa;
                            vetor[i].horaEntrada = hora;
                            quantidadeCarros++;
                            break;
                        }
                    }
                }
            }
            return quantidadeCarros;
}

void listarGaragem(Veiculo vetor[], int TAM, int quantidadeCarros){
     cout << "Listagem de veiculos\n";
            if (quantidadeCarros == 0)
            {
                cout << "Garagem vazia\n";
            }
            else
            {
                for (int i = 0; i < TAM; i++)
                {
                    if (vetor[i].placa != "")
                    {
                        cout << "Placa: " << vetor[i].placa << endl;
                    }
                }
            }
}

int sairGaragem(Veiculo vetor[], int TAM, int quantidadeCarros){
    string placa, hora;
    bool carroLocalizado;
    
     cout << "Saida de Veiculo\n";
            if (quantidadeCarros == 0)
            {
                cout << "Garagem Vazia!";

            }else {  
                
                double valorPago; 
                
                while (true)
                {
                  

                    cout << "Informe a placa em minusculo: ";
                    cin >> placa;
                    if (placa.length() == 7)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Digite a placa corretamente a placa\n";
                    }
                }

                   time_t rawtime;
                        struct tm * horaSaida;

                        time ( &rawtime );
                        horaSaida = localtime ( &rawtime );
                        printf ( "data e hora de saida: %s", asctime (horaSaida) );

                 carroLocalizado = false;
                for (int i = 0; i < TAM; i++)
                {
                    
                    if (placa == vetor[i].placa)
                    {
                        cout << "Carro sendo retirado da garagem\n";
                        vetor[i].horaSaida = hora;

                        // Calcular o valor a ser pago
                        double valorHora = 8.0; 
                        double valorMinuto = valorHora / 60.0;
                        double tempoEstacionado = calcularTempoEstacionado(vetor[i].horaEntrada, vetor[i].horaSaida);
                        valorPago = valorMinuto * tempoEstacionado;

                        cout << "Tempo estacionado: " << tempoEstacionado << " minutos" << endl;
                        cout << "Valor a ser pago: R$ " << valorPago << endl;

                        vetor[i].placa = "";
                        vetor[i].horaEntrada = "";
                        quantidadeCarros--;
                        carroLocalizado = true;
                        break;
                    }
                }
                if (!carroLocalizado)
                {
                  cout<< "Carro sendo retirado da garagem\n";
                }

            }
}