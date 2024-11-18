#include "../include/common.h"
#include <iostream>
#include "../include/ex10.h"

class Grafo {

private:
    vector<SVertice> _v;
    FILE* _binario;

public:
    Grafo(FILE* binario): _binario(binario){}
    SVertice CriaVertice(int RRN);
};

SVertice Grafo::CriaVertice(int RRN){
/* Esta função cria um novo vértice a partir de um único
registro do binário de entrada, conectando apenas o ali-
mento do registro especificado por RRN (começando em 0)*/

    SVertice vertice;
    char* temp = (char*) malloc(50 * sizeof(char));
    noListaAdj listaAdj;

    fseek(_binario, TAM_DISCO + 5 +RRN*T_REG_DADOS, SEEK_SET); 
    fread(&(listaAdj.populacao), 1, sizeof(int), _binario);

    fseek(_binario, TAM_DISCO + TAM_DADOS_FIXOS +RRN*T_REG_DADOS, SEEK_SET);  

    leitura_variavel(temp, _binario);
    vertice.nome = temp;
    cout << vertice.nome << endl;

    leitura_variavel(temp, _binario);
    vertice.especie = temp;
    cout << vertice.especie << endl;

    leitura_variavel(temp, _binario);
    vertice.habitat = temp;
    cout << vertice.habitat << endl;

    leitura_variavel(temp, _binario);
    vertice.tipo = temp;
    cout << vertice.tipo << endl;

    leitura_variavel(temp, _binario);
    vertice.dieta = temp;
    cout << vertice.dieta << endl;

    leitura_variavel(temp, _binario);
    listaAdj.alimento = temp;

    vertice.lista.push_front(listaAdj);
    _v[0] = vertice;

    free(temp);
    return vertice;
}

void ex10(FILE* binario){
    Grafo g(binario);
    g.CriaVertice(0);
    
}
