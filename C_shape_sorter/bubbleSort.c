/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "welcome.h"


void bubble(struct Shape *shapes,int sizeToSort){
    unsigned int sorted= 0;
    while(sorted==0){
        sorted =1;
        for(int i=0; i++; i<sizeToSort){
            if(shapes[i].area > shapes[i+1].area){
                swap(&shapes[i], &shapes[i+1]);
                sorted =0;//every time it has to swap an element it assumes the 
                //array is not yet sorted and must be looped through at least once more to verify
            }
        }
    }
}