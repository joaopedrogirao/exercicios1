#include <stdio.h>
int main(){
int n, n2, digito;
int contador = 0;


puts("Digite um número inteiro:");
scanf("%d", &n);

if(n < 0){ 
    n = -n;


}

n2 = n;
while(n != 0){

digito = n % 10;
if(digito == 7){
    contador++;
}

n = n / 10;



}
printf("O número %d tem %d sete(s)", n2, contador);
return 0;
}