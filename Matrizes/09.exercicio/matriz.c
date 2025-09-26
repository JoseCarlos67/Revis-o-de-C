// Dada uma matriz 4 x 4 faça um programa que diga se ela é um Quadrado Mágico ou não.

#include <stdio.h>
#include <stdlib.h>

#define tam 4

int preencheMatriz(int matriz[tam][tam])
{
  FILE *arquivo = fopen("entrada.txt", "r");
  if (arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo: ");
    return 1;
  }

  for (int i = 0; i < tam; i++)
    for (int j = 0; j < tam; j++)
    {
      if (fscanf(arquivo, "%d", &matriz[i][j]) != 1)
      {
        fprintf(stderr, "Erro: dados insuficientes no arquivo.\n");
        fclose(arquivo);
        return 1;
      }
    }
  fclose(arquivo);
}

int somaDiagonalPrincipal(int matriz[tam][tam])
{
  int soma = 0;
  for (int i = 0; i < tam; i++)
    soma += matriz[i][i];

  return soma;
}

int somaDiagonalSecundaria(int matriz[tam][tam])
{
  int soma = 0;
  for (int i = 0; i < tam; i++)
    soma += matriz[i][tam - 1 - i];

  return soma;
}

void somaColunas(int matriz[tam][tam], int somaCol[tam])
{
  for (int j = 0; j < tam; j++)
    somaCol[j] = 0;

  for (int i = 0; i < tam; i++)
    for (int j = 0; j < tam; j++)
      somaCol[j] += matriz[i][j];
}

void somaLinhas(int matriz[tam][tam], int somaLin[tam])
{
  for (int i = 0; i < tam; i++)
    somaLin[i] = 0; // zera o vetor

  for (int i = 0; i < tam; i++)
    for (int j = 0; j < tam; j++)
      somaLin[i] += matriz[i][j]; // soma por linha
}

void imprimeMatriz(int matriz[tam][tam])
{
  for (int i = 0; i < tam; i++)
  {
    for (int j = 0; j < tam; j++)
    {
      printf("%2d ", matriz[i][j]);
    }
    printf("\n");
  }
}

void verificaQuadradoMagico(int matriz[tam][tam])
{
  int falhou = 0;
  int somaDP = somaDiagonalPrincipal(matriz);
  int somaDS = somaDiagonalSecundaria(matriz);
  if (somaDS != somaDP)
  {
    printf("\nDiagonais diferentes!");
    falhou = 1;
  }
  else
    printf("\nDiagonais iguais!");

  int somaCol[tam];
  somaColunas(matriz, somaCol);
  int verificaSomaColELin = 0;
  for (int i = 1; i < tam; i++)
    if (somaCol[i - 1] == somaCol[i])
      verificaSomaColELin++;
  if (verificaSomaColELin == tam - 1)
    printf("\nSoma das colunas iguais!");
  else
  {
    printf("\nSoma das colunas diferentes!");
    falhou = 1;
  }

  int somaLin[tam];
  verificaSomaColELin = 0;
  somaLinhas(matriz, somaLin);
  int verificaSomaLin = 0;
  for (int i = 1; i < tam; i++)
    if (somaLin[i - 1] == somaLin[i])
      verificaSomaColELin++;
  if (verificaSomaColELin == tam - 1)
    printf("\nSoma das linhas iguais!");
  else
  {
    printf("\nSoma das linhas diferentes!");
    falhou = 1;
  }

  if (falhou == 0)
    printf("\nEH QUADRADO MAGICO!");
  else
    printf("\nNAO EH QUADRADO MÁGICO!");

  printf("\n");
}

int main(int argc, char const *argv[])
{
  int matriz[tam][tam];
  preencheMatriz(matriz);
  printf("Matriz:\n");
  imprimeMatriz(matriz);
  verificaQuadradoMagico(matriz);
  return 0;
}
