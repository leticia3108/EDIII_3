/*
    *************************************************
    * Trabalho Prático 03 de Estrutura de Dados III *
    *************************************************

 Alunos:
    Paulo Nunes de Azevedo    - Nº USP: 13839010
    Leticia Crepaldi da Cunha - Nº USP: 11800879


 ********* Desenvolvimento de cada integrante no projeto: *********

 -------------------------------------------------------------------------
 Leticia: Realizou as implementações das funcionalidades 10, 12 e 14


 Porcentagem de participação da sua parte: 100%
 -------------------------------------------------------------------------

 -------------------------------------------------------------------------
 Paulo: Realizou as implementações das funcionalidades 11 e 13

 Porcentagem de participação da sua parte: 80%
 -------------------------------------------------------------------------

*/

#include <iostream>
#include <stddef.h>
#include <string.h>
#include <vector>
#include <string>

#include "../include/funcoes_fornecidas.hpp"
#include "../include/common.hpp"
// #include "../include/grafo.hpp"
#include "../include/ex10.hpp"
#include "../include/ex11.hpp"
#include "../include/ex12.hpp"
#include "../include/ex13.hpp"
#include "../include/ex14.hpp"

int main()
{
    int opcao = 0;
    char nome_entrada[T_MAX];

    // Leitura da entrada inicial do usuário
    scanf("%d", &opcao);
    scanf("%s", nome_entrada);

    // Abertura do binário de entrada para leitura
    FILE *binario_entrada = fopen(nome_entrada, "rb");
    if (binario_entrada == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada\n");
        return 1;
    }

    // Criar o grafo uma única vez para reutilizar nas consultas
    Grafo grafo(binario_entrada);
    grafo.CriaGrafo();

    switch (opcao)
    {
    case 10:
        // ex10(binario_entrada);
        // fclose(binario_entrada);
        grafo.ImprimeGrafo();
        break;

    case 11:
        int numPresas;
        scanf("%d", &numPresas);
        for (int i = 0; i < numPresas; i++)
        {
            char *nomePresa = (char *)malloc(T_MAX);
            scan_quote_string(nomePresa);
            ex11(grafo, nomePresa);
            free(nomePresa);
        }
        fclose(binario_entrada);
        break;

    case 12:
        grafo.CiclosSimples();
        break;

    case 13:
        ex13(grafo);
        fclose(binario_entrada);
        break;

    case 14:
        ex14(grafo);
        fclose(binario_entrada);
        break;

    default:
        std::cout << "\n***************"
                  << "\nOpcao invalida!"
                  << "\n***************" << std::endl;
        fclose(binario_entrada);
        break;
    }

    return 0;
}
