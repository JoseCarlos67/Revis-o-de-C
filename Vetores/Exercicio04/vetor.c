#include <stdio.h>
#include <stdlib.h>

void valorTotalUnitario(float valorItens[], int quantidadeItens[], float valorTotalItens[]) {
    for(int i = 0; i < 3; i++) {
        valorTotalItens[i] = valorItens[i] * quantidadeItens[i];
    }
}

float valorTotal(float valorTotalItens[]) {
    float total;
    for (int i = 0; i < 3; i++)
    {
        total += valorTotalItens[i];
    }
    return total;
}

float valorComissao(float valorTotalVendido) {
    return valorTotalVendido * 0.05;
}

void mostraDados(float valorItens[], int quantidadeItens[], float valorTotalItens[], float valorTotalVendido, float comissaoVendedor) {
    for (int i = 0; i < 3; i++)
    {
        printf("Quantidade vendida do item %d: %d\n", i+1, quantidadeItens[i]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Valor unitario do item %d: R$ %.2f\n", i+1, valorItens[i]);
    }
    printf("\n");
    
    for (int i = 0; i < 3; i++)
    {
        printf("Valor total vendido do item %d: R$ %.2f\n", i+1, valorTotalItens[i]);
    }
    printf("\n");

    printf("==================================\n");

    printf("Valor total vendido hoje: R$ %.2f\n", valorTotalVendido);
    printf("Comissoa do vendedor: R$ %.2f\n\n", comissaoVendedor);
}

int main(int argc, char const *argv[])
{
    float valorItens[3] = {10.0, 25.45, 8.67};
    int quantidadeItens[3] = {10, 76, 23};
    
    float valorTotalItens[3]; 
    valorTotalUnitario(valorItens, quantidadeItens, valorTotalItens);
    
    float valorTotalVendido = valorTotal(valorTotalItens);
    float comissaoVendedor = valorComissao(valorTotalVendido);

    mostraDados(valorItens, quantidadeItens, valorTotalItens, valorTotalVendido, comissaoVendedor);
    return 0;
}
