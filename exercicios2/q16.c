#include <stdio.h>
int main() {
    int p1 = 0;
    int p2 = 100;
    int p3 = 200;    
    int somat = 0;
    int somac = 0;
   
    for (int i = p1; i <= p3; i++) {
        if ((i % 3 == 0) && (i <= 100)) {
                somat += i;
            
        }else if((i % 5 == 0) && (i >= 100)){
                somac += i;


        }
    }
    printf("\nQuantidade de números divisíveis por 3 no intervalo de %d a %d:\n", p1, p2);
    printf("%d\n", somat);
    printf("\nQuantidade de números divisíveis por 5 no intervalo de %d a %d:\n", p2, p3);
    printf("%d\n", somac);
    return 0;
}
