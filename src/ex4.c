/*
* O código abaixo realiza a remoção lógica de determinados dados do arquivo
* binário escolhido pelo usuário, seguindo os critérios estabelecidos pela
* funcionalidade 3, o qual o código está no arquivo './src/ex3.c'.
* 
* Ao remover o arquivo, os bytes que antes estavam ocupados com a sua
* informação, agora estão preenchidos com o caractere '$', incicando
* lixo de memória.
* 
* Aqui será feita a etapa principal, solicitando funções criadas no
* módulo 'common.c'
*/


#include "header.h"

void ex4 (){
    // Leitura das entradas do usuário
    char entradas[60];
    fgets(entradas, sizeof(entradas), stdin);
    char* nome_binario = strtok(entradas, " ");
    char* valor_n = strtok(NULL, "\n");

    // Converte valor de n que está em uma string para int
    int n = strtol(valor_n, &valor_n, 10);

    DADO dado;
    CABECALHO cabecalho;




}