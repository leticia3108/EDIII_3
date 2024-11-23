#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

#include "../include/common.hpp"
#include "../include/grafo.hpp"
#include "../include/ex13.hpp"
#include "../include/funcoes_fornecidas.hpp"



// Função auxiliar para realizar DFS e armazenar a ordem de término
void dfs(const std::vector<SVertice> &vertices, int v, std::vector<bool> &visitados, std::stack<int> &ordem)
{
    visitados[v] = true;
    for (const auto &adj : vertices[v].lista)
    {
        // Procurar índice do vértice adjacente
        auto it = std::find_if(vertices.begin(), vertices.end(), [&adj](const SVertice &vertice)
                               { return strcmp(vertice.nome, adj.alimento) == 0; });
        if (it != vertices.end())
        {
            int adjIndex = std::distance(vertices.begin(), it);
            if (!visitados[adjIndex])
            {
                dfs(vertices, adjIndex, visitados, ordem);
            }
        }
    }
    ordem.push(v); // Adicionar à pilha na ordem de término
}

// Função auxiliar para transpor o grafo
std::vector<SVertice> transporGrafo(const std::vector<SVertice> &vertices)
{
    std::vector<SVertice> transposto = vertices;

    // Limpar listas de adjacências
    for (auto &vertice : transposto)
    {
        vertice.lista.clear();
    }

    // Adicionar arestas invertidas
    for (const auto &vertice : vertices)
    {
        for (const auto &adj : vertice.lista)
        {
            // Encontrar vértice destino
            auto it = std::find_if(transposto.begin(), transposto.end(), [&adj](const SVertice &v)
                                   { return strcmp(v.nome, adj.alimento) == 0; });
            if (it != transposto.end())
            {
                noListaAdj novoAdj;
                strcpy(novoAdj.alimento, vertice.nome);
                novoAdj.populacao = adj.populacao;
                it->lista.push_back(novoAdj);
            }
        }
    }

    return transposto;
}

// Função auxiliar para realizar DFS no grafo transposto e contar componentes
void dfsComponente(const std::vector<SVertice> &vertices, int v, std::vector<bool> &visitados)
{
    visitados[v] = true;
    for (const auto &adj : vertices[v].lista)
    {
        auto it = std::find_if(vertices.begin(), vertices.end(), [&adj](const SVertice &vertice)
                               { return strcmp(vertice.nome, adj.alimento) == 0; });
        if (it != vertices.end())
        {
            int adjIndex = std::distance(vertices.begin(), it);
            if (!visitados[adjIndex])
            {
                dfsComponente(vertices, adjIndex, visitados);
            }
        }
    }
}

// Função principal da funcionalidade 13
void ex13(const Grafo &grafo)
{
    const auto &vertices = grafo.getVertices();
    int n = vertices.size();

    // Passo 1: Realizar DFS no grafo original
    std::vector<bool> visitados(n, false);
    std::stack<int> ordem;
    for (int i = 0; i < n; i++)
    {
        if (!visitados[i])
        {
            dfs(vertices, i, visitados, ordem);
        }
    }

    // Passo 2: Transpor o grafo
    auto transposto = transporGrafo(vertices);

    // Passo 3: Realizar DFS no grafo transposto
    std::fill(visitados.begin(), visitados.end(), false);
    int componentesFortementeConexos = 0;

    while (!ordem.empty())
    {
        int v = ordem.top();
        ordem.pop();
        if (!visitados[v])
        {
            dfsComponente(transposto, v, visitados);
            componentesFortementeConexos++;
        }
    }

    // Verificar se o grafo é fortemente conexo
    if (componentesFortementeConexos == 1)
    {
        std::cout << "O grafo é fortemente conexo." << std::endl;
    }
    else
    {
        std::cout << "O grafo não é fortemente conexo." << std::endl;
    }

    // Exibir o número de componentes fortemente conexos
    std::cout << "Número de componentes fortemente conexos: " << componentesFortementeConexos << std::endl;
}
