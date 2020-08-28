/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NewtonR.h
 * Author: juan
 *
 * Created on August 27, 2020, 7:05 PM
 */

#ifndef NEWTONR_H
#define NEWTONR_H

#include<stdio.h>
#include<math.h>
#include<iostream>


using namespace std;

double metodoNewton(double x0, double (*f)(double), double (*f_dx)(double), double epsilon);

#endif /* NEWTONR_H */

