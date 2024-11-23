#include "../include/common.h"
#include "../include/ex12.h"

void ex12(FILE* binario){
    Grafo g(binario);
    g.CriaGrafo();
    g.CiclosSimples();
}