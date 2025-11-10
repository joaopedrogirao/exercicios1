#include <stdio.h>
int main(){
    int n;
    
    puts("Digite um número para gerar a tabuada:");
    scanf("%d", &n);
    int a;
    a = n;
    for(int i = 1; i <= 10; i++){
        a = n * i;


    printf("%d X %d = %d\n",n, i, a);


    }
    
    
}