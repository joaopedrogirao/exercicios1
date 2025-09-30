#include <stdio.h>
int main(){

    int n;
    int m;

    puts("Digite o primeiro número:");
    scanf("%d", &n);

    puts("Digite o segundo número:");
    scanf("%d", &m);


     !(n % m)? printf("%d é múltiplo de %d", n, m): printf("%d não é múltiplo de %d", n, m);
     
     return 0;
}