/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "stdio.h"
#include <iostream>
#include "math.h"

#include "Biseccion.h"

using namespace std;

double metodoBiseccion(double x1, double x2, double epsilon, double(*f)(double)) {
    
    //declaracion de variables
    double xMed;
    double f_x1;
    double f_x2;
    double f_xMed;

    do{
         //calculo de valores necearios
         f_x1 = f(x1);
         f_x2 = f(x2);
         f_xMed = f(xMed);
        
        
        // verificar que exista cambio de signo
        if (f_x1 > 0 && f_x2 > 0 || f_x1 < 0 && f_x2 < 0) {
            cout << "El metodo no puede converger, no se cruza el eje x" << endl;
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
         xMed = (x1+x2)/2.00;

    }while (fabs(xMed - x1) > epsilon) ;
    
    return xMed;
}

