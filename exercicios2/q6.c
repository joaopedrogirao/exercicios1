
#include <stdio.h>
int main(){
    int voto, vpaulo = 0, vrenata = 0, vbranco = 0, vnulo = 0;

    puts("Digite seu voto (5-Paulo, 7-Renata, 0-Branco): ");
    scanf("%d", &voto);

    while(voto >= 0){
        char confirma;
        puts("Confirma seu voto? (s/n)");
        scanf(" %c", &confirma);    
        
        if(confirma == 'n' || confirma == 'N'){
            puts("Voto cancelado.");
            puts("Digite seu voto (5-Paulo, 7-Renata, 0-Branco): ");
            scanf("%d", &voto);
            continue;
        }
        switch(voto){
            case 5:
            vpaulo++;
            break;

            case 7:
            vrenata++;
            break;          

            case 0:
            vbranco++;
            break;  
            
            default:
            vnulo++;        

        }
        
    puts("Digite seu voto (5-Paulo, 7-Renata, 0-Branco): ");
    scanf("%d", &voto); 


    }
printf("Votos Paulo: %d\n", vpaulo);
printf("Votos Renata: %d\n", vrenata);
printf("Votos em branco: %d\n", vbranco);
printf("Votos nulos: %d\n", vnulo); 

    return 0;   


}