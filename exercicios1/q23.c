#include <stdio.h>
int main(){
int x, n;

puts("Digite um número inteiro:");
scanf("%d", &x);

puts("Digite um número inteiro para ser usado como expoente de 2:");
scanf("%d", &n);

 x = x << n;

printf("O resultado é %d", x);

}