#include "../include/common.h"
#include "../include/ex10.h"

void ex10(FILE* binario){
    Grafo g(binario);
    g.CriaGrafo();
    g.ImprimeGrafo();
}
