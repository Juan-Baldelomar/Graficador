/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: juan
 *
 * Created on August 16, 2020, 8:06 PM
 */

#include <cstdlib>
#include <cairo.h>
//#include "/usr/include/cairo/cairo.h"
#include <iostream>
#include "Biseccion.h"
#include "Graficadora.h"
#include "math.h"

using namespace std;

/*
 * 
 */

double cuadratica(double x){
    return pow(x,2)-1;
} 

double cuadraticaDx(double x){
    return 2*x;
} 

double seno(double x){
    return sin(x);
}

double seno2(double x){
    return x*x*sin(1/x);
}

double seno3(double x){
    return sin(1/x);
}


//funciones requeridas
double f1(double x){
    return x*x;
}

double f2(double x){
    return x*x*x -2*(x*x) +8*x-1;
}

double f3(double x){
    return sin(x);
}

double f4(double x){
    return log(x);
}

// DERIVADAS
double f1_dx(double x){
    return 2*x;
}

double f2_dx(double x){
    return 3*x*x -4*x + 8;
}

double f3_dx(double x){
    return cos(x);
}

double f4_dx(double x){
    return 1/x;
}


void
IniciarGraficador ()
{
    //PRUEBAS 
    //// mandando una funcion lambda (anonima)
    //graficarRegion(-10,10, [](double x){return x*x;});
    
    //PRUEBA F4 ln(x)
    graficarRegion_L(0,2,f4);
    graficarRegion(0,2,f4);
    
    
    // prueba Extra
    //graficarRegion_L(-0.1, 0.1, seno3);
    //graficarRegion(-0.1, 0.1, seno3);
        
}

int main() {
    
    //double raiz = metodoBiseccion(0.5, 2, 0.00000001, f4);
    double raiz = metodoNewton(2, f4, f4_dx, 0.00000001, 1000);
    printf("raiz en %.10f\n", raiz);
    printf("valor en la raiz: f(%.10f) = %.10f\n", raiz, f4(raiz));
    
    //IniciarGraficador();
    
    return 0;
    
}







