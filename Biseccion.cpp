/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "Biseccion.h"
#define MAX_IT 1000

using namespace std;

double metodoBiseccion(double x1, double x2, double epsilon, double(*f)(double)) {
    cout << "-------------------------------- Iniciando metodo de Biseccion --------------------------------" << endl;

    cout << "a: " << x1 << ", b: " << x2 << endl;
    //declaracion de variables
    double xMed = (x1 + x2) / 2.00;
    double f_x1;
    double f_x2;
    double f_xMed;
    int iteracion = 0;

    do {
        cout << "************** Iteracion : " << iteracion << " **************" << endl;

        //calculo de valores necearios
        f_x1 = f(x1);
        f_x2 = f(x2);
        f_xMed = f(xMed);


        // verificar que exista cambio de signo
        if (f_x1 > 0 && f_x2 > 0 || f_x1 < 0 && f_x2 < 0) {
            cout << "No sabemos si el metodo puede converger, no hay seguridad de que se cruza el eje x en este intervalo [" << x1 << ", " << x2 << "]" << endl;
            return MIN;
        }

        // si el punto medio es solucion
        if (f_xMed == 0)
            break;

        // verificar en donde existe el cambio de signo
        if (f_x1 > 0 && f_xMed < 0 || f_x1 < 0 && f_xMed > 0)
            x2 = xMed;
        else
            x1 = xMed;

        //recalcular punto medio
        xMed = (x1 + x2) / 2.00;

        iteracion++;
    } while (fabs(xMed - x1) > epsilon);

    return xMed;
}

double metodoNewton(double x0, double (*f)(double), double (*f_dx)(double), double epsilon, int max_it) {
    cout << "-------------------------------- Iniciando metodo de Newton --------------------------------" << endl;
    cout << "Punto inicial x0: " << x0 << endl;
    double x_k = x0;
    double x_k1 = x0;
    int iteracion = 0;
    double h;
    do {
        
        if (iteracion > max_it) {
            cout << "El metodo ya alcanzo el maximo de iteraciones" << endl;
            return MIN;
        }
        cout << "************** Iteracion : " << iteracion << " **************" << endl;
        x_k = x_k1;
        h = f(x_k) / f_dx(x_k);
        x_k1 = x_k - h;

        

        iteracion++;
    } while (fabs(h) > epsilon);

    return x_k1;
}

