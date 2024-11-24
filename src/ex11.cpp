#include "../include/common.hpp"
#include "../include/ex11.hpp"
#include <iostream>

void ex11(FILE* binario){
    Grafo g(binario);
    g.CriaGrafo();
    g.BuscaPredadores();
    
}