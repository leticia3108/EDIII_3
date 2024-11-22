#include "../include/common.h"
#include "../include/ex11.h"
#include <iostream>

void ex11(FILE* binario){
    Grafo g(binario);
    g.CriaGrafo();
    int numPresas;
    
    cin >> numPresas;
    //printf("%d", numPresas)
    char** presas = g.BuscaPredadores(numPresas);
    
    for (int i = 0; i < numPresas; i++){
        free(presas[i]);
    };

    free(presas);
}