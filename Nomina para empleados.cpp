#include <iostream>

using namespace std;

    // Definicion de constantes
    const int salario_mecanico = 3000000;

    const int salario_supervisor = 5000000;

    const double valor_hora_mecanico = 18750;

    const double valor_hora_supervisor = 31250;

    const float dia_vacaciones = 1.25;



    // Definicion de variables

    long pago_base;

    long descuentos;

    int accion;

    string cargo;

    int contador;

    int acumulado_horas;

    int horas_trabajadas = 0;

    int mes_ingreso; int mes_actual = 11; int mes;

    int anio_ingreso; int anio_actual = 23; int anio;

    float descanso;


void consulta_salario(){

     cout << "Consultar salario base \n";

        if (cargo == "mecanico"){

            cout << "Su salario es: " << salario_mecanico << "\n";

        }else if (cargo == "supervisor"){

            cout << "Su salario es: \n" << salario_supervisor << "\n";

        }

}

void horas(){

    if (contador < 4){

        cout << "Ingresar horas trabajadas \n";

        cout << "Ingrese las horas que ha trabajado: \n";

        cin >> horas_trabajadas;

        if (horas_trabajadas > 40 && cargo == "mecanico"){

            cout << "No se puede trabajar más de lo estimado, registre nuevamente \n";

            return;

        }else if (horas_trabajadas > 35 && cargo == "supervisor"){

            cout << "No se puede trabajar más de lo estimado, registre nuevamente \n";

            return;

        }else {

            acumulado_horas = horas_trabajadas + acumulado_horas;

            contador++;

        }

    }else if (contador == 4){

        cout << "No se permiten mas registros, las horas que trabajó son: \n" << acumulado_horas;

    }

}

void trabajado(){

    cout << "Consultar horas trabajadas: \n";

            if (cargo == "mecanico"){               // Horas trabajadas mecanico

                if (acumulado_horas == 160){

                    cout << "Ha trabajado las horas requeridas por mes \n";

            }else if (acumulado_horas < 160 && contador < 4) {

                cout << "Aun faltan " << 160-acumulado_horas << " horas para completar lo requerido \n";

            }else if (acumulado_horas < 160 && contador == 4){

                cout << "Faltaron " << 160-acumulado_horas << " horas para completar lo requerido \n";

                }
            }

            if (cargo == "supervisor"){             // Horas trabajadas supervisor

                if (acumulado_horas == 140){

                    cout << "Ha trabajado las horas requeridas por mes \n";

            }else if (acumulado_horas < 140 && contador < 4) {

                cout << "Aun faltan " << 140-acumulado_horas << " horas para completar lo requerido \n";

            }else if (acumulado_horas < 140 && contador == 4){

                cout << "Faltaron " << 140-acumulado_horas << " horas para completar lo requerido \n";

                }

            }
}

void vacaciones(){

    cout << "Consultar vacaciones acumuladas: \n";

    cout << "¿Desde que fecha trabaja en la empresa? \n";

    cin >> mes_ingreso >> anio_ingreso;

    cout << "Trabajas desde el  " << mes_ingreso << "/" << anio_ingreso << "\n ";

        anio = anio_actual - anio_ingreso;          // Diferencia de año actual con año de ingreso
        mes = mes_actual - mes_ingreso;             // Diferencia de mes actual con mes de ingreso

        if (anio_ingreso < 21){

            cout << "Fecha no valida. \n";
            return;

        }

        if (mes_ingreso > 12){

            cout << "Fecha no valida. \n";          // año menor a 21 no es valido

        }

        if (anio == 1 && mes_ingreso == mes_actual){            // Cuando el tiempo es de 1 año exacto

            descanso = dia_vacaciones * 12;
            cout << "Llevas " << descanso << " dias acumulados \n";

        }else if (anio == 2 && mes_ingreso == mes_actual){      // Cuando el tiempo es de 2 años exactos

            descanso = dia_vacaciones * 24;
            cout << "Lleva " << descanso << " dias acumulados \n";

        }else if (anio == 1 && mes_actual > mes_ingreso){       // Cuando lleva de 13 a 22 meses trabajando

            descanso = dia_vacaciones * (12 + mes);
            cout << "Lleva " << descanso << " dias acumulados \n";

        }else if (anio == 2 && mes_actual > mes_ingreso){       // Cuando lleva de 25 a 33 meses trabajando

            descanso = dia_vacaciones * (24 + mes);
            cout <<"Le agendaremos vacaciones cuanto antes, Lleva " << descanso << " dias acumulados \n";

        }else if (anio == 1 && mes_actual < mes_ingreso){       // Cuando lleva 11 meses trabajando

            descanso = dia_vacaciones * (12 + mes);
            cout << "Lleva " << descanso << " dias acumulados \n";

        }else if (anio == 2 && mes_actual < mes_ingreso){       // Cuando lleva 23 meses trabajados

            descanso = dia_vacaciones * (24 + mes);
            cout << "Lleva " << descanso << " dias acumulados \n";

        }else if (anio == 0 && mes_actual > mes_ingreso){       // Tiempo antes del mes actual, de 1 a 10 meses

            descanso = dia_vacaciones * mes;
            cout << "Lleva " << descanso << " dias acumulados \n";

        }else if (anio == 0 && mes_actual < mes_ingreso){

            cout <<"No se puede ingresar fechas despues del mes actual \n";
            return;

        }

}

void pago(){

    cout << "Pago de nomina \n";

    if (contador < 4){

        cout << "Primero registre las horas en la sección 2. \n";

    }else if (contador == 4){

        if (cargo == "mecanico"){

            pago_base = acumulado_horas * valor_hora_mecanico;

            descuentos = (pago_base*0.08);

            cout << "De acuerdo a las horas trabajadas (" << acumulado_horas << ") el pago que corresponde se calcula así: \n";

            cout << "Cargo: " << cargo << "\n";

            cout << "---------------------------------------- \n";

            cout << " Pago base:                    " << pago_base << " |\n";

            cout << " Descuentos (Salud y pension): " << descuentos << "   |\n";

            cout << " Total recibido:               " << pago_base - descuentos << " |\n";

            cout << "---------------------------------------- \n";

        }else if (cargo == "supervisor"){

            pago_base = acumulado_horas * valor_hora_supervisor;

            descuentos = (pago_base*0.08);

            cout << "De acuerdo a las horas trabajadas (" << acumulado_horas << ") el pago que corresponde se calcula así: \n";

            cout << " Cargo : " << cargo << "\n";

            cout << "---------------------------------------- \n";

            cout << " Pago base:                    " << pago_base << " |\n";

            cout << " Descuentos (Salud y pension): " << descuentos << "  |\n";

            cout << " Total recibido:               " << pago_base - descuentos << " |\n";

            cout << "---------------------------------------- \n";

        }



    }

}

int main(){

    cout << "Portal de empleados \n";
    cout << "By: Juan Sanchez \n\n";
    cout << "¿Eres mecanico o supervisor? \n";

    cin >> cargo;

    cout << "\n      ¿Que quieres hacer hoy? \n";

while (true){

    cout << "-------------------------------------- \n";
    cout << "  1. Consultar salario base          | \n";

    cout << "  2. Ingresar horas trabajadas       | \n";

    cout << "  3. Consultar horas trabajadas      | \n";

    cout << "  4. Consultar vacaciones acumuladas | \n";

    cout << "  5. Calcular pago mensual           |\n";

    cout << "  6. Salir                           |\n";
    cout << "--------------------------------------\n";

    cin >> accion;

    if (accion == 6){

        cout << "Fin del programa...";

        break;

    }

    switch (accion){

        case 1:     // Salario del personal en la empresa

        consulta_salario();

        break;

        case 2:     // Ingresar horas trabajadas

        horas();

        break;

        case 3:     // Horas trabajadas del personal

        trabajado();

        break;

        case 4:     // Vacaciones acumuladas

        vacaciones();

        break;

        case 5:

        pago();     // Pago de nomina

        }

    }

}



