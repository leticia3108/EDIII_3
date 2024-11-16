/*
* O código abaixo tem como objetivo a leitura de um arquivo .csv
* e produzir um arquivo binário segundo as especificações do
* trabalho como saída.
*
* Aqui será feita a etapa principal, solicitando funções criadas no
* módulo 'common.c'
*/

#include "header.h"

void ex1(){
    // Lê entrada do usuário como uma string e a separa em duas,
    // sendo cada uma o nome de um dos arquivos (respectivamente
    // de entrada e saída)
    char nomes[60];
    fgets(nomes, sizeof(nomes), stdin);
    char* nome_entrada = strtok(nomes, " ");
    char* nome_saida = strtok(NULL, "\n");

    //Abertura do arquivo de entrada para leitura
    FILE *arquivo_entrada = fopen(nome_entrada,"r");
    if (arquivo_entrada == NULL){
        printf("Erro ao abrir o arquivo de entrada");
    }
    //Abertura do arquivo de saída para gravação
    FILE *arquivo_saida = fopen(nome_saida,"wb");
    if (arquivo_saida == NULL){
        printf("Erro ao abrir o arquivo de saida");
    }

    escreve_dados(arquivo_entrada, arquivo_saida);
    fclose(arquivo_saida);
    binarioNaTela(nome_saida);
    fclose(arquivo_entrada);
}