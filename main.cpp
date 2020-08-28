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

void
IniciarGraficador ()
{
    //// mandando una funcion lambda
    //graficarRegion(-10,10, [](double x){return x*x;});
    
    // mandando una funcion definida
    graficarRegion(-0.1, 0.1, seno2);
        
}

int main() {
    
    //double raiz = metodoBiseccion(-5,0,0.00000001, cuadratica);
    double raiz = metodoNewton(-0.5, cuadratica, cuadraticaDx, 0.000001);
    printf("%f", raiz);
    
    IniciarGraficador();
    
    return 0;
    
}







