/*
    Header de uso comum para as funções do projeto
*/


#ifndef COMMON_HPP
#define COMMON_HPP

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

typedef struct
{
    int populacao;
    char alimento[T_MAX];
} noListaAdj;

typedef struct
{
    char nome[T_MAX];
    string especie;
    string habitat;
    string tipo;
    string dieta;
    list<noListaAdj> lista;
    int grauSaida;
    int grauEntrada;
} SVertice;

class Grafo;

// Funções
int leitura_variavel(char *str, FILE *binario_entrada)


#endif