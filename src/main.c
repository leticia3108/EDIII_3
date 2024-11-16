/*
* Trabalho Prático de Estrutura de Dados III
*
* Alunos:
* Paulo Nunes de Azevedo - Nº USP: 13839010
* Leticia - Nº USP: 
* 
* Desenvolvimento de cada integrante no projeto:
* 
* Leticia:
* Responsável pelo desenvolvimento das funcionalidades 1, 2, 3 e 5.
* 
* Porcengem de participação da sua parte: 90% 
* 
* Paulo:
* Responsável pale modularização do projeto, bem como o desenvolvimento do
* Makefile, além da documentação, correção de bugs de compilação e o
* desenvolvimento das funcionalidades 4 e 6.
*
* Porcengem de participação da sua parte: 60%
* 
*/

#include "header.h"

int main() {
    // Leitura da entrada inicial do usuário
    int opcao = 0;
    scanf("%d", &opcao);
    getc(stdin);

    switch (opcao){
        case 1:
            ex1();
            break;
         case 2:
             ex2();
             break;
        case 3:
            ex3();
            break;
        case 4:
            ex4();
            break;
        case 5:
            ex5();
            break;
        case 6:
            ex6();
            break;
        default:
            printf("\nEntrada inválida\n");
            return 1;
    }

    return 0;
}