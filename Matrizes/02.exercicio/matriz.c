// 9) Crie um programa que preencha uma matriz 5x10 com números inteiros. Em seguida faça:
// a) some cada uma das linhas armazenando o resultado em um vetor;                               x
// b) some cada uma das colunas armazenando o resultado em um vetor;                              x
// c) Imprima os dois vetores identificando qual é a soma das linhas e qual é a soma das colunas. x

#include <stdio.h>
#include <stdlib.h>

int PreencheMatriz(int matriz[5][10])
{
  FILE *arquivo = fopen("entrada.txt", "r");
  if (arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  for (int i = 0; i < 5; i++)
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

void SomaLinhas(int matriz[5][10], int somaDasLinhas[5])
{
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 10; j++)
      somaDasLinhas[i] += matriz[i][j];
}

void SomaColunas(int matriz[5][10], int somaDasColunas[])
{
  for (int j = 0; j < 10; j++)
    for (int i = 0; i < 5; i++)
      somaDasColunas[j] += matriz[i][j];
}

void ImprimeVetor(int vetor[], int tamanhoVetor)
{
  for (int i = 0; i < tamanhoVetor; i++)
  {
    printf("%d - ", vetor[i]);
  }

  printf("\n");
}

void ImprimeMatriz(int matriz[5][10])
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      printf("%d - ", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int matriz[5][10];
  int somaDasLinhas[5] = {0};

  PreencheMatriz(matriz);
  ImprimeMatriz(matriz);

  SomaLinhas(matriz, somaDasLinhas);
  printf("\nSoma das linhas: ");
  ImprimeVetor(somaDasLinhas, 5);

  int somaDasColunas[10] = {0};
  SomaColunas(matriz, somaDasColunas);
  printf("\nSoma das colunas: ");
  ImprimeVetor(somaDasColunas, 10);
  return 0;
}
