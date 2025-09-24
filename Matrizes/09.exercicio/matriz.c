// Dada uma matriz 4 x 4 faça um programa que diga se ela é um Quadrado Mágico ou não.

#include <stdio.h>
#include <stdlib.h>

int preencheMatriz(int matriz[4][4])
{
  FILE *arquivo = fopen("entrada.txt", "r");
  if (arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo: ");
    return 1;
  }

  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
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

void verificaQuadradoMagico(int matriz[4][4])
{

}

void imprimeMatriz(int matriz[4][4])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      printf("%2d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[])
{
  int matriz[4][4];
  preencheMatriz(matriz);
  printf("Matriz original:\n");
  imprimeMatriz(matriz);
  printf("\n");
  return 0;
}
