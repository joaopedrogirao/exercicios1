#include <stdio.h>
int main(){
int c, f;
    for(int i = 10; i <= 100; i += 10){

        c = i;
        f = (c * 1.8) + 32;

        printf("Temperatura em Celsius: %d\nTemperatura em Fahrenheit: %d\n", c, f);

}

return 0;


}