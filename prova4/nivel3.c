#include <stdio.h>
#include <string.h>

struct carro{
    char marca[20];
    int ano;
    float preco;


};

int main(){
    struct carro c[5];
    float valor_maximo;

    for(int i = 0; i < 5; i++){
        printf("Marca do %d° carro\n", i+1);
        fgets(c[i].marca, 20, stdin);

        puts("Ano do carro");
        scanf("%d", &c[i].ano);

        puts("Preço do carro");
        scanf("%f", &c[i].preco);


    }

    puts("Digite qual valor máximo para pagar no carro");
    scanf("%f", &valor_maximo);


    int encontrou = 0;
    for (int i = 0; i < 5; i++) {
        // Acessamos o preço do carro na posição 'i' usando o PONTO
        if (c[i].preco < valor_maximo) {
            printf("Marca: %-15s | Ano: %d | Preço: R$ %.2f\n", 
                   c[i].marca, c[i].ano, c[i].preco);
            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("Nenhum carro encontrado nessa faixa de preço.\n");
    }

    return 0;


}