#include <stdio.h>

void printBin(unsigned int n){
    for (int j = sizeof(n) * 8 - 1; j >= 0; j--) {
        printf("%d", (n >> j) & 1);
    }
}

int main(){

    
    for(int i = 1; i <= 256; i++){


    printf("Decimal:    %d\n", i);
    printf("Octal:      %o\n", i);
    printf("Hexadecimal:%x\n", i);
    printf("Binário: ");
    printBin(i);
    printf("\n");
       

        printf("\n");

    }

    return 0;

}