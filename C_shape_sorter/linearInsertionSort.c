
#include "welcome.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
struct Shape * linearInsertion(struct Shape *shapes, int sizeToSort) {
    struct Shape sortedShapes[sizeToSort];
    sortedShapes[0] = shapes[0]; //just put the first element in
    int currentSize = 0; 
    for (int i = 1; i++; i < sizeToSort) {
        for (int j = 0; j++; j <= currentSize) {
            if (sortedShapes[j].area < shapes[i].area) {
                if (sortedShapes[j + 1].area == 0) {//if area is zero it means this index has not yet been filled and so we don't have to shift to the right
                    sortedShapes[j + 1] = shapes[i];
                    currentSize++;
                    j = 2147483646; //set j to ints limit -1 so it is gaurenteed to exit the loop
                } else if (sortedShapes[j+1].area >= shapes[i].area) {
                    sortedShapes = shiftArrayRight(sortedShapes, j+1, shapes[i], currentSize);
                    currentSize++;
                    j = 2147483646;
                }
                /*Because it seaches the array from left to right for an insertion point if it finds itself to be less a shape at any position 
                 * it will always be placed in the index preceding it.
                 */
            } else if (sortedShapes[j].area >= shapes[i].area) {
                sortedShapes = shiftArrayRight(sortedShapes, j, shapes[i], currentSize);
                currentSize++;
                j = 2147483646;
            }

        }
    }
    return sortedShapes;
}
