// Faça um programa que imprima na tela a diagonal secundária de uma matriz 7 x 7.

#include <stdio.h>
#include <stdlib.h>

int PreencheMatriz(int matriz[7][7])
{
  FILE *arquivo = fopen("entrada.txt", "r");
  if (arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  for (int i = 0; i < 7; i++)
    for (int j = 0; j < 7; j++)
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

void DiagonalSecundaria(int matriz[7][7])
{
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      if (j + i != 6)
      {
        printf("00 ");
      } else 
      {
        printf("%2d ", matriz[i][j]);
      }
    }
    printf("\n");
  }
}

void ImprimeMatriz(int matriz[7][7])
{
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      printf("%2d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[])
{
  int matriz[7][7];
  PreencheMatriz(matriz);
  ImprimeMatriz(matriz);
  printf("\n");
  DiagonalSecundaria(matriz);
  return 0;
}
