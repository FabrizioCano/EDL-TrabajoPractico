#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void multiplicar_matriz(int N1,int N2,int M1,int M2,double A[N1][M1],double B [N2][M2],double C[N1][M2]){
    double suma=0.0;
    for(int j=0;j<N1;j++){
        for(int k=0;k<M1;k++){
           /*  A[j][k]= rand() % (500000-10000)+10000; */
            A[j][k]= rand() % (20-15)+10;
        }
    }
    for(int j=0;j<N2;j++){
        for(int k=0;k<M2;k++){
            /*  B[j][k]= rand() % (500000-10000)+10000; */
            B[j][k]= rand() % (20-15)+10;
        }
    }

    /*multiplicacion*/

    for(int j=0;j<M2;j++){
        for(int k=0;k<N1;k++){
            suma=0.0;
            for(int l=0;l<M1;l++){
                suma+=A[k][l]*B[l][j];
            }
            C[k][j]=suma;
        }
    }
}

void guardar_archivo(int n, int m, double matriz[n][m],FILE *arch) {
    for(int j=0;j<n;j++){
        for(int k=0;k<m;k++){
            fprintf(arch,"%lf",matriz[j][k]);
            if(k<m-1){
                fprintf(arch,", ");
            }
        }
        fprintf(arch,"\n");
    }
}


int main(){
    /* int N1=250,M1=250,N2=250,M2=250; */
    int N1=0,M1=0,N2=0,M2=0;
    int i=0;
    FILE *mat1=fopen("matriz_A.csv","w");
    FILE *mat2=fopen("matriz_B.csv","w");
    FILE *archivo=fopen("matriz_c.csv","w");
    srand(time(NULL)); 
    while(i!=1){
        printf("Ingrese la cantidad de filas y columnas de la matriz 1:\n ");
        scanf("%d %d",&N1,&M1);
        printf("Ingrese la cantidad de filas y columnas de la matriz 2:\n ");
        scanf("%d %d",&N2,&M2);
        if(M1==N2) {
            i=1;
        }
        else{
            printf("Las matrices no pueden ser multiplicadas. Vuelva a ingresar las dimensiones\n");
        }
    }
    /*generar las matrices aleatoriamente*/
    double A[N1][M1];
    double B[N2][M2];
    double C[N1][M2];
    multiplicar_matriz(N1,M1,N2,M2,A,B,C);
    guardar_archivo(N1,M1,A,mat1);
    guardar_archivo(N2,M2,B,mat2);
    guardar_archivo(N1,M2,C,archivo);
    
    printf("Resultado de la multiplicacion guardada en el archivo");
    return 0;
}