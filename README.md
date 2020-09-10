# C_shape_sorter
Program to demonstrate implementation of various sorting algorithms in C.
The shape information will be stored in a text file as this is a program just to practice implementation not analyze the speed of each algorithm time will not be tracked
and the size of the file will be kept small.
In an effort to keep the overhead as small as possible the 2 dimensional regular polygons (the shapes) will be stored in a struct with a 3-bit unsigned int used 
to indicate which kind of shape they are for area calculations. These shapes will then be sorted and placed into a file.
The program will take in command line arguements to see which algorithm you would like to use and whether the text file will use a integer to indicate the shape type or
the english name. File format comma delimenated ShapeName,side1,side2,ShapeName - side1 and side2 will be floating point numbers.
