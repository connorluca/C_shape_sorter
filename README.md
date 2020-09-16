# C_shape_sorter
Program to demonstrate implementation of various sorting algorithms in C.
The shape information will be stored in a text file as this is a program just to practice implementation not analyze the speed of each algorithm time will not be tracked
and the size of the file will be kept small.
In an effort to keep the overhead as small as possible the 2 and 3 dimensional regular polygons (the shapes) will be stored in a struct with a 3-bit unsigned int used 
to indicate which kind of shape they are for area calculations. These shapes will then be sorted by surface area(the only attribute they share) and placed into a file. The file the shape objects will be read from will start with the total number of shapes to be sorted so we do not need to implement and arrayList or any other data structure to store them.
The program will take in command line arguements to see which algorithm you would like to use and whether the text file will use a integer to indicate the shape type or
the english name. File format comma delimenated ShapeName,side1,side2,ShapeName - side1 and side2 will be floating point numbers.
