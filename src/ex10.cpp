#include "../include/common.hpp"
#include "../include/grafo.hpp"
#include "../include/ex10.hpp"
#include <iostream>
#include <algorithm>
#include <string.h>




void ex10(FILE *binario)
{
    Grafo g(binario);
    g.CriaGrafo();
    g.ImprimeGrafo();
}
