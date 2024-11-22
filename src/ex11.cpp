#include "../include/common.hpp"
#include "../include/grafo.hpp"
#include "../include/ex11.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cstring>

void ex11(const char *nomeArquivo, const char *nomePresa)
{
    // Abrir o arquivo binário
    FILE *binario = fopen(nomeArquivo, "rb");
    if (binario == NULL)
    {
        std::cerr << "Erro ao abrir o arquivo binário." << std::endl;
        return;
    }

    // Gerar o grafo
    Grafo g(binario);
    g.CriaGrafo();
    fclose(binario);

    // Buscar predadores da presa
    const auto &vertices = g.getVertices();
    std::vector<std::string> predadores;

    for (const auto &vertice : vertices)
    {
        for (const auto &adj : vertice.lista)
        {
            if (strcmp(adj.alimento, nomePresa) == 0)
            {
                predadores.push_back(vertice.nome);
            }
        }
    }

    // Exibir os predadores
    if (predadores.empty())
    {
        std::cout << "Nenhum predador encontrado para a presa: " << nomePresa << std::endl;
    }
    else
    {
        std::cout << "Predadores da presa " << nomePresa << ":\n";
        for (const auto &predador : predadores)
        {
            std::cout << predador << std::endl;
        }
    }
}
