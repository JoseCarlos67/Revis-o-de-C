// Faça um programa para ordenar uma matriz com 100 números inteiros. Imprima o matriz antes e
// após a ordenação.

#include <stdio.h>
#include <stdlib.h>

int PreencheMatriz(int matriz[10][10])
{
  FILE *arquivo = fopen("entrada.txt", "r");
  if (arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
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

void ImprimeMatriz(int matriz[10][10])
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      printf("%2d ", matriz[i][j]);
    }
    printf("\n");
  }
}

void ImprimeVetor(int vetor[100])
{
  for (int i = 0; i < 100; i++)
    printf("%d ", vetor[i]);
}

void MatrizParaVetor(int matriz[10][10], int vetor[100])
{
  int index = 0;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      vetor[index++] = matriz[i][j];
}

void VetorParaMatriz(int vetor[100], int matriz[10][10])
{
  int index = 0;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      matriz[i][j] = vetor[index++];
}

void OrganizaVetor(int vetor[100])
{
  int aux = 0;
  for (int i = 0; i < 99; i++)
    for (int j = 0; j < 99; j++)
    {
      if (vetor[j] > vetor[j + 1])
      {
        aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux;
        aux = 0;
      }
    }
}

int main(int argc, char const *argv[])
{
  int matriz[10][10];
  int vetor[100] = {0};
  PreencheMatriz(matriz);
  ImprimeMatriz(matriz);

  MatrizParaVetor(matriz, vetor);
  printf("\n");
  ImprimeVetor(vetor);

  OrganizaVetor(vetor);
  printf("\n\n");
  ImprimeVetor(vetor);

  printf("\n\n");
  VetorParaMatriz(vetor, matriz);
  ImprimeMatriz(matriz);

  return 0;
}
