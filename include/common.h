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
    string alimento;
} noListaAdj;

typedef struct {
    char nome[T_MAX];
    string especie;
    string habitat;
    string tipo;
    string dieta;
    list <noListaAdj> lista;
} SVertice;


#endif