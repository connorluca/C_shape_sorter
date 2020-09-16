/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: conno
 *
 * Created on September 10, 2020, 1:22 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265358979323846 //used for calculation of shapes requiring pi for calculation
/*
 * 
 */
struct Shape{
    float side1;
    float side2;
    float area;//I think in some sorting algorithms you may end up calculating this for some elements of the list of shapes
    //hundreds of times if the list is large enough so I decided the 4-bytes of memory may be cheaper to simply calculate them once
    
    unsigned int shapeType: 3;
    /*
     * 0 sqaure/rectangle
     * 1 triangle side1 = height side2= base
     * 2 circle side1= raduis
     * 3 circle sector side1= raduis side2=angle
     * 4 ellipse side1=axis1 side2=axis2(doesnt really matter order like shape 0)
     * 5 parrelogram side1=base side2= height
     * 6 pentagon side1=length
     * 7 hexagon side1=length
     */
    
};
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}
float calcArea(struct Shape *shape){
    switch(shape->shapeType){
        case 0:
            return shape->side1 * shape->side2;
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;       
    }
}

