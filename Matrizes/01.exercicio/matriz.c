//Faça um programa que calcule e imprima a soma de todos os elementos de uma matriz 5 x 7.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PreencheMatriz(int matriz[5][7]) 
{
  srand(time(NULL));
  int min = 1, max = 255;

  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 7; j++)
      matriz[i][j] = min + rand() % (max - min + 1);
}

void SomaMatrizes(int matriz01[5][7], int matriz02[5][7], int matrizSoma[5][7]) {
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 7; j++)
      matrizSoma[i][j] = matriz01[i][j] + matriz02[i][j];
}

void ImprimeMatriz(int matriz[5][7])
{
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 7; j++)
    {
      printf("%d - ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[])
{
  int matriz01[5][7];
  int matriz02[5][7];

  PreencheMatriz(matriz01);
  PreencheMatriz(matriz02);

  int matrizSoma[5][7];

  SomaMatrizes(matriz01, matriz02, matrizSoma);
  ImprimeMatriz(matrizSoma);
  

  return 0;
}
