void inicializarVetor(Atendimento vetor[], int n){
    for (int i = 0; i < n; i++){
        vetor[i].resultado = "";
        vetor[i].urgencia = "";

    }
}


int CadastroTriagem(){
    cout << "Cadastro de Triagem.\n";
    
    if(Atendimento == 0){
        cout << "Sistema Lotado!";
    }
    else{
        time_t t = time(NULL);
data_hora_atual = localtime(&t);
    }
        
    }
}