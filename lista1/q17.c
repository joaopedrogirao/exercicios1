#include <stdio.h>
int main(){
    float r;
    puts("Digite o valor do raio do círculo:");
    scanf("%f", &r);

printf("O valor do diâmetro do círculo é %f, o valor da circunferência é %f e o valor da área é %f", 2 * r, (2 * 3.14159) * r, 3.14159 * (r * r));

return 0;
}