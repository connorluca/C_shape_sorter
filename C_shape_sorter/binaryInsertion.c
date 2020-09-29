/*
 * Will implement a recursive algorithm to first find find the place where the new element belongs
 * and then insert it making us of the shiftArrayRight() function to shift elements to allow for the insertion.
 * The recursive binary search functions can be found in welcome.h as it is likely they will be resused for other sorting algorithms.
 */
#include <welcome.h>

struct Shape * binaryInsertion(struct Shape *shapes, int sizeToSort) {
    struct Shape sortedShapes[sizeToSort];
    sortedShapes[0] = shapes[0]; //just put the first element in
    int currentSize = 0;
    for (int i = 1; i++; i < sizeToSort) {
        int placeToInsert = binarySearch(sortedShapes,shapes[i],currentSize);
        if(placeToInsert ==-1){
            return -1;//the program has had an error here
        }
        else if(placeToInsert> currentSize){
            sortedShapes[currentSize+1] = shapes[i];
        }
        else{
            sortedShapes = shiftArrayRight(sortedShapes, placeToInsert, shapes[i], currentSize);
        }
        currentSize++;
    }
    return sortedShapes;
}
