#include <stdio.h>
int main(){

   unsigned long long p1 = 1; 
   unsigned long long p2 = 1;
    
    for (int i = 1; i <= 64; i++){

        printf("Quantidade de grãos no %d° espaço: %llu\n", i, p2);
        p1 *= 2;
        p2 += p1;
        
        
    }



    return 0;


}