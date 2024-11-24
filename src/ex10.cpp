#include "../include/common.hpp"
#include "../include/ex10.hpp"

void ex10(FILE* binario){
    Grafo g(binario);
    g.CriaGrafo();
    g.ImprimeGrafo();
}
