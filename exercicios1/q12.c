#include <stdio.h>

int main(){

    int a;
    int b;
    int c;
    puts("Digite um valor para a primeira variável: ");
    scanf("%d", &a);

    puts("Digite um valor para a segunda variável: ");
    scanf("%d", &b);

    
    c = a;
    a = b;
    b = c;  
    
    printf("%d, %d\n", a, b);


    return 0;

}