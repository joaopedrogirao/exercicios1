#include <stdio.h>


    struct aluno{
    float media;
    float n1;
    float n2;
};

float calcular_media(struct aluno a);
int main(){
    struct aluno alunos[3];

    for(int i = 0; i < 3; i++){
        printf("Digite a primeira nota do aluno %d: ", i+1);
        scanf("%f", &alunos[i].n1);

        printf("Digite a segunda nota do aluno %d: ", i+1);
        scanf("%f", &alunos[i].n2);

        alunos[i].media = calcular_media(alunos[i]);


    }

    for(int i = 0; i < 3; i++){

        printf("Média do aluno %d: %.1f\n", i+1, alunos[i].media);
    }


    return 0;


}

    float calcular_media(struct aluno a){
        return ((a.n1 + a.n2) / 2);
    }