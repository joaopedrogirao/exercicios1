#include <stdio.h>
int main(){
    int n;
    puts("Digite um número inteiro de 5 dígitos:");
    scanf("%d", &n);
   
    if(n >= 10000 && n <= 99999){

    int a = n / 10000, e = n % 10, b = (n / 1000) % 10, d = (n / 10) % 10;

    if (a == e && b == d){
        printf("O número %d é um palíndromo", n);
    }
    else{
        printf("O número %d não é um palíndromo", n);
    }

    }
else{
    puts("O número não possui 5 dígitos");
}
return 0;

}