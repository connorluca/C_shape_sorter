/*
 * Copyright (c) 2009-2010, Oracle and/or its affiliates. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Oracle nor the names of its contributors
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

//
// File:   welcome.h
//

#ifndef _welcome_H
#define	_welcome_H
#define PI 3.14159265358979323846 //used for calculation of shapes requiring pi for calculation
struct Shape{
    float side1=0;
    float side2=0;
    float area = 0;//I think in some sorting algorithms you may end up calculating this for some elements of the list of shapes
    //hundreds of times if the list is large enough so I decided the 4-bytes of memory may be cheaper to simply calculate them once
    
    unsigned int shapeType: 4;
    /*
     * 0 Rectangle
     * 1 Triangle side1 = height side2= base
     * 2 Circle side1= raduis
     * 3 CircleSector side1= raduis side2=angle
     * 4 Ellipse side1=axis1 side2=axis2(doesnt really matter order like shape 0)
     * 5 Parallelogram side1=base side2= height
     * 6 Pentagon side1=length
     * 7 Hexagon side1=length
     */
    
};

/*Shifts the contents of the array one to the right
 * This function assumes elements are stored inside the left most indexs first in the incoming array.
 * shapes is the array to be shifted
 * elementToShiftFrom is the index of the element we will start shifting elements to the right from
 * elementToAdd is the element that will replace the index of elementToShiftFrom after the existing elements have been shifted to the right.
 * currentArraySize is how many elements are currently stored in the array
 */
struct Shape * shiftArrayRight(struct Shape *shapes, int elementToShiftFrom, struct Shape elementToAdd, int currentArraySize){
    for(int i = currentArraySize; i--; i >= elementToShiftFrom){
        shapes[i+1] = shapes[i];
    }
    shapes[elementToShiftFrom] = elementToAdd;
    return shapes;
}
/*CurrentSize becuase the actual allocated size for the array is much larger than the number of elements inside of it
 * for the purposes of the insertion sort. For subsequent calls to the currentSize will be used to determine the right end of the array.
 */
int binarySearch(struct Shape *shapes, struct Shape shape, int currentSize){
    return recursiveBinarySearch(shapes,shape, 0, currentSize);
}
/*returns the position to add the next element into.
 */
int recursiveBinarySearch(struct Shape *shapes, struct Shape shape, int left, int right){
    if(left > right){
        return -1;
    }
    int mid = (left+right)/2;
    
//    if(mid == 0){
//        if(shapes[0].area <= shape.area &&( shapes[1].area >= shape.area || shapes[1].area == 0)){
//            return mid;
//        }
//    }//as indexs without a shape filling them yet have an area of 0
    if(shapes[mid].area <= shape.area &&( shapes[mid+1].area >= shape.area || shapes[mid+1].area == 0)){
        return mid;//if mid< current size we must shift elements right
    }
//    else if(shapes[mid].area == 0){
//        return mid;
//    } commented out as this scenario cannot/should not ever happen
    else if(shapes[mid].area >= shape.area){
        return recursiveBinarySearch(shapes, shape, left, mid-1);
    }
    else{
        return recursiveBinarySearch(shapes, shape, mid+1, right);
    }
}


#endif	/* _welcome_H */

