#include <stdio.h>
int main(){
    unsigned char X = 90;
    unsigned char Y = 10;
    
    unsigned char data[20];
    int k;
    for(k=0; k<20; k++) {
        data[k] = 100;
    }
    
    int indices_alvo[8] = {Y-4, Y-3, Y-2, Y-1, Y+1, Y+2, Y+3, Y+4};
    int i;
    
    printf("Escondendo bits de X (0101 1010)\n");
    
    for (i = 0; i < 8; i++) {
        
        int bit_de_X = (X >> (7 - i)) & 1;
        
        int indice_atual = indices_alvo[i];
        unsigned char valor_original = data[indice_atual];

        unsigned char valor_modificado = (valor_original & ~1) | bit_de_X;

        data[indice_atual] = valor_modificado;
        
        printf("Escondeu bit %d (%d) em data[%d]. Novo valor: %u\n", (7-i), bit_de_X, indice_atual, valor_modificado);
    }
    
    printf("\nVerificando os LSBs em 'data'\n");
    
    unsigned char bits_recuperados = 0;
    
    for (i = 0; i < 8; i++) {
        int indice_atual = indices_alvo[i];
        
        int lsb = data[indice_atual] & 1;
        
        if (lsb == 1) {
            bits_recuperados = bits_recuperados | (1 << (7 - i));
        }
    }
    
    printf("Bits recuperados: %u (Deveria ser %u)\n", bits_recuperados, X);

    return 0;
}