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


 Porcentagem de participação da sua parte:
 -------------------------------------------------------------------------

 -------------------------------------------------------------------------
 Paulo:


 Porcentagem de participação da sua parte:
 -------------------------------------------------------------------------

*/


#include "../include/funcoes_fornecidas.hpp"
#include "../include/common.hpp"
#include "../include/grafo.hpp"
#include "../include/ex10.hpp"
#include "../include/ex11.hpp"
#include "../include/ex12.hpp"
#include "../include/ex13.hpp"
#include "../include/ex14.hpp"

#include <iostream>
#include <stddef.h>
#include <cstring>
#include <vector>
#include <string>

int main()
{

    //   int* proxRRN = malloc(sizeof(int));
    //   *proxRRN = 0;

    // Leitura da entrada inicial do usuário
    int opcao = 0;
    scanf("%d", &opcao);
    getc(stdin);

    // Ler o nome do arquivo de entrada, com tamanho máximo 30:
    char nome_entrada[T_MAX];
    fgets(nome_entrada, T_MAX, stdin);
    nome_entrada[strlen(nome_entrada) - 1] = '\0';

    // Abertura do binário de entrada para leitura
    FILE *binario_entrada = fopen(nome_entrada, "rb");
    if (binario_entrada == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada");
    }

    switch (opcao)
    {

        // case 7:
        //     ex7(proxRRN);
        //     break;

        // case 8:
        //     ex8();
        //     break;

        // case 9:
        //     ex9(proxRRN);
        //     break;

    case 10:
        ex10(binario_entrada);
        fclose(binario_entrada);
        break;
case 11: {
    char nomeArquivo[T_MAX], nomePresa[T_MAX];

    // Nome do arquivo binário
    std::cout << "Digite o nome do arquivo binário: ";
    std::cin.getline(nomeArquivo, T_MAX);

    // Nome da presa
    std::cout << "Digite o nome da presa: ";
    std::cin.getline(nomePresa, T_MAX);
    
    ex11(nomeArquivo, nomePresa);
    break;
}    default:
        std::cout << "\n***************"
                  << "\nOpcao invalida!"
                  << "\n***************" << std::endl;
        break;
    }

    return 0;
}