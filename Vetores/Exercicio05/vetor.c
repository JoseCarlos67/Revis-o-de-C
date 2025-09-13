// Faça um programa que receba a temperatura média de cada mês do ano, armazenando-as em um
// vetor. Ao final, mostre a maior e a menor temperatura do ano e em que mês ocorreram (mostrar o
// mês por extenso: janeiro, fevereiro ...). Desconsidere empates.

#include <stdio.h>
#include <stdlib.h>

int MaiorTemperatura(float temperaturas[]) {
    int auxTemp = 0;
    int auxIndex = 0;
    for(int i = 0; i < 12; i++) {
        if(auxTemp <= temperaturas[i]){
            auxIndex = i;
            auxTemp = temperaturas[i];
        }
    }

    return auxIndex;
}

int main(int argc, char const *argv[])
{
    float temperaturas[12] = {49.5, 28.7, 27.2, 24.8, 21.4, 19.1, 18.6, 20.3, 32.7, 25.9, 27.8, 28.0};
    char meses[12][20] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    for (int i = 0; i < 12; i++)
    {
        printf("%d - %.1f\n", i+1, temperaturas[i]);
    }
    
    int maiorTemperatura = MaiorTemperatura(temperaturas);

    printf("\nMaior Temperatura no mês de %s: %.1f\n",meses[maiorTemperatura], temperaturas[maiorTemperatura]);
    return 0;
}
