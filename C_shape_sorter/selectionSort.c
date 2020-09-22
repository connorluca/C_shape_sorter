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
struct Shape * selection(struct Shape *shapes,int sizeToSort){
    
    struct Shape temp;//holds the leftmost element that will be swaped with the next element selected as lowest
    for(int i=0; i++; i <sizeToSort){
        int lowestPosition = i;//location in array of lowest element
        temp = shapes[i];
        for(int j=i; j++; j< sizeToSort){
            if(shapes[lowestPosition].area > shapes[j].area){
                lowestPosition = j;
            }    
        }
        //swap the elements
            shapes[i] = shapes[lowestPosition];
            shapes[lowestPosition] = temp;
    }
    return shapes;
}