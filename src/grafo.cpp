#include "../include/grafo.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>

// Comparador para ordenar vértices por nome
bool ComparadorVertice(const SVertice &s1, const SVertice &s2) {
    return (strcmp(s1.nome, s2.nome) < 0);
}

// Comparador para ordenar a lista de adjacências por nome do alimento
bool ComparadorLista(const noListaAdj &s1, const noListaAdj &s2) {
    return (strcmp(s1.alimento, s2.alimento) < 0);
}

// Comparador para verificar igualdade entre vértices
bool ComparadorIgualdade(const SVertice &s1, const SVertice &s2) {
    return (strcmp(s1.nome, s2.nome) == 0);
}

// Construtor da classe Grafo
Grafo::Grafo(FILE *binario) : _binario(binario) {}

// Cria um vértice a partir de um registro no binário
SVertice Grafo::CriaVertice(int RRN) {
    SVertice vertice;
    char temp[50];
    noListaAdj listaAdj;

    // Ler a população da aresta
    fseek(_binario, TAM_DISCO + 5 + RRN * T_REG_DADOS, SEEK_SET);
    fread(&listaAdj.populacao, sizeof(int), 1, _binario);

    // Ler os dados variáveis
    fseek(_binario, TAM_DISCO + TAM_DADOS_FIXOS + RRN * T_REG_DADOS, SEEK_SET);
    leitura_variavel(vertice.nome, _binario);
    leitura_variavel(temp, _binario);
    vertice.especie = temp;
    leitura_variavel(temp, _binario);
    vertice.habitat = temp;
    leitura_variavel(temp, _binario);
    vertice.tipo = temp;
    leitura_variavel(temp, _binario);
    vertice.dieta = temp;
    leitura_variavel(listaAdj.alimento, _binario);

    // Adicionar a aresta ao vértice
    vertice.lista.push_front(listaAdj);

    // Adicionar o vértice à lista de vértices do grafo
    _v.push_back(vertice);

    return vertice;
}

// Cria o grafo lendo todos os registros do binário
void Grafo::CriaGrafo() {
    int RRN = 0;

    while (!feof(_binario)) {
        CriaVertice(RRN);
        RRN++;
        fseek(_binario, TAM_DISCO + RRN * T_REG_DADOS, SEEK_SET);
        if (fgetc(_binario) == EOF) break;
    }

    // Ordenar os vértices e juntar elementos com nomes iguais
    std::sort(_v.begin(), _v.end(), ComparadorVertice);
    JuntaElementos();

    // Remover duplicatas
    auto resize = std::unique(_v.begin(), _v.end(), ComparadorIgualdade);
    _v.resize(std::distance(_v.begin(), resize));

    // Atualizar grau de entrada
    AtualizaDegrauEntrada();
}

// Junta vértices com o mesmo nome
void Grafo::JuntaElementos() {
    for (auto i = _v.begin(); i != _v.end(); ++i) {
        for (auto j = i + 1; j != _v.end(); ++j) {
            if (ComparadorIgualdade(*i, *j)) {
                i->lista.insert(i->lista.end(), j->lista.begin(), j->lista.end());
                i->grauSaida += j->grauSaida;
            } else {
                break;
            }
        }
        i->lista.sort(ComparadorLista);
    }
}

// Atualiza o grau de entrada de cada vértice
void Grafo::AtualizaDegrauEntrada() {
    for (auto &i : _v) {
        i.grauEntrada = 0;
        for (const auto &k : _v) {
            for (const auto &j : k.lista) {
                if (strcmp(j.alimento, i.nome) == 0) {
                    i.grauEntrada++;
                }
            }
        }
    }
}

// Imprime o grafo no formato esperado
void Grafo::ImprimeGrafo() const {
    for (const auto &v : _v) {
        for (const auto &no : v.lista) {
            std::cout << v.nome << " " << v.especie << " " << v.habitat << " "
                      << v.dieta << " " << v.tipo << " " << v.grauEntrada << " "
                      << v.grauSaida << " " << (v.grauEntrada + v.grauSaida) << " "
                      << no.alimento << " " << no.populacao << std::endl;
        }
    }
}

// Getter para acessar os vértices
const std::vector<SVertice>& Grafo::getVertices() const {
    return _v;
}
