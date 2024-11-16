/*
Arquivo com as funções usadas no resto do projeto
*/

#include "header.h"
#define TAM_ELEMENTO 50

/* A seguinte função lê uma string variável do arquivo binário na posição atual
e retorna o desvio do arquivo (considerando o delimitador) */
int leitura_variavel(char* str, FILE* binario_entrada){

    char* c = malloc(sizeof(char));
    fread(&c, sizeof(char), 1, binario_entrada);

    int i = 0;
    while (*c != '#'){
        str[i] = *c;
        fread(&c, sizeof(char), 1, binario_entrada);
    }
        str[i] = '\0';
        i++;
        free(c);
    return i;
}

int sobreescreve_dado (FILE* binario_entrada, DADO dado){

int encadeamento;
char rem = 0;

fwrite(&rem, 1, sizeof(char), binario_entrada);
fread(&encadeamento, sizeof(int), 1, binario_entrada);
fwrite(&dado.populacao, sizeof(int), 1, binario_entrada);
fwrite(&dado.tamanho, sizeof(float), 1, binario_entrada);
fwrite(&dado.unidadeMedida, sizeof(char), 1, binario_entrada);
fwrite(&dado.velocidade, sizeof(int), 1, binario_entrada);
fwrite(&dado.nome, strlen(dado.nome), 1, binario_entrada);
fwrite(&dado.especie, strlen(dado.especie), 1, binario_entrada);
fwrite(&dado.habitat, strlen(dado.habitat), 1, binario_entrada);
fwrite(&dado.tipo, strlen(dado.tipo), 1, binario_entrada);
fwrite(&dado.dieta, strlen(dado.dieta), 1, binario_entrada);
fwrite(&dado.alimento, strlen(dado.alimento), 1, binario_entrada);

return encadeamento;
}

void imprime_dado(FILE* binario_entrada, DADO* dado){

        int dado_removido;

        fread (&(dado->removido), sizeof(char), 1, binario_entrada);
        if (dado->removido == '0'){
            int pular = 0;
            fseek(binario_entrada, 8, SEEK_CUR);


            fread(&(dado->tamanho), sizeof(float), 1, binario_entrada);
            fread(&(dado->unidadeMedida), sizeof(char), 1, binario_entrada);
            fread(&(dado->velocidade), sizeof(int), 1, binario_entrada);
 
            pular += 18;          
            pular += leitura_variavel(dado->nome, binario_entrada);
            pular += leitura_variavel(dado->especie, binario_entrada);
            pular += leitura_variavel(dado->habitat, binario_entrada);
            pular += leitura_variavel(dado->tipo, binario_entrada);
            pular += leitura_variavel(dado->dieta, binario_entrada);
 

        printf("Nome: %s\nEspecie: %s\n", dado->nome, dado->especie);
        
        if (strcmp(dado->tipo, "") != 0)
            printf( "Tipo: %s\n", dado->tipo);

        if (strcmp(dado->dieta, "") != 0)
            printf( "Dieta: %s\n", dado->dieta);

        if (strcmp(dado->habitat, "") != 0)
            printf( "Lugar que habitava: %s\n", dado->habitat);
        
        if (dado->tamanho != -1)
            printf("Tamanho: %.1lf\n", dado->tamanho);
        
        if (dado->velocidade != -1)
            printf("Velocidade: %d %cm/h\n", dado->velocidade, dado->unidadeMedida);
        
        printf("\n");}

}

char* le_elemento(FILE* arquivo_entrada){

    char* elemento = malloc (TAM_ELEMENTO * sizeof(char));
    if (elemento == NULL) {
        printf("Falha na alocacao\n");
    }

    // Caractere lido no arquivo
    char caractere_lido = fgetc(arquivo_entrada);

    // Verifica que não está no final do arquivo
    if (caractere_lido == EOF) {
        // printf("\n\nNao ha nada no arquivo\n\n");
        return NULL;
    }

    // Captura o primeiro dado que não seja espaço ou \0
    while (caractere_lido == ' '|| caractere_lido == '\0'){
        caractere_lido = fgetc(arquivo_entrada);
    }

    int i = 0;
    while(
        caractere_lido != '\n' && 
        caractere_lido != ',' && 
        caractere_lido != EOF && 
        i < TAM_ELEMENTO
        ){

        elemento[i] = caractere_lido;
        i++;
        // printf("%c", caractere_lido);
        caractere_lido = fgetc(arquivo_entrada);
    }
    elemento[i] = '\0';

    // printf("Elemento = (%s) \n", elemento);

    return elemento;
}

void criar_cabecalho(FILE* arquivo_saida, CABECALHO cabecalho){

    fseek(arquivo_saida, 0, SEEK_SET);

    // Escreve os valores do cabeçalho no binário
    fwrite(&cabecalho.status,      sizeof(char), 1, arquivo_saida);
    fwrite(&cabecalho.topo,        sizeof(int),  1, arquivo_saida);
    fwrite(&cabecalho.proxRRN,     sizeof(int),  1, arquivo_saida);
    fwrite(&cabecalho.nroRegRem,   sizeof(int),  1, arquivo_saida);
    fwrite(&cabecalho.nroPagDisco, sizeof(int),  1, arquivo_saida);
    fwrite(&cabecalho.qttCompacta, sizeof(int),  1, arquivo_saida);

    // Deixa todas os demais endereços do disco setados com $
    for (int i = 0; i < (TAM_DISCO - 21); i++){
    fwrite("$", sizeof(char), 1, arquivo_saida);
    }

}


void escreve_dados(FILE* arquivo_entrada, FILE* arquivo_saida){

    // Escreve a versão inicial do cabeçalho
    CABECALHO cabecalho;

    cabecalho.status      =  0;
    cabecalho.topo        = -1;
    cabecalho.proxRRN     =  0;
    cabecalho.nroRegRem   =  0;
    cabecalho.nroPagDisco =  1; // Considera a página de cabeçalho
    cabecalho.qttCompacta =  0;

    criar_cabecalho(arquivo_saida, cabecalho);

    int reg     =  0; // Número de registros.
    int reg_pag =  0; // Número de registros em uma página.
    int num_pag =  2; // Número de páginas ocupadas pelo arquivo de dados.
    char* elem;
    DADO str;

    // Le a primeira linha do código e a remove
    char* linha1 = malloc(100 * sizeof(char));
    fgets(linha1, 100, arquivo_entrada);
    free(linha1);

    // Le o primeiro elemento da descricao
    int i = 0;  // Tipo de elemento a ser lido no csv.
    while( (elem = le_elemento(arquivo_entrada)) != NULL ){
        switch(i){
            case 0:
                strcpy(str.nome,elem);
                break;
            case 1:
                strcpy(str.dieta,elem);
                break;
            case 2:
                strcpy(str.habitat,elem);
                break;
            case 3:
                str.populacao = atoi(elem);
                break;
            case 4:
                strcpy(str.tipo,elem);
                break;
            case 5:
                str.velocidade = atoi(elem);
                break;
            case 6:
                str.unidadeMedida = elem[0];
                break;
            case 7:
                str.tamanho = atof(elem);
                break;
            case 8:
                strcpy(str.especie,elem);
                break;
            case 9:
                strcpy(str.alimento,elem);
                break;
        }
        
        // Faz com que passe para o proximo caso
        i = (i+1) % 10;
        free(elem);

        if (i == 0) {
            char removido = '0';
            int encadeamento = -1;
            char delim = '#';
            char lixo = '$';
            int ac = 0;

            // Escrever a struct no arquivo binário:
            fwrite(&removido,          sizeof(char),  1, arquivo_saida);
            fwrite(&encadeamento,      sizeof(int),   1, arquivo_saida);
            fwrite(&str.populacao,     sizeof(int),   1, arquivo_saida);
            fwrite(&str.tamanho,       sizeof(float), 1, arquivo_saida);
            fwrite(&str.unidadeMedida, sizeof(char),  1, arquivo_saida);
            fwrite(&str.velocidade,    sizeof(int),   1, arquivo_saida);
            ac += 18;

            ac += strlen(str.nome)+1;
            fwrite(&str.nome, sizeof(char), strlen(str.nome), arquivo_saida);
            fwrite(&delim,    sizeof(char), 1,                arquivo_saida); // Delimitador

            ac += strlen(str.especie)+1;
            fwrite(&str.especie, sizeof(char), strlen(str.especie), arquivo_saida);
            fwrite(&delim,       sizeof(char), 1,                   arquivo_saida); // Delimitador
            ac += strlen(str.habitat)+1;
            fwrite(&str.habitat, sizeof(char), strlen(str.habitat), arquivo_saida);
            fwrite(&delim,       sizeof(char), 1,                   arquivo_saida); // Delimitador
            ac += strlen(str.tipo)+1;
            fwrite(&str.tipo, sizeof(char), strlen(str.tipo), arquivo_saida);
            fwrite(&delim,    sizeof(char), 1,                arquivo_saida); // Delimitador
            ac += strlen(str.dieta)+1;
            fwrite(&str.dieta, sizeof(char), strlen(str.dieta), arquivo_saida);
            fwrite(&delim,     sizeof(char), 1,                 arquivo_saida); // Delimitador
            ac += strlen(str.alimento)+1;
            fwrite(&str.alimento, sizeof(char), strlen(str.alimento), arquivo_saida);
            fwrite(&delim,        sizeof(char), 1,                    arquivo_saida); // Delimitador

            while( (160 - ac) > 0){
                fwrite(&lixo, sizeof(char), 1, arquivo_saida); //Identifica o lixo
                ac++;
            }
        }
    
        reg_pag = (reg_pag + 1) % 100;
        reg++;

        if (reg_pag == 0){
            num_pag++;
        }
    }

    // Escreve a versão final do cabeçalho
    cabecalho.status = '1';
    cabecalho.nroPagDisco = num_pag;
    cabecalho.proxRRN = reg / 10;
    criar_cabecalho(arquivo_saida, cabecalho);
}

// Função que lê os dados de um arquivo de entrada
void le_dados(FILE* arquivo_entrada, FILE* arquivo_saida){

    // Escreve a versão inicial do cabeçalho
    CABECALHO cabecalho;

    cabecalho.status      =  0;
    cabecalho.topo        = -1;
    cabecalho.proxRRN     =  0;
    cabecalho.nroRegRem   =  0;
    cabecalho.nroPagDisco =  1; // Considera a página de cabeçalho
    cabecalho.qttCompacta =  0;

    // criar_cabecalho(arquivo_saida, cabecalho);

    int reg     =  0; // Número de registros.
    int reg_pag =  0; // Número de registros em uma página.
    int num_pag =  2; // Número de páginas ocupadas pelo arquivo de dados.
    char* elem;
    DADO str;

    // Le a primeira linha do código e a remove
    char* linha1 = malloc(100 * sizeof(char));
    fgets(linha1, 100, arquivo_entrada);
    free(linha1);

    // Le o primeiro elemento da descricao
    int i = 0;  // Tipo de elemento a ser lido no csv.
    while( (elem = le_elemento(arquivo_entrada)) != NULL ){
        switch(i){
            case 0:
                strcpy(str.nome,elem);
                break;
            case 1:
                strcpy(str.dieta,elem);
                break;
            case 2:
                strcpy(str.habitat,elem);
                break;
            case 3:
                str.populacao = atoi(elem);
                break;
            case 4:
                strcpy(str.tipo,elem);
                break;
            case 5:
                str.velocidade = atoi(elem);
                break;
            case 6:
                str.unidadeMedida = elem[0];
                break;
            case 7:
                str.tamanho = atof(elem);
                break;
            case 8:
                strcpy(str.especie,elem);
                break;
            case 9:
                strcpy(str.alimento,elem);
                break;
        }
        
        // Faz com que passe para o proximo caso
        i = (i+1) % 10;
        free(elem);

        

        // if (i == 0) {
        //     char removido = '0';
        //     int encadeamento = -1;
        //     char delim = '#';
        //     char lixo = '$';
        //     int ac = 0;

        //     // Escrever a struct no arquivo binário:
        //     fread(&removido,          sizeof(char),  1, arquivo_entrada);
        //     fread(&encadeamento,      sizeof(int),   1, arquivo_entrada);
        //     fread(&str.populacao,     sizeof(int),   1, arquivo_entrada);
        //     fread(&str.tamanho,       sizeof(float), 1, arquivo_entrada);
        //     fread(&str.unidadeMedida, sizeof(char),  1, arquivo_entrada);
        //     fread(&str.velocidade,    sizeof(int),   1, arquivo_entrada);

        //     ac += 18;

        //     ac += strlen(str.nome)+1;
        //     fread(&str.nome, sizeof(char), strlen(str.nome), arquivo_entrada);
        //     fread(&delim,    sizeof(char), 1,                arquivo_entrada); // Delimitador

        //     ac += strlen(str.especie)+1;
        //     fread(&str.especie, sizeof(char), strlen(str.especie), arquivo_entrada);
        //     fread(&delim,       sizeof(char), 1,                   arquivo_entrada); // Delimitador
        //     ac += strlen(str.habitat)+1;
        //     fread(&str.habitat, sizeof(char), strlen(str.habitat), arquivo_entrada);
        //     fread(&delim,       sizeof(char), 1,                   arquivo_entrada); // Delimitador
        //     ac += strlen(str.tipo)+1;
        //     fread(&str.tipo, sizeof(char), strlen(str.tipo), arquivo_entrada);
        //     fread(&delim,    sizeof(char), 1,                arquivo_entrada); // Delimitador
        //     ac += strlen(str.dieta)+1;
        //     fread(&str.dieta, sizeof(char), strlen(str.dieta), arquivo_entrada);
        //     fread(&delim,     sizeof(char), 1,                 arquivo_entrada); // Delimitador
        //     ac += strlen(str.alimento)+1;
        //     fread(&str.alimento, sizeof(char), strlen(str.alimento), arquivo_entrada);
        //     fread(&delim,        sizeof(char), 1,                    arquivo_entrada); // Delimitador

        //     while( (160 - ac) > 0){
        //         fread(&lixo, sizeof(char), 1, arquivo_entrada); //Identifica o lixo
        //         ac++;
        //     }
        // }
    
        // reg_pag = (reg_pag + 1) % 100;
        // reg++;

        // if (reg_pag == 0){
        //     num_pag++;
        // }


    }

    // Escreve a versão final do cabeçalho
    cabecalho.status = '1';
    cabecalho.nroPagDisco = num_pag;
    cabecalho.proxRRN = reg / 10;
    criar_cabecalho(arquivo_saida, cabecalho);
}