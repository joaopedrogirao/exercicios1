#include <stdio.h>

int main(){

int n;
int menor;

int *pn = &n;
int *pm = &menor;
    
puts("Digite um número:");
    scanf("%d", pn);
    if(*pn == 0) return 0;

    *pm = *pn;
while(1){
     

    puts("Digite um número:");
    scanf("%d", pn);

    if (*pn == 0){
        break;
    }else if(*pn < *pm){
        *pm = *pn;
    }
    


}

printf("O menor número é:%d", *pm);
return 0;
}