//---------------------------------------------------------------------
// Arquivo	    : main.c
// Conteudo	    : programa de avaliacao do TAD IMG
// Autor	    : Marcelo Andrade
// Historico	: 2022-09-10
//---------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>
#include <string.h>
#include "img.h"
#include "msgassert.h" 


// variaveis globais para opcoes
//static int opescolhida;
char lognome[100];
int regmem;
char nome_arq1[100], nome_arq2[100];

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
    fprintf(stderr,"\t-i <int>\t(nome do arquivo de entrada)\n");
    fprintf(stderr,"\t-o <int>\t(nome do arquivo de saida)\n");
    fprintf(stderr,"\t-p <arq>\t(arquivo de registro de acesso)\n");
    fprintf(stderr,"\t-l \t(registrar acessos a memoria)\n");
}


void parse_args(int argc,char ** argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida, optx, opty, regmem, lognome
{
     // variaveis externas do getopt
     extern char * optarg;
     extern int optind;

     // variavel auxiliar
     int c;

     // inicializacao variaveis globais para opcoes
     regmem = 0;
     lognome[0] = 0;
     nome_arq1[0] = 0;
     nome_arq2[0] = 0;

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "smtp:lh:o:i:")) != EOF)
       switch(c) {
         case 'p': 
	          strcpy(lognome,optarg);
		  break;
         case 'i': 
	          strcpy(nome_arq1, optarg);
		  break;
         case 'o': 
	          strcpy(nome_arq2, optarg);
		  break;
         case 'l': 
	          regmem = 1;
		  break;
         case 'h':
         default:
                  uso();
                  exit(1);

       }
}


int main(int argc, char ** argv)
// Descricao: programa principal para execucao de operacoes de matrizes 
// Entrada: argc e argv
// Saida: depende da operacao escolhida
{
    // ate 3 matrizes sao utilizadas, dependendo da operacao
    mat_tipo a, b;

    // avaliar linha de comando
    parse_args(argc,argv);


    inicializaValores(&a, nome_arq1);

    converteImagem(&a, &b);

    criaImagemPGM(&b, nome_arq2);

    destroiMatriz(&a);

    destroiMatriz(&b);

    return 0;
}

