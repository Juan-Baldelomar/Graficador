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
//#include <cairo.h>
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
IniciarGraficador (double a, double b, short n){
    
    if (a>b) {
        cout << "Parametros incorrectos, a es mayor que b" <<endl;
        return;
    }
    
    //PRUEBAS 
    //// mandando una funcion lambda (anonima)
    //graficarRegion(-10,10, [](double x){return x*x;});
    
    //PRUEBA F4 ln(x)
    //graficarRegion_L(-10,10,[](double x){return x;});
    //graficarRegion(0,2,f4);
    
    
    // prueba Extra
    //graficarRegion_L(-0.1, 0.1, seno3);
    //graficarRegion(-0.1, 0.1, seno3);
        
    if (n==1){
        graficarRegion_L(a,b, f1);
        graficarRegion(a,b, f1);
    }else if(n==2){
        graficarRegion_L(a,b, f2);
        graficarRegion(a,b, f2);
    }else if(n==3){
        graficarRegion_L(a,b, f3);
        graficarRegion(a,b, f3);
    }else{
        graficarRegion_L(a,b, f4);
        graficarRegion(a,b, f4);
    }
}

int main() {
    
    while(true){
        char c;
        double raiz;
        cout << "Presione la Tecla G(g) para graficar, B(b) para usar el metodo de Biseccion o N(n) para el metodo de newton" <<endl;
        cin >> c;
        
        if (c == 'G' || c == 'g'){
            double a, b;
            short n;
            cout << "Ingrese el parametro  del valor inicial del intervalo a" << endl;
            cin >> a;
            cout << "Ingrese el parametro  del valor final del intervalo b" << endl;
            cin >> b;
            cout << "Ingrese el numero de la funcion que desea graficar (1-4)" << endl;
            cin >> n;
            cout << "Espere, graficando funcion ... " << endl;
            IniciarGraficador(a,b,n);
            cout << "Grafica Terminada, verifique la carpeta donde esta el ejecutable o desde donde esta compilando los archivos fuente" <<endl;
        }else if (c == 'B' || c == 'b'){
            double a,b, error;
            short fun;
            cout << "Inserte el valor inicial del intervalo a " << endl;
            cin >> a;
            cout << "Inserte el valor final del intervalo b " << endl;
            cin >> b;
            cout << "Inserte el valor del error " << endl;
            cin >> error;
            cout << "Inserte el numero (1-4) de la funcion que desea graficar" << endl;
            cin >> fun;
            
            if (fun ==1 ){
                raiz = metodoBiseccion(a, b, 0.00000001, f1);
                printf("raiz en %.10f\n", raiz);
                printf("valor en la raiz: f(%.10f) = %.10f\n", raiz, f1(raiz));
            }else if (fun ==2 ){
                raiz = metodoBiseccion(a, b, 0.00000001, f2);
                printf("raiz en %.10f\n", raiz);
                printf("valor en la raiz: f(%.10f) = %.10f\n", raiz, f2(raiz));
            }else if (fun ==3 ){
                raiz = metodoBiseccion(a, b, 0.00000001, f3);
                printf("raiz en %.10f\n", raiz);
                printf("valor en la raiz: f(%.10f) = %.10f\n", raiz, f3(raiz));
            }else{
                raiz = metodoBiseccion(a, b, 0.00000001, f4);
                printf("raiz en %.10f\n", raiz);
                printf("valor en la raiz: f(%.10f) = %.10f\n", raiz, f4(raiz));
            }
            
            
        }else if (c == 'N' || c == 'n'){
            double x0, error;
            int max;
            short fun;
            cout << "Inserte el valor inicial x0" << endl;
            cin >> x0;
            cout << "Inserte el valor maximo de iteraciones " << endl;
            cin >> max;
            cout << "Inserte el valor del error " << endl;
            cin >> error;
            cout << "Inserte el numero (1-4) de la funcion que desea graficar" << endl;
            cin >> fun;
            
            if (fun ==1 ){
                raiz = metodoNewton(x0, f1, f1_dx, error, max);
                printf("raiz en %.10f\n", raiz);
                printf("valor en la raiz: f(%.10f) = %.10f\n", raiz, f1(raiz));
            }else if (fun ==2 ){
                raiz = metodoNewton(x0, f1, f1_dx, error, max);
                printf("raiz en %.10f\n", raiz);
                printf("valor en la raiz: f(%.10f) = %.10f\n", raiz, f2(raiz));
            }else if (fun ==3 ){
                raiz = metodoNewton(x0, f1, f1_dx, error, max);
                printf("raiz en %.10f\n", raiz);
                printf("valor en la raiz: f(%.10f) = %.10f\n", raiz, f3(raiz));
            }else{
                raiz = metodoNewton(x0, f1, f1_dx, error, max);
                printf("raiz en %.10f\n", raiz);
                printf("valor en la raiz: f(%.10f) = %.10f\n", raiz, f4(raiz));
            }
            
        }else{
            break;
        }
    }
    //double raiz = metodoBiseccion(0.5, 2, 0.00000001, f4);
    //raiz = metodoNewton(2, f4, f4_dx, 0.00000001, 1000);
    
    
    
    
    return 0;
    
}







