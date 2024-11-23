#include "../include/common.hpp"
#include "../include/grafo.hpp"
#include "../include/ex11.hpp"

#include <iostream>
#include <vector>
#include <cstring>

void ex11(const Grafo &grafo, const char *nomePresa)
{
    // std::cout << "[DEBUG] Iniciando a busca de predadores para a presa: " << nomePresa << std::endl;

    // Obter os vértices do grafo
    const auto &vertices = grafo.getVertices();
    // std::cout << "[DEBUG] Número de vértices no grafo: " << vertices.size() << std::endl;

    // Lista para armazenar os predadores
    std::vector<std::string> predadores;

    // Iterar pelos vértices e buscar arestas que apontam para a presa
    for (const auto &vertice : vertices)
    {
        // std::cout << "[DEBUG] Verificando o vértice: " << vertice.nome << std::endl;
        for (const auto &adj : vertice.lista)
        {
            // std::cout << "[DEBUG] Checando aresta para alimento: " << adj.alimento << std::endl;
            if (strcmp(adj.alimento, nomePresa) == 0)
            {
                // std::cout << "[DEBUG] Predador encontrado: " << vertice.nome << std::endl;
                predadores.push_back(vertice.nome); // Adicionar o predador
            }
        }
    }

    // Exibir os resultados
    if (predadores.empty())
    {
        // std::cout << "[DEBUG] Nenhum predador encontrado para a presa: " << nomePresa << std::endl;
        std::cout << "Registro Inexistente." << std::endl << std::endl;
    }
    else
    {
        // std::cout << "[DEBUG] Predadores encontrados para a presa: " << nomePresa << std::endl;
        // std::cout << "Predadores da presa " << nomePresa << ":\n";
        std::cout << nomePresa << ": ";
        for (auto i = 0; i < predadores.size(); i++)
        {
            std::cout << predadores[i];
            if (i < predadores.size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << std::endl << std::endl;
    }

    // std::cout << "[DEBUG] Finalizando a funcionalidade ex11 para a presa: " << nomePresa << std::endl;
}
