#include "../include/common.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

int leitura_variavel(char *str, FILE *binario_entrada)
{

    char c;
    fread(&c, sizeof(char), 1, binario_entrada);

    if (feof(binario_entrada))
    {
        return -1;
    }

    int i = 0;
    while (c != '#')
    {
        str[i] = c;
        if (feof(binario_entrada))
        {
            return -1;
        }
        fread(&c, sizeof(char), 1, binario_entrada);
        i++;
    }
    str[i] = '\0';
    i++;

    return i;
}

