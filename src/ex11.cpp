#include "../include/common.hpp"
#include "../include/grafo.hpp"
#include "../include/ex11.hpp"

#include <iostream>
#include <vector>
#include <cstring>

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
        std::cout << "Registro Inexistente." << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << nomePresa << ": ";
        for (auto i = 0; i < predadores.size(); i++)
        {
            std::cout << predadores[i];
            if (i < predadores.size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << std::endl
                  << std::endl;
    }
}
