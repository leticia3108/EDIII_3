/*
* Header principal do projeto.
* 
* Aqui se concentra a declaração das funções utilizadas ao longo do projeto,
* bem como as funções fornecidas pelo professor e pelos monitores da disciplina
* 
*/


#ifndef HEADER_H
#define HEADER_H

// Bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "../include/funcoes_fornecidas.h"

// Tamanho fixo de cada página de disco de 1600 bytes
#define TAM_DISCO 1600
#define T_MAX 30
#define TAM_STRING_ENTRADA 10


// Funções de uso comum
int leitura_variavel(char *, FILE*);
char* le_elemento(FILE*);
void criar_cabecalho(FILE*, CABECALHO);
void escreve_dados(FILE*, FILE*);
void le_dados(FILE*, FILE*);
void escreve_dados(FILE* , FILE*);
int leitura_variavel(char str[50] , FILE*);
void imprime_dado(FILE*, DADO*);

// Funções respectivas de cada funcionalidade do projeto
void ex1();
void ex2();
void ex3();
void ex4();
void ex5();
void ex6();

#endif