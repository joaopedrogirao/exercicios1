#include <stdio.h>

    struct professor{
        char nome[50];
    };

    struct disciplina{
        char nome[50];
        struct professor p;
    };

    int main(){

        struct disciplina d;
        puts("Digite a disciplina: ");
        fgets(d.nome, 50, stdin);

        puts("Digite o nome do professor: ");
        fgets(d.p.nome, 50, stdin);

        printf("Professor: %sDisciplina: %s", d.p.nome, d.nome);

        return 0;

        
    }
