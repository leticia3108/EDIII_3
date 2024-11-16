/*
* O código a seguir faz a recuperação de dados de um arquivo binário
* solicitado pelo usuário, e utilizará critérios de busca a escolha
* do própŕio.
* 
* Essa funcionalidade pode retornar 0 registros, para o caso de não
* haver algum registro que obedeça aos critérios de busca estabelecidos,
* 1 registro, ou diversos, contato que estejam de acordo com os critérios
* do ussuário.
* 
* Aqui será feita a etapa principal, solicitando funções criadas no
* módulo 'common.c'
*/

#include "header.h"
#define T_MAX 30


#define STRING_TO_INT(str) \
    (strcmp(str, "populacao") == 0 ? 5 : \
     strcmp(str, "tamanho") == 0 ? 9 : \
     strcmp(str, "unidade") == 0 ? 13 : \
     strcmp(str, "velocidade") == 0 ? 14 : \
     strcmp(str, "nome") == 0 ? 18 : \
     strcmp(str, "especie") == 0 ? 19 : \
     strcmp(str, "habitat") == 0 ? 20 : \
     strcmp(str, "tipo") == 0 ? 21 : \
     strcmp(str, "dieta") == 0 ? 22 : \
     strcmp(str, "alimento") == 0 ? 23 :-1) 

/* Funções para execução do ex 2 */

void ex3(){

// Ler o nome do arquivo de entrada, com tamanho máximo 30:
char nome_entrada[T_MAX];
scanf("%s", nome_entrada);
DADO* dado = malloc(sizeof(DADO));

// Abertura do binário de entrada para leitura
FILE *binario_entrada = fopen(nome_entrada,"rb");
if (binario_entrada == NULL){
    printf("Erro ao abrir o arquivo de entrada");
    return;
}

// Leitura do número de campos
int num_campos;
scanf("%d", &num_campos);
//printf("%d\n", num_campos);

// Strings que definem um comando de busca
char str_buscada[num_campos][30]; // Armazena as strings buscadas
int tipo_busca[num_campos]; // Armazena o tipo de busca, como definido na macro
char temp[30]; // String temporária que será convertida no tipo de busca

int r = 0; // Contagem dos registros
char removido;
int achados = 0; //Contagem dos registros que correspoondem à busca
int stop = 0; // Flag para parar o loop quando for encontrado um nome específico
int num, num2;
float tam;
char* str = malloc(sizeof(char)*30);
char unidade;

for (int i = 0; i < num_campos; i++){

    achados = 0;
    printf("Busca %d\n", i+1);

    scanf("%s",temp);

    tipo_busca[i] = STRING_TO_INT(temp);

    //printf("(%d)", tipo_busca[i]);
    if (tipo_busca[i] >= 18){
     scan_quote_string(str_buscada[i]);} else {
     scanf("%s", str_buscada[i]);
    }
   // printf("string buscada = (%s)", str_buscada[i]);

// Ir para o primeiro registro de dados disponível
    fseek(binario_entrada, 1600, SEEK_SET);
        r = 0;
        while (fread(&removido, sizeof(char), 1, binario_entrada) != 0){

        if (stop == 1){
            stop = 0;
            break;
        }
        switch (tipo_busca[i]){

        case 5:
        case 14:
            fseek(binario_entrada, tipo_busca[i]-1, SEEK_CUR) ;
            fread(&num, sizeof(int), 1, binario_entrada);
 
            num2 = atoi(str_buscada[i]);

            if ((num == atoi(str_buscada[i]))  && (removido == '0')){
                fseek (binario_entrada, 1600+160*(r), SEEK_SET);
                imprime_dado(binario_entrada, dado);
                achados++;
            }
            r++;
            break;


        case 9:
            fseek(binario_entrada, tipo_busca[i]-1, SEEK_CUR) ;
            fread(&tam, sizeof(float), 1, binario_entrada);

            if (tam == atof(str_buscada[i]) && removido =='0'){
                fseek (binario_entrada, 1600+160*(r), SEEK_SET);
                imprime_dado(binario_entrada, dado);
                achados++;
            }
            r++;
            break;

        case 13:
            fseek(binario_entrada, tipo_busca[i]-1, SEEK_CUR) ;
            fread(&unidade, sizeof(char), 1, binario_entrada);
 

            if (unidade == (str_buscada[i][0]) && removido =='0'){
                fseek (binario_entrada, 1600+160*(r), SEEK_SET);
                imprime_dado(binario_entrada, dado);
                achados++;
            }
            r++;
            break;

        case 18:

            fseek(binario_entrada, 17, SEEK_CUR);

                leitura_variavel(str, binario_entrada);

            if (strcmp(str_buscada[i], str) == 0 && removido =='0'){
                fseek (binario_entrada, 1600+160*(r), SEEK_SET);
                imprime_dado(binario_entrada, dado);
                achados++;
                stop = 1;
            }
            r++;
            break;

        case 19:
        case 20:
        case 21:
        case 22:
        case 23:

            fseek(binario_entrada, 17, SEEK_CUR);

            for (int caso = 0; caso <= tipo_busca[i]-18; caso++){
                leitura_variavel(str, binario_entrada);}

          //  printf("string encontrada = (%s)", str);

            if (strcmp(str_buscada[i], str) == 0 && removido =='0'){
                fseek (binario_entrada, 1600+160*(r), SEEK_SET);
                imprime_dado(binario_entrada, dado);
                achados++;
            }
            r++;
            break;
            
        }
        fseek (binario_entrada, 1600+160*(r), SEEK_SET);
        }       

    if (achados==0){
        printf("Registro inexistente.\n\n");
    }
    printf("Numero de paginas de disco: %d\n\n", r/10 + 1 + (r%10 != 0));
     }

    free(dado);
    free(str);
    fclose(binario_entrada);
}
