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
#include <cstddef>
#include <cstring>
#include <vector>
#include <string>

int main()
{

    //   int* proxRRN = malloc(sizeof(int));
    //   *proxRRN = 0;

    // Leitura da entrada inicial do usuário
    int opcao = 0;
    char nome_entrada[T_MAX];

    scanf("%d", &opcao);
    scanf("%s", nome_entrada);

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

    case 11:
        char nomePresa[T_MAX];

        // Lê nome da presa
        scanf("%s", nomePresa);

        ex11(binario_entrada, nomePresa);
        break;

    default:
        std::cout << "\n***************"
                  << "\nOpcao invalida!"
                  << "\n***************" << std::endl;
        break;
    }

    return 0;
}