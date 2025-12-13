#include <stdio.h>
#include <stdlib.h>

struct livro
{
    char titulo[50];
    char autor[30];
    int paginas;
};

int main(){
    struct livro *l;

    int quantidade;
    puts("Quantos livros você deseja registrar?");
    scanf("%d", &quantidade);

    l = malloc(quantidade * sizeof(struct livro));

    for(int i = 0; i < quantidade; i++){
        while (getchar() != '\n');

        puts("Digite o nome do livro");
        fgets((l+i)->titulo, 50, stdin);

        puts("Digite o nome do autor");
        fgets((l+i)->autor, 30, stdin);

        puts("Digite a quantidade de páginas do livro");
        scanf("%d", &((l+i)->paginas));


    }

     for(int i = 0; i < quantidade; i++){
        printf("\n%d° Livro: %sAutor: %sQuantidade de páginas: %d", i+1, (l+i)->titulo, (l+i)->autor,  (l+i)->paginas);

     }

     free(l);

     return 0;


    

    
    








}
