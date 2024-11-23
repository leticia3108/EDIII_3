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

#include <iostream>
#include <stddef.h>
#include <string.h>
#include <vector>
#include <string>

#include "../include/funcoes_fornecidas.hpp"
#include "../include/common.hpp"
#include "../include/grafo.hpp"
#include "../include/ex10.hpp"
#include "../include/ex11.hpp"
#include "../include/ex13.hpp"

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
        ex10(binario_entrada);
        fclose(binario_entrada);
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

    case 13:
        std::cout << "[DEBUG] Executando a funcionalidade 13..." << std::endl;
        ex13(grafo);
        break;

    default:
        std::cout << "\n***************"
                  << "\nOpcao invalida!"
                  << "\n***************" << std::endl;
        break;
    }

    return 0;
}
