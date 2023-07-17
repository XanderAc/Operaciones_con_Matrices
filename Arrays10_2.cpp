//(5.4.6) Un programa que use una matriz de 3x4 para resolver un sistema de 3 ecuaciones con 3 incógnitas usando el método de Gauss (hacer ceros por debajo de la diagonal principal para luego aplicar sustitución regresiva).
#include <iostream>
using namespace std;

void metododeGauss(double matriz [3][4]){
    for(int k=0;k<2;k++){
        for(int i=k+1; i<3; i++){
            float gauss = matriz[i][k] / matriz[k][k];
            for(int j=k;j<4;j++){
                matriz[i][j] = matriz[i][j] - (gauss * matriz[k][j]);
            }
        }
    }
}

double determinante(double matriz[3][4]){
    int det;
    det = matriz[0][0]*matriz[1][1]*matriz[2][2];
    return det;
}

void respuestas(double matriz[3][4]){
    float resultado[3];
    resultado[2] = matriz[2][3] / matriz[2][2];
    resultado[1] = (matriz[1][3] - (matriz[1][2]*resultado[2])) / matriz[1][1];
    resultado[0] = (matriz[0][3] - (matriz[0][2]*resultado[2]) - (matriz[0][1]*resultado[1])) / matriz[0][0];
    cout << " Los valores de las incognitas son: " << " x = " << resultado[0] << " , y = " << resultado[1] << " Y z = " << resultado[2];
}

void imprimirMatriz(double matriz[3][4]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main (){
    double matriz[3][4];
    int fila, columna, det;
    cout << " Ingrese los datos de la matriz a solucionar, la columna 4 es la columna de las constantes " << endl;
    for(fila = 0;fila<3; fila++){
        for ( columna = 0; columna < 4; columna++){
                cout << "dime el dato de la fila " << fila+1 << " y la columna " << columna+1 << ":";
                cin >> matriz[fila][columna];
            }
        }
    cout << " La matriz es: " << endl , imprimirMatriz(matriz);
    metododeGauss(matriz);
    cout << " La matriz escalonada es \n" , imprimirMatriz(matriz);
    det = determinante(matriz);
    cout << " El determinante es: " << det << endl;
    if (det == 0){
        cout << " El sistema de ecuaciones no tiene solucion " << endl;
    }else{
        respuestas(matriz);
    }
    return 0;
}