
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
    // std::cout << "[DEBUG] Iniciando o programa..." << std::endl;

    int opcao = 0;
    char nome_entrada[T_MAX];

    // Leitura da entrada inicial do usuário
    // std::cout << "[DEBUG] Lendo opção e nome do arquivo..." << std::endl;
    scanf("%d", &opcao);
    scanf("%s", nome_entrada);
    // std::cout << "[DEBUG] Opção escolhida: " << opcao << ", Arquivo: " << nome_entrada << std::endl;

    // Abertura do binário de entrada para leitura
    // std::cout << "[DEBUG] Abrindo o arquivo binário..." << std::endl;
    FILE *binario_entrada = fopen(nome_entrada, "rb");
    if (binario_entrada == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada\n");
        return 1;
    }

    // Criar o grafo uma única vez para reutilizar nas consultas
    // std::cout << "[DEBUG] Criando o grafo a partir do arquivo binário..." << std::endl;
    Grafo grafo(binario_entrada);
    grafo.CriaGrafo();
    fclose(binario_entrada);
    // std::cout << "[DEBUG] Grafo criado com sucesso." << std::endl;

    switch (opcao)
    {
    case 10:
        // std::cout << "[DEBUG] Executando a funcionalidade 10..." << std::endl;
        binario_entrada = fopen(nome_entrada, "rb");
        if (binario_entrada == NULL)
        {
            printf("Erro ao abrir o arquivo de entrada\n");
            return 1;
        }
        ex10(binario_entrada);
        fclose(binario_entrada);
        // std::cout << "[DEBUG] Funcionalidade 10 concluída." << std::endl;
        break;

    case 11:
        // std::cout << "[DEBUG] Executando a funcionalidade 11..." << std::endl;
        int numPresas;
        scanf("%d", &numPresas);
        // std::cout << "[DEBUG] Número de presas: " << numPresas << std::endl;
        for (int i = 0; i < numPresas; i++)
        {
            char *nomePresa = (char *)malloc(T_MAX);
            // char *string_aux = (char *)malloc(T_MAX);

            // std::cout << "[DEBUG] Iteração " << i + 1 << " do loop para processar presas." << std::endl;

            // Ler o nome auxiliar da presa (separar entrada)
            // std::cout << "[DEBUG] Lendo string auxiliar..." << std::endl;
            // scanf("%s", string_aux);
            // std::cout << "[DEBUG] String auxiliar lida: " << string_aux << std::endl;

            // Ler o nome completo da presa
            // std::cout << "[DEBUG] Chamando scan_quote_string para ler o nome completo da presa..." << std::endl;
            scan_quote_string(nomePresa);
            // std::cout << "[DEBUG] Nome da presa lido (após scan_quote_string): " << nomePresa << std::endl;

            // Chamar a funcionalidade ex11 para processar o grafo
            // std::cout << "[DEBUG] Chamando ex11 para processar a presa: " << nomePresa << std::endl;
            ex11(grafo, nomePresa);
            // std::cout << "[DEBUG] ex11 processado com sucesso para a presa: " << nomePresa << std::endl;
            
            free(nomePresa);
            // free(string_aux);
        }
        // std::cout << "[DEBUG] Funcionalidade 11 concluída." << std::endl;
        break;

    default:
        // std::cout << "[DEBUG] Opção inválida." << std::endl;
        std::cout << "\n***************"
                  << "\nOpcao invalida!"
                  << "\n***************" << std::endl;
        break;
    }

    // std::cout << "[DEBUG] Finalizando o programa..." << std::endl;
    return 0;
}
