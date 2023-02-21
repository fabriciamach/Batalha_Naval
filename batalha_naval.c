	
//Batalha Naval

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIMENSAO 11




void fazerM(int matriz[][DIMENSAO]){

    int l, c, L, C;
    srand(time(NULL));
    
        for (l = 0; l < 11; l++){
            if(l == 0){

                for (c = 0; c < 11; c++){
                    if (c==0){
                    matriz[l][c] = 0;
                    
                    }else{
                    matriz[l][c] = c;
                    }
                }

            }else{



                for (c = 0; c < 11; c++){



                    if (c == 0){



                    matriz[l][c] = l;



                    }else{



                    matriz[l][c] = 3;



                    }

                }

            }
        }

    //fazendo barco 4

    L = 1 + ( rand() % 10 );
    C = 1 + ( rand() % 10 );

    if(L >= 7){
        L = L - 4;
    }
    
    for(int i = 0; i < 4; i++){
    matriz[L][C] = 2;
    L++;
    }

    //Fazendo 2 X barco 3

    for(int j = 0; j < 2; j++){
    L = 1 + ( rand() % 10 );
    C = 1 + ( rand() % 10 );
    
     if(C >= 8){
      C = C - 3;
     }

    for(int i = 0; i < 2; i++){

      if(matriz[L][C] == 2 || matriz[L][C+1] == 2 || matriz[L][C+2] == 2 ){
      L = 1 + ( rand() % 10 );
      C = 1 + ( rand() % 10 );
    
      if(C >= 8){
      C = C - 3;
      }

      i = 0;
      }

    }
    
    for(int i = 0; i < 3; i++){
    matriz[L][C] = 2;
    C++;
    }
    
    }

    //Fazendo barco 2

    L = 1 + ( rand() % 10 );
    C = 1 + ( rand() % 10 );
    
    if(L >= 9){
    L = L - 2;
    }

    for(int i = 0; i < 2; i++){

      if(matriz[L][C] == 2 || matriz[L+1][C] == 2){
      L = 1 + ( rand() % 10 );
      C = 1 + ( rand() % 10 );
      
        if(L >= 9){
        L = L - 2;
        }
        
      i = 0;
      }
    }

    for(int i = 0; i < 2; i++){
    matriz[L][C] = 2;
    C++;
    }

    //Fazendo 5 X barco 1

    for(int j = 0; j < 5; j++){
    L = 1 + ( rand() % 10 );
    C = 1 + ( rand() % 10 );

    for(int i = 0; i < 2; i++){
    
      if(matriz[L][C] == 2){
      L = 1 + ( rand() % 10 );
      C = 1 + ( rand() % 10 );
      i = 0;
      }
    }

    for(int i = 0; i < 3; i++){
    matriz[L][C] = 2;
    }
    }
}

void imprimeM (int matriz[][DIMENSAO]){

    int l, c;
        for (l = 0; l < 11; l++){
        
            for (c = 0; c < 11; c++){
            
                if(c == 0 && l == 0){
                 printf("  \t");
                }else{
                
                    if(l == 0 || c == 0){
                    printf("\t%i", matriz[l][c]);
                    }else{
                    
                        if(matriz[l][c] == 1){
                        printf("\to");
                        }else{

                            if(matriz[l][c] == 4){
                            printf("\tx");
                            }else{
                            printf("\t~");
                            }
                        }
                    }
                }
             }

            printf("\n");

            if(l == 0){
                printf("\n");
            }
       }
}

void imprimeresultado (int matriz[][DIMENSAO]){

    int l, c;
    
        for (l = 0; l < 11; l++){
        
            for (c = 0; c < 11; c++){

                if(c == 0 && l == 0){
                 printf("  \t");
                }else{

                    if(l == 0 || c == 0){
                    printf("\t%i", matriz[l][c]);
                    }else{

                        if(matriz[l][c] == 1){
                        printf("\to");
                        }else{
                        
                            if(matriz[l][c] == 4){
                            printf("\tx");
                            }else{

                                if( matriz[l][c] == 2){
                                printf("\tw");
                                }else{
                                printf("\t~");
                                }
                            }
                        }
                    }
                }
            }
            
            printf("\n");

            if(l == 0){
                printf("\n");
            }
       }
}

int atirandoemM (int matriz[][DIMENSAO], int l, int c, int acertos){

    if(matriz[l][c] == 2){
        matriz[l][c] = 4;
        acertos = acertos + 1;
    }else{
    
        if(matriz[l][c] == 4){
        matriz[l][c] = 4;
        }else{
        matriz[l][c] = 1;
        }
    }

    return acertos;
}


void resultadodojogo(int tiros, int acertos){

    if(tiros == 0){
        printf("O jogador perdeu o jogo, acabou com todos os tiros..., acertou %i barcos", acertos);
    }else{
        printf("Parabens!! O jogador venceu o jogo");
    }
}



int main(){

    int M[DIMENSAO][DIMENSAO], l, c, tiros, acertos;
    tiros = 25;
    acertos = 0;

    while(tiros > 0 && acertos < 17){
    printf("\t\t\t\t\tBatalha Naval:\n\n");

        if(tiros == 25){
        fazerM(M);
        imprimeM(M);
        printf("Tiros: %i\n", tiros);
        printf("Escolha uma linha:\n");
        scanf("%d",&l);
        printf("Escolha uma coluna:");
        scanf("%d",&c);
        acertos = atirandoemM(M,l,c, acertos);
        system("cls");
        tiros--;
        
        }else{
        imprimeM(M);
        printf("Tiros: %i\n", tiros);
        printf("Escolha uma linha:\n");
        scanf("%d",&l);
        printf("Escolha uma coluna:");
        scanf("%d",&c);
        acertos = atirandoemM(M,l,c, acertos);
        system("cls");
        tiros--;
        }
    }

    printf("\t\t\t\t\tBatalha Naval:\n\n");
    imprimeresultado(M);
    resultadodojogo(tiros, acertos);
    return 0;
}
