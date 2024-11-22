/*
    Header de uso comum para as funções do projeto
*/

#include <string>

#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <list>
#include <vector>

using namespace std;

// Definições
#define T_REG_DADOS 160
#define TAM_DISCO 1600
#define TAM_DADOS_FIXOS 18
#define T_MAX 50

typedef struct {
    int populacao;
    char alimento[T_MAX];
} noListaAdj;

typedef struct {
    char nome[T_MAX];
    string especie;
    string habitat;
    string tipo;
    string dieta;
    list <noListaAdj> lista;
    int grauSaida;
    int grauEntrada;
} SVertice;

bool ComparadorVertice (SVertice s1, SVertice s2);
bool ComparadorLista (noListaAdj s1, noListaAdj s2);
bool ComparadorIgualdade (SVertice s1, SVertice s2);

class Grafo {

private:
    vector<SVertice> _v;
    FILE* _binario;

public:
    Grafo(FILE* binario): _binario(binario){}
    SVertice CriaVertice(int RRN);
    void CriaGrafo();
    void JuntaElementos();
    void AtualizaDegrauEntrada();
    void ImprimeGrafo();
    void BuscaPredadores();
};

void scan_quote_string(char *str);

#endif