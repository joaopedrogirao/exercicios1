#include "imagelib.h"

// Defina o limiar de erro. Quanto maior, mais compressão e menos qualidade.
#define THRESHOLD 15 

// Verifica se uma região é homogênea
// Retorna 1 (Sim) ou 0 (Não)
int is_homogeneous(Image *img, int x, int y, int w, int h) {
    unsigned char min = 255, max = 0;
    
    for(int i = y; i < y + h; i++) {
        for(int j = x; j < x + w; j++) {
            unsigned char val = img->data[i][j];
            if (val < min) min = val;
            if (val > max) max = val;
        }
    }
    // Se a diferença entre o mais claro e o mais escuro for pequena, é homogêneo
    return (max - min) <= THRESHOLD;
}

// Calcula a cor média da região para salvar
unsigned char get_average_color(Image *img, int x, int y, int w, int h) {
    long sum = 0;
    long count = 0;
    for(int i = y; i < y + h; i++) {
        for(int j = x; j < x + w; j++) {
            sum += img->data[i][j];
            count++;
        }
    }
    return (unsigned char)(sum / count);
}

// Função Recursiva de Compressão (Gera o Bitstream)
// Protocolo: 0 = Nó dividido (Split), 1 = Nó folha (Leaf) + Cor
void compress_quadtree(Image *img, int x, int y, int w, int h, FILE *out) {
    // Critério de parada base: 1 pixel
    if (w <= 1 || h <= 1) {
        fputc(1, out); // É folha
        fputc(img->data[y][x], out); // Salva cor
        return;
    }

    if (is_homogeneous(img, x, y, w, h)) {
        fputc(1, out); // É folha
        fputc(get_average_color(img, x, y, w, h), out); // Salva cor média
    } else {
        fputc(0, out); // Não é folha, DIVIDIR
        
        int halfW = w / 2;
        int halfH = h / 2;
        
        // Ajuste para dimensões ímpares
        int nextW = w - halfW; 
        int nextH = h - halfH;

        // Recursão para os 4 quadrantes (NW, NE, SW, SE)
        compress_quadtree(img, x, y, halfW, halfH, out);             // NW
        compress_quadtree(img, x + halfW, y, nextW, halfH, out);     // NE
        compress_quadtree(img, x, y + halfH, halfW, nextH, out);     // SW
        compress_quadtree(img, x + halfW, y + halfH, nextW, nextH, out); // SE
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <imagem_entrada.pgm>\n", argv[0]);
        return 1;
    }

    printf("Carregando imagem...\n");
    Image *img = load_pgm(argv[1]);

    FILE *out = fopen("bitstream.bin", "wb");
    if (!out) return 1;

    // Salva dimensões no início do arquivo comprimido para o decodificador saber
    fwrite(&img->width, sizeof(int), 1, out);
    fwrite(&img->height, sizeof(int), 1, out);
    fwrite(&img->max_val, sizeof(int), 1, out);

    printf("Comprimindo...\n");
    compress_quadtree(img, 0, 0, img->width, img->height, out);


    // ... código de compressão anterior ...

    // Move o cursor para o fim do arquivo para medir o tamanho
    fseek(out, 0, SEEK_END);
    long fileSize = ftell(out);
    printf("Tamanho do Bitstream: %ld bytes\n", fileSize);

    // Opcional: Calcular a taxa de compressão na hora
    // Tamanho original = Largura * Altura (para PGM P5 8-bit)
    long originalSize = img->width * img->height;
    double ratio = (1.0 - ((double)fileSize / originalSize)) * 100.0;
    printf("Taxa de Compressao: %.2f%%\n", ratio);

    // ...
    fclose(out);
    free_image(img);
    printf("Compressao concluida! Arquivo: bitstream.bin\n");

    return 0;
}