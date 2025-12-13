#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50


int main(){
    FILE *f;

    char nome[TAM];
    int idade;
    char email[TAM];


    f = fopen("usuarios.csv", "w");

    if(f == NULL){
        printf("Erro ao abrir o f");
        return 1;
    }

    fprintf(f, "Nome, Idade, Email\n");

    int n = 0;
    puts("Digite a quantidade de usúarios que você deseja cadastrar");
    scanf("%d", &n);

    getchar();

    for(int i = 0; i < n; i++){

        printf("Digite o nome do %d° usuário: ", i+1);
        fgets(nome, TAM, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        printf("Digite a idade do %d° usuário: ", i+1);
        scanf("%d", &idade);

        getchar();
        
        printf("Digite o email do %d° usuário: ", i+1);
        fgets(email, TAM, stdin);
        email[strcspn(email, "\n")] = '\0';


        fprintf(f, "%s, %d, %s\n", nome, idade, email);

        


    }

    fclose(f);

    return 0;



}