#include "../include/common.h"
#include "../include/ex11.h"
#include <iostream>

void ex11(FILE* binario){
    Grafo g(binario);
    g.CriaGrafo();
    g.BuscaPredadores();
    
}