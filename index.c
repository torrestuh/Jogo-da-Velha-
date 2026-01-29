#include <stdio.h>
#include <stdlib.h>

char tabuleiro[3][3];

void inicializarTabuleiro(){
    for(int i = 0; i < 3; i++){
        
        for(int j = 0; j < 3; j++){
            
            tabuleiro[i][j] = ' ';
            
        }
        
    }
    
}

void mostrarTabuleiro(){
    printf("\n");
    printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    
}

char verificarVitoria(){
    //esse for verifica se ganhou na horizontal e vertical, respectivamente
    for(int i = 0; i < 3; i++){
        
        if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' '){
            
            return tabuleiro[i][0];
            
        } else if(tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' '){
            
            return tabuleiro[0][i];
            
        }
        
    }
    
    //esse if else verifica se ganhou na diagonal
    if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' '){
        
        return tabuleiro[0][0];
        
    }else if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' '){
        
        return tabuleiro[0][2];
        
    }
    
    //retorna vazio se nn tiver ganhador
    return ' ';
}

int verificarEmpate(){
    for(int i = 0; i < 3; i ++){
        
        for(int j = 0; j < 3; j++){
            
            if(tabuleiro[i][j] == ' '){
                
                return 0;
                
            }
            
        }
        
    }
    
    return 1;
}

int minimax(int profundidade, int maximizando){
    char vencedor = verificarVitoria();
    
    if(vencedor == 'O'){
        
        return 10 - profundidade;
        
    } else if(vencedor == 'X'){
        
        return profundidade - 10;
        
    } else if(verificarEmpate()){
        
        return 0;
    }
    
    if(maximizando){
        int melhor = -1000;
        
        for(int i = 0; i < 3; i++){
            
            for(int j = 0; j < 3; j++){
                
                if(tabuleiro[i][j] == ' '){
                    
                    tabuleiro[i][j] = 'O';
                    int valor = minimax(profundidade + 1, 0);
                    tabuleiro[i][j] = ' ';
                    
                    if(valor > melhor){
                        melhor = valor;
                    }
                    
                }
            }
        }
        return melhor;
        
    } else {
        int pior = 1000;
        
        for(int i = 0; i < 3; i++){
            
            for(int j = 0; j < 3; j++){
                
                if(tabuleiro[i][j] == ' '){
                    
                    tabuleiro[i][j] = 'X';
                    int valor = minimax(profundidade + 1, 1);
                    tabuleiro[i][j] = ' ';
                    
                    if(valor < pior){
                        pior = valor;
                    }
                    
                }
            }
        }
        return pior;
    }
}

void jogadaMaquina(){
    int melhorValor = -1000;
    int linha = -1;
    int coluna = -1;
    
    for(int i = 0; i < 3; i++){
        
        for(int j = 0; j < 3; j++){
            
            if(tabuleiro[i][j] == ' '){
                
                tabuleiro[i][j] = 'O';
                int valor = minimax(0, 0);
                tabuleiro[i][j] = ' ';
                
                if(valor > melhorValor){
                    melhorValor = valor;
                    linha = i;
                    coluna = j;
                }
                
            }
        }
    }
    
    tabuleiro[linha][coluna] = 'O';
}

void jogadaJogador(char simbolo){
    int linha, coluna;
    
    do{
        printf("Escolha a linha da sua jogada (1-3): ");
        scanf("%d", &linha);
        printf("Escolha a coluna da sua jogada (1-3): ");
        scanf("%d", &coluna);
        linha--;
        coluna--;
        
    } while(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ');
    
    tabuleiro[linha][coluna] = simbolo;
}

void main(){
    int modo, vez;
    inicializarTabuleiro();
    
    printf("--- Jogo da Velha ---\n");
    printf("1 - Singleplayer\n");
    printf("2 - Multiplayer\n");
    printf("Selecione o modo de jogo: ");
    scanf("%d", &modo);
    
    printf("Quem comeca jogando? (1 - 'X' / 2 - 'O'): ");
    scanf("%d", &vez);
    
    while(1){
        mostrarTabuleiro();
        
        if(modo == 1){
            
            if(vez == 1){
                
                jogadaJogador('X');
                
            }else{
                
                jogadaMaquina();
                
            }
            
        }else if(modo == 2){
            
            jogadaJogador(vez == 1 ? 'X' : 'O');
            
        }
        
        char vencedor = verificarVitoria();
        if(vencedor != ' '){
            
            mostrarTabuleiro();
            printf("O jogador: '%c' venceu a partida!\n", vencedor);
            break;
            
        } else if(verificarEmpate()){
            
            mostrarTabuleiro();
            printf("O jogo terminou empatado!");
            break;
            
        }
        
        vez = (vez == 1) ? 2 : 1;
    }
}
