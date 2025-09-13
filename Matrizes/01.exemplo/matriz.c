#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PreencheMatriz(int matriz[3][3])
{
  srand(time(NULL));
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      matriz[i][j] = rand();
}

void ImprimeMatriz(int matriz[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[])
{
  int matriz[3][3];

  PreencheMatriz(matriz);
  ImprimeMatriz(matriz);

  return 0;
}
