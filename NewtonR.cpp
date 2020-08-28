

#include "NewtonR.h"



double metodoNewton(double x0, double (*f)(double), double (*f_dx)(double), double epsilon){
    double x_k = x0;
    double x_k1 = x0;
    
    do{
        x_k = x_k1;
        x_k1 = x_k - f(x_k)/f_dx(x_k);
        
    }while(fabs(x_k - x_k1)>epsilon);
    
    return x_k1;
}
