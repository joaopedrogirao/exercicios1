#include <stdio.h>

int main(){
    float a, l, c;

    puts("Digite a altura da caixa: ");
    scanf("%f", &a);

    puts("Digite a largura da caixa: ");
    scanf("%f", &l);

    puts("Digite o comprimento da caixa: ");
    scanf("%f", &c);

    printf("O volume da caixa é %.2f", a * l * c);

        return 0;

}