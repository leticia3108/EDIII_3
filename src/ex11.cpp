#include "../include/common.hpp"
#include "../include/grafo.hpp"
#include "../include/ex11.hpp"

#include <iostream>
#include <vector>
#include <cstring>

// Modificado para aceitar um grafo já criado
void ex11(const Grafo &grafo, const char *nomePresa)
{
    // Obter os vértices do grafo
    const auto &vertices = grafo.getVertices();

    // Lista para armazenar os predadores
    std::vector<std::string> predadores;

    // Iterar pelos vértices e buscar arestas que apontam para a presa
    for (const auto &vertice : vertices)
    {
        for (const auto &adj : vertice.lista)
        {
            if (strcmp(adj.alimento, nomePresa) == 0)
            {
                predadores.push_back(vertice.nome); // Adicionar o predador
            }
        }
    }

    // Exibir os resultados
    if (predadores.empty())
    {
        std::cout << "Nenhum predador encontrado para a presa: " << nomePresa << std::endl;
    }
    else
    {
        std::cout << "Predadores da presa " << nomePresa << ":\n";
        for (const auto &predador : predadores)
        {
            std::cout << predador;
        }
    }
}
