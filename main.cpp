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

double seno(double x){
    return x*x*sin(1/x);
}

//
//int main() {
//    
//    double raiz = metodoBiseccion(-5,5,0.00000001, cuadratica);
//    printf("%f", raiz);
//    
//    return 0;
//    
//}





int
main (int argc, char *argv[])
{
    //// mandando una funcion lambda
    //graficarRegion(-10,10, [](double x){return x*x;});
    
    // mandando una funcion definida
    graficarRegion(-0.01,0.01, seno);
        return 0;
}

