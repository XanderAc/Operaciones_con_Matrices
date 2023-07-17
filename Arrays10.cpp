#include <iostream>
using namespace std;
/*(5.4.4) Un programa que pida al usuario los datos de una matriz de 3x3, y calcule y muestre su matriz inversa*/

double determinante(float matriz[3][3]){
    int det;
    det = (matriz[0][0]*matriz[1][1]*matriz[2][2] + matriz[0][1]*matriz[1][2]*matriz[2][0] + matriz[0][2]*matriz[1][0]*matriz[2][1]) - (matriz[0][2]*matriz[1][1]*matriz[2][0]+ matriz[0][0]*matriz[1][2]*matriz[2][1]+matriz[0][1]*matriz[1][0]*matriz[2][2]);
    return det;
}

double calcularDeterminante2x2(double a, double b, double c, double d) {
    return a * d - b * c;
}

float calcularCofactor(float matriz[3][3], int fila, int columna) {
    int signo = (fila + columna) % 2 == 0 ? 1 : -1;
    double submatriz[2][2];
    int contador = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i != fila && j != columna) {
                submatriz[contador / 2][contador % 2] = matriz[i][j];
                ++contador;
            }
        }
    }

    return signo * calcularDeterminante2x2(submatriz[0][0], submatriz[0][1], submatriz[1][0], submatriz[1][1]);
}

void calcularMatrizAdjunta(float matriz[3][3], float matriz_a[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matriz_a[j][i] = calcularCofactor(matriz, i, j);
        }
    }
}

void imprimirMatriz(float matriz[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    float matriz [3][3] , matriz_a [3][3], det, matriz_i[3][3]; 
    int fila, columna;
    cout << " Ingrese los datos de la matriz " << endl;
    for (fila = 0; fila <3 ; fila++){
        for(columna = 0; columna < 3; columna++){
            cout << " Ingrese el numero de la fila " << fila+1 << " y la columna " << columna+1 << " : " ;
            cin >> matriz[fila][columna];
        }
    }
    cout << " La matriz  es: "<< endl;
    for(fila=0;fila<3;fila++){
        for(columna=0;columna<3;columna++){
            cout << matriz[fila][columna] << " ";
        }
        cout << endl;
    }
    det = determinante(matriz);
    calcularMatrizAdjunta(matriz, matriz_a);
    cout << "El determinante es: " << det << endl;
    if(det == 0){
        cout << " La matriz ingresada no tiene matriz inversa ";
    }else{
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                matriz_i[i][j] = matriz_a[i][j] / det;
                }
        }
        cout << " La matriz inversa es: " , imprimirMatriz(matriz_i);
    }
    return 0;
}

