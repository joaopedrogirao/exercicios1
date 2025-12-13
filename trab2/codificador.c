#include <stdio.h>
#include <stdlib.h>
#include "pgm/pgm.h"

#define LIMIAR_DE_HOMOGENEIDADE 35.00

typedef struct node {
    unsigned char rowStart, rowEnd;
    unsigned char colStart, colEnd;
    unsigned char pMin, pMax;
    unsigned char split;
    double pAvg;
    struct node *upLeft, *upRight, *downLeft, *downRight;
} Node;

Node *treeChild(int rowStart, int rowEnd, int colStart, int colEnd, struct pgm *img) {
    Node *root = (Node *) malloc(sizeof(Node));
    
    root->rowStart = rowStart;
    root->rowEnd = rowEnd;
    root->colStart = colStart;
    root->colEnd = colEnd;
    
    double sum = 0, count = 0, diff = 0, variance = 0;
    root->pMax = 0; root->pMin = 255;

    for (int i = root->rowStart; i <= root->rowEnd; i++) {
        for (int j = root->colStart; j <= root->colEnd; j++) {
            unsigned char pixel = *(img->pData + i*img->c + j);
            if (root->pMax < pixel) root->pMax = pixel;
            else if (root->pMin > pixel) root->pMin = pixel;
            sum += pixel; count++;
        }
    }
    root->pAvg = sum/count;
    for (int i = root->rowStart; i <= root->rowEnd; i++) {
        for (int j = root->colStart; j <= root->colEnd; j++) {
            unsigned char pixel = *(img->pData + i*img->c + j);
            diff = pixel - root->pAvg;
            variance += diff * diff;
        }
    }
    root->split = variance/count < LIMIAR_DE_HOMOGENEIDADE? 0 : 1;
    root->upLeft = root->upRight = root->downLeft = root->downRight = NULL;

    return root;
}

Node *treeQuadSplit(Node *root, struct pgm *img) {    
    if (root == NULL) {
        printf("Gerando a árvore com limiar %.2f...\n", LIMIAR_DE_HOMOGENEIDADE);
        return treeQuadSplit(treeChild(0, img->r-1, 0, img->c-1, img), img);
    }
    else if ((root->rowStart+127 == root->rowEnd && root->colStart+127 == root->colEnd) || (root->split == 0)) {
        root->split = 0;
        return root;
    }
    else {
        int midRow = (root->rowStart + root->rowEnd) / 2;
        int midCol = (root->colStart + root->colEnd) / 2;

        root->upLeft = treeChild(root->rowStart, midRow, root->colStart, midCol, img);
        root->upRight = treeChild(root->rowStart, midRow, midCol+1, root->colEnd, img);
        root->downLeft = treeChild(midRow+1, root->rowEnd, root->colStart, midCol, img);
        root->downRight = treeChild(midRow+1, root->rowEnd, midCol+1, root->colEnd, img);

        treeQuadSplit(root->upLeft, img);
        treeQuadSplit(root->upRight, img);
        treeQuadSplit(root->downLeft, img);
        treeQuadSplit(root->downRight, img);

        return root;
    }
}

void treeFree(Node *root) {
    if(root != NULL) {
        treeFree(root->upLeft);
        treeFree(root->upRight);
        treeFree(root->downLeft);
        treeFree(root->downRight);
        free(root);
    }
}

void writeByte(FILE *file, unsigned char bit, unsigned char *buffer, int *count) {    
    *buffer = (*buffer << 1) | (bit & 1);
    (*count)++;

    if (*count == 8) {
        if (fwrite(buffer, 1, 1, file) != 1) {
            perror("Erro ao escrever o byte!");
            exit(1);
        }
        *count = 0;
        *buffer = 0;
    }
}

void completeByte(FILE *file, unsigned char *buffer, int *count) {
    if (*count > 0) {
        *buffer <<= (8 - *count);
        if (fwrite(buffer, 1, 1, file) != 1) {
            perror("Erro ao preencher o byte!");
            exit(1);
        }
        puts("Byte preenchido com sucesso!");
    }
}

void writeBytes(Node *root, FILE *file, struct pgm *img, unsigned char *buffer, int *count) {
    if (root == NULL) return;

    writeByte(file, root->split, buffer, count);
    
    if (root->split == 0) {
        unsigned char cor = root->pAvg;
        
        for (int i = 7; i >= 0; i--) {
            unsigned char bit = (cor >> i) & 1;
            writeByte(file, bit, buffer, count);
        }
        return;
    }

    writeBytes(root->upLeft, file, img, buffer, count);
    writeBytes(root->upRight, file, img, buffer, count);
    writeBytes(root->downLeft, file, img, buffer, count);
    writeBytes(root->downRight, file, img, buffer, count);
}

void writeBitstream(Node *root, char *fileName, struct pgm *img) {
    FILE *file = fopen(fileName, "wb");
    puts("Escrevendo o bitstream...");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    if (fwrite(&img->r, sizeof(int), 1, file) != 1 || fwrite(&img->c, sizeof(int), 1, file) != 1 || fwrite(&img->mv, sizeof(int), 1, file) != 1) {
        fclose(file);
        perror("Erro ao escrever cabeçalho da imagem!");
        exit(2);
    }
    
    unsigned char buffer = 0;
    int count = 0;

    writeBytes(root, file, img, &buffer, &count);
    completeByte(file, &buffer, &count);

    if (fclose(file) != 0) {
        perror("Erro ao fechar o arquivo!");
        exit(3);
    } else puts("Arquivo fechado com sucesso!");
    puts("Bitstream escrito com sucesso!");
}

void treePrint(Node *root) {
    if (root != NULL) {
        printf("%d ", root->split);
        treePrint(root->upLeft);
        treePrint(root->upRight);
        treePrint(root->downLeft);
        treePrint(root->downRight);
    }
}