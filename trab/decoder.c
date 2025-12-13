#include "imagelib.h"

// Preenche uma região da imagem com uma cor sólida
void fill_region(Image *img, int x, int y, int w, int h, unsigned char color) {
    for(int i = y; i < y + h; i++) {
        for(int j = x; j < x + w; j++) {
            img->data[i][j] = color;
        }
    }
}

// Função Recursiva de Reconstrução
void decompress_quadtree(Image *img, int x, int y, int w, int h, FILE *in) {
    int tag = fgetc(in); // Lê o marcador (0 ou 1)

    if (tag == 1) { // É Folha (Região Homogênea)
        int color = fgetc(in); // Lê a cor
        fill_region(img, x, y, w, h, (unsigned char)color);
    } 
    else if (tag == 0) { // É Nó Interno (Divisão)
        int halfW = w / 2;
        int halfH = h / 2;
        int nextW = w - halfW;
        int nextH = h - halfH;

        // Reconstrói na mesma ordem da compressão: NW, NE, SW, SE
        decompress_quadtree(img, x, y, halfW, halfH, in);
        decompress_quadtree(img, x + halfW, y, nextW, halfH, in);
        decompress_quadtree(img, x, y + halfH, halfW, nextH, in);
        decompress_quadtree(img, x + halfW, y + halfH, nextW, nextH, in);
    }
}

int main() {
    FILE *in = fopen("bitstream.bin", "rb");
    if (!in) {
        printf("Arquivo bitstream.bin nao encontrado.\n");
        return 1;
    }

    int w, h, max;
    // Lê o cabeçalho do arquivo binário
    fread(&w, sizeof(int), 1, in);
    fread(&h, sizeof(int), 1, in);
    fread(&max, sizeof(int), 1, in);

    printf("Reconstruindo imagem %dx%d...\n", w, h);
    Image *img = create_image(w, h, max);

    decompress_quadtree(img, 0, 0, w, h, in);

    save_pgm(img, "imagem_reconstruida.pgm");

    fclose(in);
    free_image(img);
    printf("Imagem reconstruida salva como 'imagem_reconstruida.pgm'\n");

    return 0;
}