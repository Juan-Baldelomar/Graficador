/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biseccion.h
 * Author: juan
 *
 * Created on August 16, 2020, 8:35 PM
 */
#include <limits>
#include "stdio.h"
#include <iostream>
#include "math.h"

#ifndef BISECCION_H
#define BISECCION_H
#define MIN std::numeric_limits<double>::min()






double metodoNewton(double x0, double (*f)(double), double (*f_dx)(double), double epsilon, int max_it);
double metodoBiseccion(double x1, double x2, double epsilon, double(*f)(double)) ;



#endif /* BISECCION_H */

