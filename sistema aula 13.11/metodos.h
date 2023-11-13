string converterMaiusculas(string texto) {
    string textoMaiusculo;
    for (char c : texto) {
        textoMaiusculo += toupper(c);
    }
    return textoMaiusculo;
}

void Cadastrar(Laboratorios* &vetor, int &totaldeSalas, int &salas) {
    cout << "CADASTRAR SALAS OU LABORATORIO" << endl;

    cout << "Numeo da sala: ";
    cin >> vetor[totaldeSalas].Nsala;
    cout << "Tipo (sala ou laboratorio): ";
    cin >> vetor[totaldeSalas].tipo;
    vetor[totaldeSalas].tipo = converterMaiusculas(vetor[totaldeSalas].tipo);
    totaldeSalas++;
   
}

void CadastrarPessoas(PAutorizada* &vetor, int &totaldePessoas, string &nome) {
    cout << "CADASTRAR PESSOAS AUTORIZADAS" << endl;

    cout << "Nome: ";
    cin >> vetor[totaldePessoas].nome;
    vetor[totaldePessoas].nome = converterMaiusculas(vetor[totaldePessoas].nome);
    cout << "Tipo (Aluno, Professor ou Funcionario): ";
    cin >> vetor[totaldePessoas].tipo;
    vetor[totaldePessoas].tipo = converterMaiusculas(vetor[totaldePessoas].tipo);
    cout << "Telefone de contato:"
    cin >> vetor[totaldePessoas].fone;
    totaldePessoas++;
   
}

void AutorizacaoSala (Laboratorios*, PAutorizada* &vetor, int &totaldeSalas, int &totaldePessoas, int &salas, string &nome){
    if (totaldeSalas == 0){
        cout << "Nao existem salas ou laboratorios cadastrados!" << endl;
        return;
    }else(totaldePessoas == 0){
        cout << "Nao existem pessoas cadastradas!" << endl;
        return;
    }

    cout << "AUTORIZACAO DE USO DE SALAS" << endl;

    string nome;
    int sala;

    cout << "informe o nome da pessoa que deseja autorizar:";
    cin >> nome;
    nome = converterMaiusculas(nome);

    for (int i = 0; i < totaldePessoas; i++){
        
    }
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

void SalvarSalas(const Laboratorios* vetor, int totaldeSalas) {
    ofstream arquivoSalas("salas.csv");

    if (arquivoSalas.is_open()) {
        for (int i = 0; i < totaldeSalas; i++) {
            arquivoSalas << vetor[i].Nsalas << "," << vetor[i].tipo << "," << "\n";
        }
        arquivoSalas.close();
        cout << "Sala Salva com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo sala.csv." << endl;
    }
}

void SalvarPessoas(const PAutorizada* vetor, int totaldeSalas) {
    ofstream arquivoPessoas("pessoas.csv");

    if (arquivoPessoas.is_open()) {
        for (int i = 0; i < totaldePessoas; i++) {
            arquivoPessoas << vetor[i].nomes << "," << vetor[i].tipo << "," << vetor[i].fone << "\n";
        }
        arquivoPessoas.close();
        cout << "Pessoa Salva com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo pessoas.csv." << endl;
    }
}

void CarregarSalas(Laboratorios* &vetor, int &totaldeSalas, int &sala) {
    ifstream arquivoSala("sala.csv");

    if (arquivoSala.is_open()) {
        totaldeSala = 0;
        string linha;

        while (getline(arquivoSala, linha)) {
            size_t pos = linha.find(",");
            if (pos != string::npos) {
                if (totaldeSala >= salas) {
                    salas += 1;
                    Laboratorios* novoVetor = new Laboratorios[salas];
                    for (int i = 0; i < totaldeSalas; i++) {
                        novoVetor[i] = vetor[i];
                    }
                    delete[] vetor;
                    vetor = novoVetor; 
                }
                vetor[totaldeSalas].nome = linha.substr(0, pos);
                linha = linha.substr(pos + 1);
                pos = linha.find(",");
                if (pos != string::npos) {
                    vetor[totaldeSalas].Nsala = linha.substr(0, pos);
                    vetor[totaldeSalas].tipo = stod(linha.substr(pos + 1));
                    totaldeSalas++;
                }
            }
        }
        arquivoCripto.arquivoSala();
    } else {
        cout << "Erro ao abrir o arquivo salas.csv. Criando uma base de dados vazia." << endl;
    }
totaldeSala