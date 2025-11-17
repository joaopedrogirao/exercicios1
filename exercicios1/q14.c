#include <stdio.h>
int main(){

unsigned int dia;

puts("Digite a quantidade de dias trabalhados pelo vendedor: ");
scanf("%u", &dia);

float saldo = dia * 50.25;



if(dia >= 10){
    printf("Seu saldo final é: %.2f", saldo * 0.9);

}else if(dia > 20){
    printf("Seu saldo final é: %.2f", saldo * 1.3 * 0.9);

}else{
    printf("Seu saldo final é: %.2f", saldo * 1.2 * 0.9);

}

return 0;




}