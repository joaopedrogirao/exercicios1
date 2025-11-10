#include <stdio.h>
int main(){

    
    for(int i = 1; i <= 10; i++){

    if (i % 2){
        unsigned long int fat = 1;
        
        for(int i2 = 1; i2 <= i; i2++){
            fat *= i2;
            
           
        }
    
    printf("O fatorial de %d é: %ld\n", i, fat);
    
    } 
}

}