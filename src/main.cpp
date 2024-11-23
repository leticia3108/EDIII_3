
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

    default:
        std::cout << "\n***************"
                  << "\nOpcao invalida!"
                  << "\n***************" << std::endl;
        break;
    }

    return 0;
}
