// Dadas duas matrizes A e B 3 x 3, faça um programa para calcular a soma das matrizes e salvar
// em uma matriz C. Imprima as três matrizes.

#include <stdio.h>
#include <stdlib.h>

int PreencheMatrizes(int matrizA[3][3], int matrizB[3][3])
{
  FILE *arquivo = fopen("entrada.txt", "r");
  if (arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (i < 3)
      {
        if (fscanf(arquivo, "%d", &matrizA[i][j]) != 1)
        {
          fprintf(stderr, "Erro: dados insuficientes no arquivo.\n");
          fclose(arquivo);
          return 1;
        }
      }
      else
      {
        if (fscanf(arquivo, "%d", &matrizB[i-3][j]) != 1)
        {
          fprintf(stderr, "Erro: dados insuficiente no arquivo.\n");
          fclose(arquivo);
          return 1;
        }
      }
    }
  }
  fclose(arquivo);
}

void SomaMatrizes(int matrizA[3][3], int matrizB[3][3], int matrizC[3][3])
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
}

void ImprimeMatriz(int matriz[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%2d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[])
{
  int matrizA[3][3];
  int matrizB[3][3];
  
  PreencheMatrizes(matrizA, matrizB);
  ImprimeMatriz(matrizA);
  printf("\n");

  ImprimeMatriz(matrizB);
  printf("\n");

  int matrizC[3][3];

  SomaMatrizes(matrizA, matrizB, matrizC);
  ImprimeMatriz(matrizC);


  return 0;
}
