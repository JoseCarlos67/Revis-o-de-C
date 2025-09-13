#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int vetor[4];

    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        vetor[i] = rand() % 67;
    }


    for(int i = 0; i < 4; i++)
        printf("%d - ", vetor[i]);

    return 0;
}
