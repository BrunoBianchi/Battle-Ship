#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Definindo o Tamanho Total do Tabuleiro
#define TAM 10 
// Definindo Quantos  Navios Tem
#define NAV 10

// Funcao Para Listar o tabuleiro
void listarTabela(char tabuleiro[10][10]) {
        for(int i = 0;i<TAM;i++) {
        for(int j = 0; j < TAM; j++) {
            // Caso i-j for igual a O ele print Verde
            if(tabuleiro[i][j] == 'O') {
                printf("\033[0;32m%c\033[0m \t",tabuleiro[i][j]);
                // Caso i-j for igual a X ele print Vermelho
            }else if(tabuleiro[i][j] == 'X') {
                printf("\033[0;31m%c\033[0m \t",tabuleiro[i][j]);
            }else {
                // Se i-j nao for igual a x ou o ele print normal
                printf("\033[0;34m%c\033[0m \t",tabuleiro[i][j]);
            }
            
        }
        puts("\n");
        }
        
}

int main() {
    // Criando Tabuleiro 10 x 10
    char tabuleiro[10][10];
    // Criando tabuleiro de 10x10 de resposta do user
    char resposta[10][10];
    int tentativas = 0,erros = 0,acertos=0;
    // Colocando * em todas as casas
    for(int i = 0;i<TAM;i++) {
        for(int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '*';
            resposta[i][j] = '*';
        }
    }
    // Definindo os navios Aleatoriamente
    for(int i =0;i<NAV;i++) {
        srand((unsigned) i * time(NULL));
        // Valor aleatorio de 0 - 9 para linha
        int linha = rand() % 10;
        // Valor aleatorio de 0 - 9 para coluna
        int coluna = rand() % 10;
        // Resposta de um navio 
        tabuleiro[linha][coluna] = 'O';
    }
        // Enquanto Tentativas nao exceder 30
        while(tentativas <30) {
            int linha = 0, coluna = 0;
            listarTabela(resposta);
            printf("Escolha uma linha: ");
            scanf("%d",&linha);
            printf("Escolha uma Coluna: ");
            scanf("%d",&coluna);     
            // Verificando se o valor atribuido a linha nao e' maior que 10 e nem menor que 0, caso seja sera gerado um alor aleatorio
            linha = linha<10 && linha>=0?linha:rand() % 10; 
             // Verificando se o valor atribuido a coluna nao e' maior que 10 e nem menor que 0, caso seja sera gerado um alor aleatorio
            coluna = coluna<10 && coluna>=0?coluna:rand() % 10; 
            if(tabuleiro[linha][coluna] == 'O') {
                resposta[linha][coluna] = 'O';
                acertos++;
            }else {
                resposta[linha][coluna] = 'X';
                erros++;
            }
            if(acertos >= NAV) {
                system("cls");
                printf("\nVitoria,Todos navios foram borbardeados!\nTentativas:%d\nErros:%d\nAcertos:%d\n\n",tentativas,erros,acertos);
                listarTabela(tabuleiro);
                return 0;
            }
            tentativas ++ ;
        }
         system("cls");
         printf("\nDerrota,Voce nao conseguiu bombardear todos os navios!\nTentativas:%d\nErros:%d\nAcertos:%d\n\n",tentativas,erros,acertos);
         listarTabela(tabuleiro);
    return 0;
}