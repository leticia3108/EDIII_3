#include "../include/funcoes_fornecidas.hpp"
#include "../include/common.hpp"
#include "../include/grafo.hpp"
#include "../include/ex12.hpp"
#include <iostream>


void ex12(FILE* binario){
    Grafo g(binario);
    g.CriaGrafo();
    g.CiclosSimples();
}