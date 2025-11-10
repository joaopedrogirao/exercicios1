#include <stdio.h>

int main() {
    
    int limite = 500;
    int contadortriplas = 0;

    printf("Triplas de Pitágoras com lados até %d:\n\n", limite);

    for (int cateto1 = 1; cateto1 <= limite; cateto1++) {

        for (int cateto2 = cateto1; cateto2 <= limite; cateto2++) {

            for (int hipotenusa = cateto2 + 1; hipotenusa <= limite; hipotenusa++) {

                if ( (cateto1 * cateto1) + (cateto2 * cateto2) == (hipotenusa * hipotenusa) ) {
                    
                    printf("Tripla encontrada: (%d, %d, %d)\n", cateto1, cateto2, hipotenusa);
                    contadortriplas++;
                }
            }
        }
    }

    printf("\nTriplas encontradas: %d\n", contadortriplas);

    return 0;
}