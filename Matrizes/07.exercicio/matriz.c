//  Faça um programa para calcular a transposta de uma matriz 5 x 4. Imprima as duas matrizes na 
// tela

#include <stdio.h>
#include <stdlib.h>

int PreencheMatriz(int matriz[5][4])
{
  FILE *arquivo = fopen("entrada.txt", "r");
  if (arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4; j++)
    {
      if (fscanf(arquivo, "%d", &matriz[i][j]) !=1)
      {
        fprintf(stderr, "Erro: dados insuficientes no arquivo.\n");
        fclose(arquivo);
        return 1;
      }
    }
    fclose(arquivo);
}

void Transposta(int matrizOriginal[5][4], int matrizTransposta[4][5])
{
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4; j++)
      matrizTransposta[j][i] = matrizOriginal[i][j];
}

void ImprimeMatriz(int linha, int coluna, int matriz[linha][coluna])
{
  for (int i = 0; i < linha; i++)
  {
    for (int j = 0; j < coluna; j++)
    {
      printf("%2d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[])
{
  int matriz[5][4];
  PreencheMatriz(matriz);
  ImprimeMatriz(5, 4, matriz);

  printf("\nMatriz Transposta:\n");
  int matrizTransposta[4][5];
  Transposta(matriz, matrizTransposta);
  ImprimeMatriz(4, 5,matrizTransposta);
  return 0;
}
