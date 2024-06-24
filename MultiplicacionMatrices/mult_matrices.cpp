#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

void multiplicar_matrices(int N1,int N2,int M1,int M2) {
    ofstream archivo1("matrizA.csv");
    ofstream archivo2("matrizB.csv");
    ofstream archivo("matriz_cpp.csv");
    double suma=0.0;
    double A[N1][M1];
    double B[N2][M2];
    double C[N1][M2];
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

    
    /* /*multiplicacion*/

    for(int j=0;j<M2;j++){
        for(int k=0;k<N1;k++){
            suma=0.0;
            for(int l=0;l<M1;l++){
                suma+=A[k][l]*B[l][j];
            }
            C[k][j]=suma;
        }
    }
    for(int j=0;j<N1;j++){
        for(int k=0;k<N2;k++){
            archivo1 << A[j][k]<< ' ';
        }
        archivo1 << "\n";
    }
    for(int j=0;j<M1;j++){
        for(int k=0;k<M2;k++){
            archivo2 << B[j][k]<< ' ';
        }
        archivo2 << "\n";
    } 
    for(int j=0;j<N1;j++){
        for(int k=0;k<M2;k++){
            archivo << C[j][k];
            if(k<M2-1) {
                archivo << ", ";
            }
        }
        archivo << "\n";
    }
}
int main(){
    
    /* int N1=250,M1=250,N2=250,M2=250; */
    int N1=0,M1=0,N2=0,M2=0;
    int i=0;
    
    srand(time(NULL)); 
    

    while(i!=1){
        cout << "Ingrese la cantidad de filas y columnas de la matriz 1:\n ";
        cin >> N1;
        cin >> N2;
        cout <<"Ingrese la cantidad de filas y columnas de la matriz 2:\n ";
        cin >> M1;
        cin >> M2;
        try {
            if(M1==N2) {
                i=1;
            }
            else{
                throw std::runtime_error("\nLas matrices no pueden ser multiplicadas. Vuelva a ingresar las dimensiones\n");
            }
        }
        catch (const exception e) {
            cerr << e.what();
        }
    } 
    //* *generar las matrices aleatoriamente
    multiplicar_matrices(N1,N2,M1,M2);
    cout  << "Resultado de la multiplicacion guardada en el archivo";
    return 0;
}