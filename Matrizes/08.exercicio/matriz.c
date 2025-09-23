#include <stdio.h>
#include <stdlib.h>

void imprimeMatriz(int linha, int coluna, int matriz[linha][coluna])
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
  
  return 0;
}
