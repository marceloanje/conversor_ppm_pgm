//---------------------------------------------------------------------
// Arquivo	    : img.h
// Conteudo	    : definicoes do TAD IMG
// Autor	    : Marcelo Andrade
// Historico	: 2022-09-10
//---------------------------------------------------------------------

#ifndef IMGH
#define IMGH


typedef struct mat{
	double **m;      // vetor bidimencional por aloacacao dinamica
	int tamx, tamy;  // dimensoes da matriz
} mat_tipo;


void criaMatriz(mat_tipo *mat, int tx, int ty);
void inicializaValores(mat_tipo *mat, char *nome_arq);
void converteImagem(mat_tipo *a, mat_tipo * b);
void criaImagemPGM(mat_tipo *mat, char nomeMatriz[100]);
void destroiMatriz(mat_tipo *a);

#endif
