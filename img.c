//---------------------------------------------------------------------
// Arquivo	    : img.c
// Conteudo	    : definicoes do TAD IMG
// Autor	    : Marcelo Andrade
// Historico	: 2022-09-10
//---------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "img.h"
#include "msgassert.h"


// Descricao: cria matriz com dimensoes ty X tx
// Entrada: mat, tx, ty
// Saida: mat
void criaMatriz(mat_tipo * mat, int tx, int ty){

    //verifica se os valores de tx e ty são validos
    erroAssert(tx>0,"Dimensao nula");
    erroAssert(ty>0,"Dimensao nula");
    
    // inicializa as dimensoes da matriz
    mat->tamx = tx;
    mat->tamy = ty;

    //aloca as linhas da matriz
    mat->m = malloc(mat->tamy * sizeof(double *));

    //aloca as colunas para cada linha
    for (int i = 0; i < mat->tamy; i++)
        mat->m[i] = malloc(3*(mat->tamx * sizeof(double)));
}

// Descricao: lê o arquivo ppm e inicializa uma matriz mat com esses valores
// Entrada: mat
// Saida: mat
void inicializaValores(mat_tipo *mat, char *nome_arq){

    int valorElemento;
    FILE *arq;

    arq = fopen(nome_arq, "r");
    if (arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");

    //Leitura arquivo número de linhas e de colunas
    //Posteriormente passadas como parâmetro para o método criaMatriz
    
    int i,j,tx,ty, n;
    char str[2];
    
    fscanf(arq, "%s", &str);

    fscanf(arq, "%d %d", &tx, &ty);
    criaMatriz(mat, tx, ty);
    
    fscanf(arq, "%d", &n);
    
    for (i=0; i<mat->tamy; i++){
        for (j=0; j<3*(mat->tamx); j++){
            fscanf(arq, "%d", &valorElemento);
            mat->m[i][j] = valorElemento;
      }
    }

    fclose(arq);
}

// Descricao: converte os valores de uma imagem ppm para uma imagem pgm
// Entrada: mat
// Saida: mat
void converteImagem(mat_tipo *a, mat_tipo *b){

    //cria a matriz que recebera os valores da imagem pgm
    criaMatriz(b,a->tamx, a->tamy);

    int k;

    double elemento;

    //for que caminha a cada três elementos
    for (int i=0; i<a->tamy; i++){

        //variavel auxiliar para preencher a matriz que recebe os valores da conversão
        k = 0;

        for(int j=0; j<3*(a->tamx); j++){

            //realiza a conta com os pixels para conversão
            elemento = 0.192157*((0.30*(a->m[i][j])) + (0.59*(a->m[i][j+1])) + (0.11*(a->m[i][j+2])));

            b->m[i][k] = elemento;

            k++;
            j += 2;
        }
    }
}

// Descricao: cria uma imagem pgm com a valores de mat
// Entrada: mat
// Saida: imagem pgm
void criaImagemPGM(mat_tipo * mat, char nomeMatriz[100]){

    double elemento;
    
    FILE *fp;
    
    fp = fopen(nomeMatriz, "w");

    //imprime os dados padroes do arquivo .pgm    
    fprintf(fp,"%s ", "P2");
    fprintf(fp,"\n");
    fprintf(fp,"%d %d", mat->tamx, mat->tamy);
    fprintf(fp,"\n");
    fprintf(fp,"%d", 49);
    fprintf(fp,"\n");
    

    // imprime as linhas
    for (int i=0; i<mat->tamy; i++){
        for(int j=0; j<mat->tamx; j++){
        
            elemento = floor(mat->m[i][j]);
            fprintf(fp,"%.0f ",elemento);
        }
        fprintf(fp,"\n");
    }
    
    fclose(fp);
}

// Descricao: destroi a matriz a, que se torna inacessível
// Entrada: a
// Saida:
void destroiMatriz(mat_tipo *a){

    // apenas um aviso se a matriz for destruida mais de uma vez
    avisoAssert(((a->tamx>0)&&(a->tamy>0)),"Matriz já foi destruida");

    // torna as dimensoes invalidas
    a->tamx = a->tamy = -1;
}
