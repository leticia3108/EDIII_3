// #ifndef GRAFO_HPP
// #define GRAFO_HPP

// #include <vector>
// #include <list>
// #include <string>
// #include <cstdio>
// #include "common.hpp"

// // Funções auxiliares para ordenação e comparação
// bool ComparadorVertice(const SVertice &s1, const SVertice &s2);
// bool ComparadorLista(const noListaAdj &s1, const noListaAdj &s2);
// bool ComparadorIgualdade(const SVertice &s1, const SVertice &s2);


// class Grafo
// {
// private:
//     std::vector<SVertice> _v; // Lista de vértices
//     FILE *_binario;           // Ponteiro para o arquivo binário

// public:
//     // Construtor
//     Grafo(FILE *binario);

//     // Funções principais
//     SVertice CriaVertice(int RRN); // Cria um vértice a partir de um registro
//     void CriaVerticeAlimento(char *);
//     void CriaGrafo();             // Gera o grafo a partir do binário
//     void JuntaElementos();        // Junta vértices com nomes iguais
//     void AtualizaDegrauEntrada(); // Atualiza o grau de entrada de cada vértice
//     void ImprimeGrafo();          // Imprime os dados do grafo

//     // Getter para os vértices
//     const std::vector<SVertice> &getVertices() const;
// };


// #endif // GRAFO_HPP
