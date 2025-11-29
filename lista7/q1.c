#include <stdio.h>

struct aluno{
    float media;
    float n1;
    float n2;
};

int main(){
    struct aluno a;

    puts("Digite a primeira nota:");
    scanf("%f", &a.n1);

    puts("Digite a segunda nota:");
    scanf("%f", &a.n2);

    a.media = (a.n1 + a.n2) / 2.0;

    printf("Média = %.2f", a.media);

    return 0;


}

