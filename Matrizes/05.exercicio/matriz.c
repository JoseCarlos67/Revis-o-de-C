// Faça um programa que imprima na tela a diagonal principal de uma matriz 5 x 5.

#include <stdio.h>
#include <stdlib.h>

int PreencheMatriz(int matriz[5][5])
{
  FILE *arqquivo = fopen("entrada.txt", "r");
  if (arqquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
    {
      if (fscanf(arqquivo, "%d", &matriz[i][j]) != 1)
      {
        fprintf(stderr, "Erro: dados insuficientes no arquivo.\n");
        fclose(arqquivo);
        return 1;
      }
    }

    fclose(arqquivo);
}

void DiagonalPrincipal(int matirz[5][5])
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (i != j)
      {
        printf("00 ");
      } else {
        printf("%2d ", matirz[i][j]);
      }
    }
    printf("\n");
  }
}

void ImprimeMatriz(int matriz[5][5])
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      printf("%2d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[])
{
  int matriz[5][5];
  // DiagonalPrincipal(matriz);
  PreencheMatriz(matriz);
  ImprimeMatriz(matriz);
  printf("\n");
  DiagonalPrincipal(matriz);

  return 0;
}
