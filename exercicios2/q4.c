#include <stdio.h>
int main(){
    int jose = 150;
    int pedro = 110;
    int anos = 0;
    while (jose >= pedro){
        jose += 2;
        pedro += 3;
        anos++;
    }
    printf("Serão necessários %d anos para que Pedro seja maior que José.\n", anos);
    return 0;
}   