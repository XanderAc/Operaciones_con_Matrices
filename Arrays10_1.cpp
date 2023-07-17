#include <iostream>
using namespace std;
/*(5.4.5) Un programa que pida al usuario los datos de dos matrices de 2x2, y calcule y muestre su producto.*/
void multiplicarMatrices2x2(double matriz[2][2][2], double matriz_r[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                matriz_r[i][j] += matriz[0][i][k] * matriz[1][k][j];
            }
        }
    }
}

void imprimirMatriz(double matriz[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    cout << " Multiplicacion de matrices " << endl;
    double matriz[2][2][2], matriz_r[2][2];
    int m, fila,columna;
    cout << " Ingrese los datos de las matrices " << endl;
    for(m=0; m<2; m++){
        for(fila = 0;fila<2; fila++){
            for ( columna = 0; columna < 2; columna++)
            {
                cout << "En la matriz " << m+1
                    << ", dime el dato de la fila" << fila+1
                    << "y la columna " << columna+1 << ":";
                    cin >> matriz[m][fila][columna];
            }
            
        }
    }
    multiplicarMatrices2x2(matriz,matriz_r);
    cout << " El resultado es : " << endl , imprimirMatriz(matriz_r);
    return 0;
}
