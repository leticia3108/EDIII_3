/*
*************************************************
* Trabalho Prático 03 de Estrutura de Dados III *
*************************************************

 Alunos:
    Paulo Nunes de Azevedo    - Nº USP: 13839010
    Leticia Crepaldi da Cunha - Nº USP: 11800879
 
 
 ********* Desenvolvimento de cada integrante no projeto: *********
 
 -------------------------------------------------------------------------
 Leticia:
    Implementou as funcionalidades 7 e 9, além de refazer o Makefile, 
    tornando-o mais e limpo e melhor para futuras manutenções no projeto.
    
 Porcentagem de participação da sua parte: 
 -------------------------------------------------------------------------
 
 -------------------------------------------------------------------------
 Paulo:
    Implementou a funcionalidade 8 e fez adaptações da modularização do 
    trabalho para o trabalho 2, que facilitam futuras manutenções no
    projeto.

 Porcentagem de participação da sua parte: 
 -------------------------------------------------------------------------
 
*/

#include <stddef.h>
#include <cstring>

#include "../include/common.hpp"
#include "../include/ex10.hpp"
#include "../include/ex11.hpp"
#include "../include/ex12.hpp"
#include "../include/ex14.hpp"


int main() {

 //   int* proxRRN = malloc(sizeof(int));
 //   *proxRRN = 0; 

    // Leitura da entrada inicial do usuário
    int opcao = 0;
    scanf("%d", &opcao);
    getc(stdin);


    // Ler o nome do arquivo de entrada, com tamanho máximo 30:
    char nome_entrada[T_MAX];
    /*fgets(nome_entrada, T_MAX, stdin);
    nome_entrada[strlen(nome_entrada) - 1] = '\0'; */
    scanf("%s", nome_entrada);

    //printf("Nome (%s)\n", nome_entrada);

    // Abertura do binário de entrada para leitura
    FILE *binario_entrada = fopen(nome_entrada,"rb");
    if (binario_entrada == NULL){
        printf("Falha no processamento do arquivo.");
    }

    switch (opcao) {

/*      case 7:
            ex7(proxRRN);
            break;

        case 8:
            ex8();
            break;

        case 9:
            ex9(proxRRN);
            break;
*/
        case 10:
            ex10(binario_entrada);
            break;

        case 11:
            ex11(binario_entrada);
            break;
    
        case 12:
            ex12(binario_entrada);
            break;

        case 14:
            ex14(binario_entrada);
            break;

        default:
            printf("\n**********\nOpcao invalida!\n**********\n");
            break;
    }

    fclose(binario_entrada);
    return 0;
}