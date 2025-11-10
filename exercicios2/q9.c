#include <stdio.h>
int main(){
    int pt = 1, st = 1;

    printf("%d\n", pt);
    printf("%d\n", st);     

    for (int i = 3; i <= 20; i++){
        int t = pt + st;
        printf("%d\n", t);
        pt = st;
        st = t; 
    }

return 0;  
    }   