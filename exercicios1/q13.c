#include <stdio.h>

int main(){
    float c;

    printf("Digite a temperatura em celsius: ");
    scanf("%f", &c);

printf("O valor em fahrenheit dessa temperatura é: %.1f", (c * 9 + 160) / 5 );

return 0;



}