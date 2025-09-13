// Faça um programa que leia 10 números reais e os armazene em um vetor. Em seguida, leia um
// código inteiro e faça uma das ações abaixo:
// 0 – finaliza o programa;
// 1 – imprime o vetor na ordem do início ao fim;
// 2 – imprime o vetor na ordem inversa (do fim para o início).
// O programa deve funcionar até que o usuário digite 0 para finalizar.

#include <stdio.h>
#include <stdlib.h>

void AlimentarVetor(int vetor[]){
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &vetor[i]) != 1) {
            printf("Erro ao ler número %d\n", i + 1);
        }
    }
}

void PrintarVetor(int vetor[]) {
    for(int i = 0; i < 10; i++) {
        printf("%d\n", vetor[i]);
    }
}

int main(int argc, char const *argv[])
{
    int vetor[10];
    AlimentarVetor(vetor);
    PrintarVetor(vetor);
    return 0;
}
