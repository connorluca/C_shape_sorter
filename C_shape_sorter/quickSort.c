/*
 * Quicksort implementation using medain of 3 to find the medain in enter array. This algorithm is not designed for small arrays as 
 * the overhead needed for the algorithm is not worth it.
 */
#include <stdlib.h>
#include "welcome.h"
//1st call left =0 right = sizeToSort

void quickSort(struct Shape *shapes, int left, int right) {
    if (left < right) {
        int pivotPoint = partition(shapes, left, right); //the shape selected to be the pivot point remains the same, but it has been moved 
        quickSort(shapes, left, pivotPoint);
        quickSort(shapes, pivotPoint + 1, right);

    }
}

int partition(struct Shape *shapes, int left, int right) {
    float pivotPoint = shapes[selectPivot(shapes, left, right)].area;

    int i = left - 1;
    int j = right + 1;
    while (0 == 0) {
        while (shapes[++i].area < pivotPoint) {
            if (i == right)break;
        }
        while (shapes[--j].area > pivotPoint) {
            if (j == left)break;
        }
        if (i >= j) {
            
            return j;
            
        }
        swap(&shapes[i],&shapes[j]);
    }
    
    
}
/*
 * Selects three random elements from left-> right and returns the median of those 3
 */
float selectRandomPivotOfThree(struct Shape *shapes, int left, int right){
    return medianOfThree(rand() % (right - 1), rand() % (right - 1), rand() % (right - 1), shapes);
}

/*
 * To select the pivot point we will use a medain of 3 rule inside a for loop to find the medain of the entire array.
 * Using turkeys Ninther for an approximation may be more effective for very large data sets rather than finding the exact medain or simple using 
 * lomutos median of 3 of the middle lo and high values for each partition or 3 random numbers from the array.
 * When using 
 */
int selectPivot(struct Shape *shapes, int left, int right) {
    int median[3] = {0, 0, 0};
    int remainder = (right - left) % 3; //how many left over elements that won't be handled by the loop
    /*If the remainder is 1 a random element from the array will be added to the
     * array and the median of those 3 will be taken as the median of the entire array.
     * If the remainder is 2 it will be added to the median array and the median of those 3 will be taken as the 
     * median of the entire array.
     * If the remainder is zero median[0] will be taken as the median of the entire array.
     */
    int counter = 0; //represents how many elements are inside of the array holding the medians

    for (int i = left; i + 3; i < right) {
        if (median[2] != 0) {
            median[0] = medianOfThree(median[0], median[1], median[2]);
            median[1] = 0;
            median[2] = 0;
            counter = 1;
        } else {
            median[counter] = medianOfThree(i, i + 1, i + 2);
            counter++;
        }
    }
    if (remainder == 0) {
        return median[0];
    } else if (remainder == 2) {
        return medianOfThree(median[0], right - 1 right - 2);
    } else {
        return medianOfThree(median[0], right - 1, rand() % (right));
    }
}

int medianOfThree(int a, int b, int c, struct Shape *shapes) {
    int x = shapes[a].area - shapes[b].area; //if a is less than b x will be negative etc 0
    int y = shapes[b].area - shapes[c].area;
    int z = shapes[a].area - shapes[c].area;
    if (x * y > 0) {//if both negative a<b and c>b
        return b;
    } else if (x * z > 0) {//x=negative so a<b z is negative so a<c 
        //we have eliminated b as the a possible middle as the previous if failed so it must be c since a is the lowest
        return c;
    } else {
        /*This also covers the case of if two numbers are equal. as there can be no median in 3 numbers if two of them are equal, we simply return a
         * as a is index 0 in the median array and therefore more likely to be the median of the entire array than the other 2 numbers.
         * Because it has likely been checked against other numbers and found to be the median in previous iterations of the loop.
         */
        return a;
    }
}