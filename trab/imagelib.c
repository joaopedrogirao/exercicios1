#include "imagelib.h"
#include <ctype.h>

Image* create_image(int w, int h, int max_val) {
    Image *img = (Image*) malloc(sizeof(Image));
    img->width = w;
    img->height = h;
    img->max_val = max_val;
    img->tipo = 5; // Padrão P5
    
    // Aloca Matriz 2D (Linhas)
    img->data = (unsigned char**) malloc(h * sizeof(unsigned char*));
    // Aloca Colunas
    for(int i = 0; i < h; i++) {
        img->data[i] = (unsigned char*) malloc(w * sizeof(unsigned char));
    }
    return img;
}

void free_image(Image *img) {
    if (img) {
        for(int i = 0; i < img->height; i++) {
            free(img->data[i]);
        }
        free(img->data);
        free(img);
    }
}

// Lógica adaptada do seu pgm.c
Image* load_pgm(const char *filename) {
    FILE *fp;
    char ch;

    if (!(fp = fopen(filename, "rb"))){
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    if ((ch = getc(fp)) != 'P'){
        puts("A imagem fornecida nao esta no formato pgm");
        exit(2);
    }
    
    int tipo = getc(fp) - 48;
    
    // Pula espaços em branco e comentários (Lógica melhorada do seu pgm.c)
    while ((ch = getc(fp)) != EOF) {
        if (ch == '#') {
            while ((ch = getc(fp)) != '\n' && ch != EOF);
        } else if (!isspace(ch)) {
            ungetc(ch, fp); // Devolve o caractere que não é espaço/comentário
            break;
        }
    }

    int c, r, mv;
    fscanf(fp, "%d %d", &c, &r);
    fscanf(fp, "%d", &mv);
    
    // Pula o último whitespace antes dos dados
    fgetc(fp); 

    Image *img = create_image(c, r, mv);
    img->tipo = tipo;

    switch(tipo){
        case 2:
            // puts("Lendo imagem PGM (dados em texto)");
            for (int i = 0; i < r; i++){
                for (int j = 0; j < c; j++) {
                    int val;
                    fscanf(fp, "%d", &val);
                    img->data[i][j] = (unsigned char)val;
                }
            }
        break;  
        case 5:
            // puts("Lendo imagem PGM (dados em binário)");
            for (int i = 0; i < r; i++){
                fread(img->data[i], sizeof(unsigned char), c, fp);
            }
        break;
        default:
            puts("Formato nao implementado");
            exit(3);
    }
    
    fclose(fp);
    return img;
}

// Lógica do seu writePGMImage adaptada
void save_pgm(Image *img, const char *filename){
    FILE *fp;

    if (!(fp = fopen(filename, "wb"))){
        perror("Erro ao salvar.");
        exit(1);
    }

    // Salva sempre como P5 (Binário) pois é mais eficiente
    fprintf(fp, "P5\n");
    fprintf(fp, "%d %d\n", img->width, img->height);
    fprintf(fp, "%d\n", 255);

    for (int i = 0; i < img->height; i++){
        fwrite(img->data[i], sizeof(unsigned char), img->width, fp);
    }

    fclose(fp);
}