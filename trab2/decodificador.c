#include <stdio.h>
#include <stdlib.h>
#include "pgm.h"

void readBitstream(FILE *bitstm, struct pgm *p);
void fileAlocation(struct pgm *p);
FILE* openBitstream(const char *file);
unsigned char readbit(FILE *bitstm, unsigned char *buffer,int *bitsrestantes);
unsigned char readcolorformbits(FILE *bitstm, unsigned char *buffer, int *bitsrestantes);
void decoder(FILE *bitstm, struct pgm *img, int rowStart,int rowEnd,int colStart, int colEnd,unsigned char *buffer, int *bitsrestantes);


int main(int argc, char *argv[]){

    if (argc != 3)
    {
        printf("uso: %s <entrada.bin> <saida.pgm>\n", argv[0]);
        exit(1);
    }

    FILE *bitstm = openBitstream(argv[1]);

    struct pgm img;

    readBitstream(bitstm, &img);

    fileAlocation(&img);

    if (!img.pData)
    {
        printf("Erro de alocação de memoria na reconstrução da imagem.\n");
        fclose(bitstm);
        exit(6);
    }

    unsigned char buffer = 0;
    int bitsrestantes = 0;

    decoder(bitstm, &img, 0,img.r - 1, 0, img.c -1, &buffer, &bitsrestantes);


    fclose(bitstm);

    writePGMImage(&img, argv[2]);

    free(img.pData);


    return 0;
}

unsigned char readbit(FILE *bitstm, unsigned char *buffer,int *bitsrestantes){
    if (*bitsrestantes == 0)
    {
        if (fread(buffer,1,1,bitstm) != 1)
        {
            printf("erro ao ler byte do bitstream\n");
            exit(10);

        }
        *bitsrestantes = 8;
        
    }

    unsigned char bit = (*buffer >> 7) & 1;

    *buffer <<= 1;
    (*bitsrestantes)--;

    return bit;
    
}

unsigned char readcolorformbits(FILE *bitstm, unsigned char *buffer, int *bitsrestantes){
    unsigned char vmedio = 0;
    for (int i = 7; i >= 0; i--)
    {
        unsigned bit = readbit(bitstm,buffer,bitsrestantes);
        vmedio |= (bit << i);

    }

    return vmedio;
    
}


void decoder(FILE *bitstm, struct pgm *img, int rowStart,int rowEnd,int colStart, int colEnd,unsigned char *buffer, int *bitsrestantes){

    unsigned char flag = readbit(bitstm,buffer,bitsrestantes);

    if (flag == 0)
    {
        unsigned char vmedio = readcolorformbits(bitstm,buffer,bitsrestantes);

        for (int i = rowStart; i <= rowEnd; i++)
        {
            for (int j = colStart; j <= colEnd; j++)
            {
                img->pData[i * img->c  + j] = vmedio; 
            }
            
        }
        
        
    }
    else{
        int midrow = (rowStart + rowEnd)/2;
        int midcol = (colStart + colEnd)/2;

        decoder(bitstm, img,rowStart,midrow,colStart,midcol,buffer,bitsrestantes);

        decoder(bitstm,img,rowStart,midrow,midcol+1,colEnd,buffer,bitsrestantes);

        decoder(bitstm,img,midrow+1,rowEnd,colStart,midcol,buffer,bitsrestantes);

        decoder(bitstm,img,midrow+1,rowEnd,midcol+1,colEnd,buffer,bitsrestantes);

    }


}

void readBitstream(FILE *bitstm, struct pgm *p){

    if (fread(&p->r, sizeof(int), 1, bitstm) != 1)
    {
        printf("Erro ao ler linhas.\n");
        fclose(bitstm);
        exit(3);
    }

    if (fread(&p->c, sizeof(int), 1, bitstm) != 1)
    {
        printf("Erro ao ler colunas.\n");
        fclose(bitstm);
        exit(4);
    }

    if (fread(&p->mv, sizeof(int), 1, bitstm) != 1)
    {
        printf("Erro ao ler maxvalue.\n");
        fclose(bitstm);
        exit(5);
    }

}

void fileAlocation(struct pgm *p){

    int totaldepixels = p->c * p->r;

    p->pData = (unsigned char*)malloc(totaldepixels * sizeof(unsigned char));

}

FILE* openBitstream(const char *file){
    FILE *fp;
    
    fp = fopen(file,"rb");

    if (!fp)
    {
        printf("Erro ao abrir arquivo de entrada %s\n", file);
        exit(2);
    }

    return fp;

}