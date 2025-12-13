#include <stdio.h>
#include <string.h>
#define TAM 50

struct Ferramenta{
    int nr;
    char nome[TAM];
    int quantidade;
    double custo;


};

    void reiniciararquivo(FILE *fPtr);
    void inserirferramenta(FILE *fPtr);
    void listarferramentas(FILE *fPtr);
    void excluirferramenta(FILE *fPtr);
    void atualizarferramenta(FILE *fPtr);
    int menu();

    int main(){
    FILE *f;

    f = fopen("hardware.dat", "rb+");
    
    
    if(f == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }


    struct Ferramenta vazio = {0, "", 0, 0};

    for(int i = 0; i < 100; i++){
        fwrite(&vazio, sizeof(struct Ferramenta), 1, f);

    }
    int opcao;
    while ((opcao = menu()) != 6) {
        switch (opcao) {
            case 1: inserirferramenta(f); break;
            case 2: listarferramentas(f); break;
            case 3: excluirferramenta(f); break;
            case 4: atualizarferramenta(f); break;
            case 5: 
            
                reiniciararquivo(f); 
                break;
            default: puts("Opcão inválida");
        }
    }

    fclose(f);
    return 0;
}


int menu() {
    int op;
    printf("\n--- LOJA DE FERRAMENTAS ---\n");
    puts("1 - Inserir nova ferramenta");
    puts("2 - Listar todas as ferramentas");
    puts("3 - Excluir ferramenta");
    puts("4 - Atualizar dados de ferramenta");
    puts("5 - Zerar arquivo (Reset)");
    puts("6 - Sair");
    puts("Escolha uma opcao: ");
    scanf("%d", &op);
    return op;
}








void reiniciararquivo(FILE *f){
    struct Ferramenta vazia = {0, "", 0, 0};
    rewind(f);

    for(int i = 0; i < 100; i++){
        fwrite(&vazia, sizeof(struct Ferramenta), 1, f);

    }
    puts("Novo arquivo iniciado");

}

void inserirferramenta(FILE *f){
    struct Ferramenta ferramentas = {0, "", 0, 0};
    int nr;

    puts("Digite um número de registro para a ferramenta (1 a 100): ");
    scanf("%d", &nr);

    if(nr < 1 || nr > 100){
        puts("Número de registro inválido");
        return;

    }

    fseek(f, (nr - 1) * sizeof(struct Ferramenta), SEEK_SET);

    fread(&ferramentas, sizeof(struct Ferramenta), 1, f);
    
    if(ferramentas.nr != 0) {
        printf("O registro %d já contém a ferramenta '%s'.\n", nr, ferramentas.nome);

    }else{
        ferramentas.nr = nr;

        puts("Nome da ferramenta: ");
        getchar();
        fgets(ferramentas.nome, TAM, stdin);
        ferramentas.nome[strcspn(ferramentas.nome, "\n")] = '\0';

        puts("Quantidade: ");
        scanf("%d", &ferramentas.quantidade);

        puts("Custo: ");
        scanf("%lf", &ferramentas.custo);

        fseek(f, (nr-1) * sizeof(struct Ferramenta), SEEK_SET);

        fwrite(&ferramentas, sizeof(struct Ferramenta), 1, f);
        puts("Ferramenta adicionada");
    }
}

void listarferramentas(FILE *f){
    struct Ferramenta ferramentas;
    rewind(f);

    while (fread(&ferramentas, sizeof(struct Ferramenta), 1, f) == 1){
        if (ferramentas.nr != 0){
            printf("%-10d %-30s %-10d R$ %-10.2f\n", ferramentas.nr, ferramentas.nome, ferramentas.quantidade, ferramentas.custo);
        }
    }
}

void excluirferramenta(FILE *f){
    struct Ferramenta vazia = {0, ", 0, 0.0"};
    struct Ferramenta temp;
    int nr;

    printf("Digite o número do registro a ser excluído (1 a 100): ");
    scanf("%d", &nr);

    if (nr < 1 || nr > 100) return;

    fseek(f, (nr - 1) * sizeof(struct Ferramenta), SEEK_SET);
    fread(&temp, sizeof(struct Ferramenta), 1, f);

    if (temp.nr == 0) {
        printf("O registro #%d ja esta vazio.\n", nr);
    } else {
        fseek(f, (nr - 1) * sizeof(struct Ferramenta), SEEK_SET);
        fwrite(&vazia, sizeof(struct Ferramenta), 1, f);
        printf("Registro #%d excluido com sucesso.\n", nr);
    }

}

void atualizarferramenta(FILE *f){
struct Ferramenta ferramentas;
    int nr;

    printf("Digite o ID da ferramenta a atualizar (1-100): ");
    scanf("%d", &nr);

    if (nr < 1 || nr > 100) return;

    fseek(f, (nr - 1) * sizeof(struct Ferramenta), SEEK_SET);
    fread(&ferramentas, sizeof(struct Ferramenta), 1, f);

    if (ferramentas.nr == 0) {
        printf("Nenhuma ferramenta encontrada no registro #%d.\n", nr);
        return;
    }

    puts("Dados Atuais:");
    printf("Nome: %s | Qtd: %d | Custo: %.2f\n", ferramentas.nome, ferramentas.quantidade, ferramentas.custo);
    
    puts("Novos Dados:");
    puts("Novo Nome:");
    getchar();
    fgets(ferramentas.nome, 30, stdin);
    ferramentas.nome[strcspn(ferramentas.nome, "\n")] = '\0';

    printf("Nova Quantidade: ");
    scanf("%d", &ferramentas.quantidade);

    printf("Novo Custo: ");
    scanf("%lf", &ferramentas.custo);

    fseek(f, (nr - 1) * sizeof(struct Ferramenta), SEEK_SET);
    fwrite(&ferramentas, sizeof(struct Ferramenta), 1, f);
    puts("Atualizado com sucesso!");
}

