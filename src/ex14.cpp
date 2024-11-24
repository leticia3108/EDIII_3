#include "../include/funcoes_fornecidas.hpp"
#include "../include/common.hpp"
#include "../include/grafo.hpp"
#include "../include/ex14.hpp"
#include <iostream>


void ex14 (FILE* binario){
    Grafo g(binario);
    g.CriaGrafo();
    int numPredadores;
    cin >> numPredadores;

    char** predadores = (char**) malloc (numPredadores*sizeof(char*));

    char** presas = (char**) malloc (numPredadores*sizeof(char*));

    for (int i = 0; i < numPredadores; i++){
        predadores[i] = (char*) malloc (T_MAX*sizeof(char));
        scan_quote_string(predadores[i]);
        presas[i] = (char*) malloc (T_MAX*sizeof(char));
        scan_quote_string(presas[i]);
        //printf("(%s)", predadores[i]);
    }

    for (int i = 0; i < numPredadores; i++){
        if (g.BuscaPredadorPresa(predadores[i], presas[i]) != -1)
            cout << predadores[i] << " " << presas[i] << ": " << g.BuscaPredadorPresa(predadores[i], presas[i]) << endl;
        else
            cout << predadores[i] << " " << presas[i] << ": " <<"CAMINHO INEXISTENTE" << endl;
    }

    for (int i = 0; i < numPredadores; i++){
        free (presas[i]);
        free (predadores[i]);
    }

    free (presas);
    free (predadores);
    
}