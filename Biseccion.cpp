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
    double xMed = (x2 + x1) / 2;

    double f_x1 = (*f)(x1);
    double f_x2 = (*f)(x2);
    double f_xMed = (*f)(xMed);

    // verificar que exista cambio de signo
    if (f_x1 > 0 && f_x2 > 0 || f_x1 < 0 && f_x2 < 0){
        cout << "El metodo no puede converger, no se cruza el eje x" << endl;
        return -10000000;
    }
    
    // si el punto medio es solucion
    if (f_xMed == 0 )
        return xMed;
    
    // verificar en donde existe el cambio de signo
    if (f_x1 > 0 && f_xMed < 0 || f_x1 < 0 && f_xMed > 0){
        
        //verificar error
        if (abs(xMed - x1) < epsilon) 
            return xMed;
        
        return metodoBiseccion(x1, xMed, epsilon, f); 
    }
    else {
        if (abs(xMed - x2) < epsilon) 
            return xMed;
        
        return metodoBiseccion(xMed, x2, epsilon, f); 
    }
    
    


    }

