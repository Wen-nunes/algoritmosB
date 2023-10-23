string converterMaiusculas(string texto) {
    string textoMaiusculo;
    for (char c : texto) {
        textoMaiusculo += toupper(c);
    }
    return textoMaiusculo;
}

void Cadastrar(Criptomoeda* &vetor, int &totalCriptomoedas, int &capacidade) {
    cout << "CADASTRAR CRIPTOMOEDA" << endl;

    cout << "Nome: ";
    cin >> vetor[totalCriptomoedas].nome;
    cout << "Sigla: ";
    cin >> vetor[totalCriptomoedas].sigla;
    vetor[totalCriptomoedas].sigla = converterMaiusculas(vetor[totalCriptomoedas].sigla);

    cout << "Valor em dolar: ";
    cin >> vetor[totalCriptomoedas].VDollar;
    cout << "Criptomoeda cadastrada com sucesso." << endl;
    totalCriptomoedas++;
   
}

void atualizar(Criptomoeda* vetor, int totalCriptomoedas) {
    if (totalCriptomoedas == 0) {
        cout << "A base de dados esta vazia. Nao e possivel atualizar criptomoedas." << endl;
        return;
    }

    cout << "ATUALIZAR VALOR DA CRIPTOMOEDA" << endl;

    string sigla;
    cout << "Informe a sigla da criptomoeda a ser atualizada: ";
    cin >> sigla;
    sigla = converterMaiusculas(sigla);

    for (int i = 0; i < totalCriptomoedas; i++) {
        if (vetor[i].sigla == sigla) {
            cout << "Novo valor em dolar: ";
            cin >> vetor[i].VDollar;
            cout << "Valor atualizado com sucesso." << endl;
            return;
        }
    }
    cout << "Criptomoeda nao encontrada." << endl;
}

void remover(Criptomoeda* vetor, int &totalCriptomoedas) {
    if (totalCriptomoedas == 0) {
        cout << "A base de dados esta vazia. Nao e possível remover criptomoedas." << endl;
        return;
    }

    cout << "REMOVER CRIPTOMOEDA" << endl;

    string sigla;
    cout << "Informe a sigla da criptomoeda a ser removida: ";
    cin >> sigla;
    sigla = converterMaiusculas(sigla);

    for (int i = 0; i < totalCriptomoedas; i++) {
        if (vetor[i].sigla == sigla) {
            for (int j = i; j < totalCriptomoedas - 1; j++) {
                vetor[j] = vetor[j + 1];
            }
            totalCriptomoedas--;
            cout << "Criptomoeda removida com sucesso." << endl;
            return;
        }
    }

    cout << "Criptomoeda nao encontrada." << endl;
}

void listar(Criptomoeda* vetor, int totalCriptomoedas) {
    if (totalCriptomoedas == 0) {
        cout << "A base de dados esta vazia." << endl;
        return;
    }

    cout << "LISTA DE CRIPTOMOEDAS" << endl;
    for (int i = 0; i < totalCriptomoedas; i++) {
        cout << "Nome: " << vetor[i].nome << ", Sigla: " << vetor[i].sigla << ", Valor em dólar: " << vetor[i].VDollar << endl;
    }
}

void salvarCriptomoedas(const Criptomoeda* vetor, int totalCriptomoedas) {
    ofstream arquivoCripto("cripto.csv");

    if (arquivoCripto.is_open()) {
        for (int i = 0; i < totalCriptomoedas; i++) {
            arquivoCripto << vetor[i].nome << "," << vetor[i].sigla << "," << vetor[i].VDollar << "\n";
        }
        arquivoCripto.close();
        cout << "Criptomoedas salvas com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo cripto.csv." << endl;
    }
}

void carregarCriptomoedas(Criptomoeda* &vetor, int &totalCriptomoedas, int &capacidade) {
    ifstream arquivoCripto("cripto.csv");

    if (arquivoCripto.is_open()) {
        totalCriptomoedas = 0;
        string linha;

        while (getline(arquivoCripto, linha)) {
            size_t pos = linha.find(",");
            if (pos != string::npos) {
                if (totalCriptomoedas >= capacidade) {
                    capacidade += 1;
                    Criptomoeda* novoVetor = new Criptomoeda[capacidade];
                    for (int i = 0; i < totalCriptomoedas; i++) {
                        novoVetor[i] = vetor[i];
                    }
                    delete[] vetor;
                    vetor = novoVetor; 
                }
                vetor[totalCriptomoedas].nome = linha.substr(0, pos);
                linha = linha.substr(pos + 1);
                pos = linha.find(",");
                if (pos != string::npos) {
                    vetor[totalCriptomoedas].sigla = linha.substr(0, pos);
                    vetor[totalCriptomoedas].VDollar = stod(linha.substr(pos + 1));
                    totalCriptomoedas++;
                }
            }
        }
        arquivoCripto.close();
    } else {
        cout << "Erro ao abrir o arquivo cripto.csv. Criando uma base de dados vazia." << endl;
    }
}