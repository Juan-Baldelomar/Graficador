/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graficadora.h
 * Author: juan
 *
 * Created on August 16, 2020, 9:11 PM
 */

#ifndef GRAFICADORA_H
#define GRAFICADORA_H


#include <limits>
#include <iostream>
#include "stdio.h"
#include <cairo.h>
#include <math.h>

//void createGrid(double width, double height);
void graficarRegion(double a, double b, double (*f)(double));

#endif /* GRAFICADORA_H */

