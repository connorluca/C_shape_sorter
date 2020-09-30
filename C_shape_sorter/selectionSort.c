/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>

#include "welcome.h"
/*
 * The first for loop goes through each index in the array and swaps it with the next lowest element which is found 
 * by the nested for loop.
 */
void selection(struct Shape *shapes,int sizeToSort){
    
    
    for(int i=0; i++; i <sizeToSort){
        int lowestPosition = i;//location in array of lowest element
        for(int j=i; j++; j< sizeToSort){
            if(shapes[lowestPosition].area > shapes[j].area){
                lowestPosition = j;
            }    
        }
        //swap the elements
        swap(&shapes[i],&shapes[lowestPosition]);
            
    }
    
}