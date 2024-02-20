#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}


int main() {
    char operador;
    double num1, num2;
    bool programa = true;



    cout << "Calculadora en C++, hecha por Juan Pablo Sanchez Nieto - Ing. Software - Materia Logica de Programacion I \n" << endl;
    cout << "Uso del programa: " <<endl;
    cout << "En la siguiente tabla se encuentran los operadores disponibles: \n" <<endl;
    cout << "|     Suma       | + |"<<endl;
    cout << "|     Resta      | - |"<<endl;
    cout << "| Multiplicacion | * |"<<endl;
    cout << "|    Division    | / |"<<endl;
    cout << "|     Modulo     | % |"<<endl;
    cout << "|   Factorial    | + |"<<endl;
    cout << "|  Potenciacion  | + | \n"<<endl;
    cout << "Para salir del programa, escribe 'e' \n"<<endl;

    while (programa){

    cout << "Ingrese un operador (+, -, *, /, %, !, ^): \n";
    cin >> operador;

    if (operador == 'E' || operador == 'e') {
            programa = false;
            continue;  // Salir del bucle
        }

    switch (operador) {

        case '+':
            cout << "Ingrese los sumandos: ";
            cin >> num1 >> num2;
            cout << "Resultado: " << num1 + num2 << endl;
            break;

        case '-':
            cout << "Ingrese minuendo y sustraendo: ";
            cin >> num1 >> num2;
            cout << "Resultado: " << num1 - num2 << endl;
            break;

        case '*':
            cout << "Ingrese los factores: ";
            cin >> num1 >> num2;
            cout << "Resultado: " << num1 * num2 << endl;
            break;

        case '/':
            cout << "Ingrese dividendo y divisor: ";
            cin >> num1 >> num2;
            if (num2 != 0) {
                cout << "Resultado: " << num1 / num2 << endl;
            } else {
                cout << "Error: No se puede dividir por cero." << endl;
            }
            break;

        case '%':
            cout << "Ingrese dividendo y cociente";
            cin >> num1 >> num2;
            if (num2 == 0){

                cout << "No se puede calcular el modulo entre cero.\n";
            }
            else {
                cout << "Resultado: " << fmod(num1, num2) << endl;
            }
            break;

        case '!':
            cout << "Ingrese el numero a factorizar";
            cin >> num1;
            if (num1 >= 0) {
                cout << "Resultado (factorial): " << factorial(static_cast<int>(num1)) << endl;
            } else {
                cout << "Error: No se puede calcular el factorial de un número negativo." << endl;
            }
            break;

        case '^':
            cout << "Ingrese la base y el exponente: ";
            cin >> num1 >> num2;
            cout << "Resultado (potenciacion): " << pow(num1, num2) << endl;
            break;

        default:
            cout << "Error: Operador no válido." << endl;

    }
}

    cout << "Programa finalizado." << endl;
    return 0;

}
