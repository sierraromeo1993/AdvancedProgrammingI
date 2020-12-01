/*
 * anomaly_detection_util.cpp
 *
 * Author: Ian Sanders 324707165
 */

#include <math.h>
#include <iostream>
#include <cmath>
#include "anomaly_detection_util.h"



/* returns the average of the given values of an array */
float avg(float* x,int size){
    float sum = 0;
    
    for(int i = 0; i<size; i++){
        sum+= x[i];
    }

    return sum/size;


}

/* Does the actual calculation of the avgiance of a given set of data points from array once 
median is known*/
float avgEq(float* x,int size, float avg){
    float sum = 0;
    for(int i = 0; i<size; i++){
        sum+= (x[i]-avg)*(x[i]-avg);
        
    }

    return sum/size;
}




/* Calculates the avgiance of a given set of data points through helper function avgEq  */
float var(float* x, int size){
    float avVal = avg(x,size);
    return avgEq(x,size,avVal);
}

/* Does the actual calculation of the coavgiance of a given set of data points from arrays once 
median is known for both sets of data points */
float covEq(float* x, float avgX,float* y, float avgY,int size){
    float sum = 0;
    for(int i = 0; i<size; i++){
        sum+= (x[i]-avgX)*(y[i]-avgY);
        
    }
    
    return sum/size;
}



/* Calculates the coavgiance of a given set of data points through helper function covEq  */
float cov(float* x, float* y, int size){
    float avgX = avg(x,size);
    float avgY = avg(y,size);
    return covEq(x,avgX,y,avgY,size);


}



/* returns the Pearson correlation coefficient of X and Y */
float pearson(float* x,float* y, int size){

    return (cov(x,y,size)/(sqrt(var(x,size))*sqrt(var(y,size))));

}




/* performs a linear regression and returns the line equation, line equation is y = ax + b  */
Line linear_reg(Point** points, int size){
    
    

    float arrX[size];
    float arrY[size];
    
    
    for(int i = 0 ; i < size ; i++){
        arrX[i] = points[i]->x;
        arrY[i] = points[i]->y;
        
    }

    float avgX = avg(arrX,size);
    float avgY = avg(arrY,size);

    float a =  cov(arrX,arrY,size)/var(arrX,size);
    


    float b =  avgY -(a*avgX);

    Line line(a,b);

    return line;
}



/* returns the deviation between point p and the line equation of the points,ie returns the distance 
between the y value of the point */
float dev(Point p,Point** points, int size){
    Line line =  linear_reg(points,size);
    return fabs(line.f(p.x) - p.y);
    


}

/* returns the deviation between point p and the line 
ie returns the distance  between the y value of the point*/

float dev (Point p,Line l){
    return fabs(l.f(p.x) - p.y);

    
}