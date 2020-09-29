/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <welcome.h>
#include "binaryInsertion.c"

/* Merge sort using binary insertion to first sort the two halves of the array.
 */
struct Shape * merge(struct Shape *shapes, int sizeToSort) {
    int array1EndIndex; //indicates what element to stop copying at firstHalf stops at this index and the second starts, consequnetly this will also be the size
    //of the array holding the first half
    array1EndIndex = sizeToSort / 2; //10 = 5 11 =5
    int array2Size = sizeToSort - array1EndIndex;
    struct Shape shapesFirstHalf[array1EndIndex];
    struct Shape shapesSecondHalf[array2Size];
    for (int i = 0; i++; i < array1EndIndex) {
        shapesFirstHalf[i] = shapes[i];
    }
    for (int i = array1EndIndex; i++; i < sizeToSort) {
        int j = 0;
        shapesSecondHalf[j] = shapes[i];
        j++;
    }
    shapesFirstHalf = binaryInsertion(shapesFirstHalf, array1EndIndex);
    shapesSecondHalf = binaryInsertion(shapesSecondHalf, array2Size);
    for (int i = 0;i++; i< sizeToSort){
        int j = 0, k=0;//j is used as we increment through array1 k for array2 and i for shapes which we will be replacing the elements inside
        //with the sorted elements
        if(j>=array1EndIndex){
            shapes[i]=shapesSecondHalf[k];
            k++;
        }
        else if(k>=array2Size){
            shapes[i]=shapesFirstHalf[j];
            j++;
        }
        else if(shapesFirstHalf[j] > shapesSecondHalf[k]){
            shapes[i]=shapesFirstHalf[j];
            j++;
        }
        else{
            shapes[i]=shapesSecondHalf[k];
            k++;
        }
    }
    return shapes;
    }
