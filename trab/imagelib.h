#ifndef IMAGELIB_H
#define IMAGELIB_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura adaptada do seu pgm.c para funcionar com a Quadtree
typedef struct {
    int tipo;       // 2 para P2, 5 para P5
    int width;      // c (colunas)
    int height;     // r (linhas)
    int max_val;    // mv
    unsigned char **data; // Matriz 2D (Necessário para a recursão da Quadtree)
} Image;

// Protótipos
Image* load_pgm(const char *filename);
void save_pgm(Image *img, const char *filename);
void free_image(Image *img);
Image* create_image(int w, int h, int max_val);

#endif
