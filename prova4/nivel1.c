#include <stdio.h>
#include <math.h>

struct Ponto
{
    float x;
    float y;
};

int main(){
    struct Ponto p1;
    struct Ponto p2;

    puts("Digite as coordenada de x do primeiro ponto");
    scanf("%f", &p1.x);

    puts("Digite as coordenada de y do primeiro ponto");
    scanf("%f", &p1.y);    

    p2.x = -2;
    p2.y = 2;

    float distancia = sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y))); 


printf("Distância entre os pontos 1 e 2: %.2f", distancia);

    return 0;
}
