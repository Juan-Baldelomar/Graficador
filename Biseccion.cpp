/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



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


double metodoNewton(double x0, double (*f)(double), double (*f_dx)(double), double epsilon){
    double x_k = x0;
    double x_k1 = x0;
    
    do{
        x_k = x_k1;
        x_k1 = x_k - f(x_k)/f_dx(x_k);
        
    }while(fabs(x_k - x_k1)>epsilon);
    
    return x_k1;
}

