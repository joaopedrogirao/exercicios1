#include <stdio.h>
int main(){
    int n;
    int quadrado = 0;
    for(n = 16; n<= 90; n += 4){
        quadrado = n * n;
        printf("%d\n", quadrado);
    }
return 0;
}