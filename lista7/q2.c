#include <stdio.h>
#define TAM 30
struct estoque{
    char nomePeca[TAM];
    int numeroPeca;
    float preco;
    int pedido;
};
int main(){  
struct estoque p;

puts("Digite o nome da peça:");
fgets(p.nomePeca, TAM, stdin);

puts("Digite o número da peça:");
scanf("%d", &p.numeroPeca);

puts("Digite o preço da peça:");
scanf("%f", &p.preco);

puts("Digite o número do pedido:");
scanf("%d", &p.pedido);

printf("Nome da peça: %sNúmero da peça: %d\nPreço da peça: %.2f\nNúmero do pedido: %d", p.nomePeca, p.numeroPeca, p.preco, p.pedido);

return 0;
}

