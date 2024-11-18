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

typedef struct {
    int populacao;
    string alimento;
} noListaAdj;

typedef struct {
    string nome;
    string especie;
    string habitat;
    string tipo;
    string dieta;
    list <noListaAdj> lista;
} SVertice;

// Definições
#define T_REG_DADOS 160
#define TAM_DISCO 1600
#define TAM_DADOS_FIXOS 18
#define T_MAX 50

#endif