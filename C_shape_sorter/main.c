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
// $./a.out filename 1 bubble //file must be inside of the files folder //1 for number, 2 for shapename in file
// $./a.out filename 2 quick //for number in file instead of shape name and use quicksort
//If shapename is used rather than number to indicate file it will be case sensitive
//Sorted from lowest to highest
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <welcome.h>
#include "selectionSort.c"
#include "bubbleSort.c"
#include "linearInsertionSort.c"
#include "binaryInsertion.c"
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *fp;
    char fileName[] = (strcat("./files/",argv[1])); 
    fp =fopen(fileName, "r");
    int numberOfShapes;
    fscanf(fp, "%d", numberOfShapes);
    struct Shape shapes[numberOfShapes];
    shapes = readShapes(fp, numberOfShapes, (int)argv[2]);
    fclose(fp);
    //numberOfShapes isn't really necessary I'm just including it out of laziness and code readability
    if(strcmp(argv[3], "Selection")==0){
        shapes = selection(shapes, numberOfShapes);
    }
    else if(strcmp(argv[3], "Bubble")==0){
        shapes = bubble(shapes, numberOfShapes);
    }
    else if(strcmp(argv[3], "LinearInsertion")==0){
        shapes = linearInsertion(shapes, numberOfShapes);
    }
    else{
      puts("Invalid sort option selected");
      return -1;//failure due to user input
    }
    
    return (EXIT_SUCCESS);
}
float calcArea(struct Shape *shape, char shapeName[]){
    
    switch(shape->shapeType){
        case 0:
            return shape->side1 * shape->side2;
            break;
        case 1:
            return (shape->side1 * shape->side2)/2;
            break;
        case 2:
            return PI*(shape->side1*shape->side1);
            break;
        case 3:
            return (sqaured(shape->side1)*shape->side2)/2;
            break;
        case 4:
            return shape->side1* shape->side2*PI;
            break;
        case 5:
            return shape->side1 * shape->side2;
            break;
        case 6:
            return (sqaured(shape->side1)+(sqrt(25+10sqrt(5))))/4;
            break;
        case 7:
            return 3/2*sqrt(3)*sqaured(shape->side1);
            break;       
    }
}
float sqaured(float toSqaure){
    return toSqaure*toSqaure;
}
/* Reads in shape data and calc the area assigning to the area attribute
 */
struct Shape * readShapes(FILE *fp, int num, int type){
    struct Shape shapes[num];
    int i = 0;
    float nextSide;
    char shapeName[20];
    while(!feof(fp)){
    
    if(type==1){
        fscanf(fp, "%d", nextSide);
        shapes[i].shapeType = nextSide;
        fscanf(fp, "%f", nextSide);
        shapes[i].side1 = nextSide;
        fscanf(fp, "%f", nextSide);
        shapes[i].side2 = nextSide;
        shapes[i].area = calcArea(shapes[i]);
    }
    else{
        fscanf(fp, "%s", shapeName);
        shapes[i].shapeType = assignType(shapeName);
        fscanf(fp, "%f", nextSide);
        shapes[i].side1 = nextSide;
        fscanf(fp, "%f", nextSide);
        shapes[i].side2 = nextSide;
        shapes[i].area = calcArea(shapes[i]);
    }
    }
}
/* Takes in text input an assigns the shape the approraite type ID
 */
int assignType(char text[]){
    
}

