# C_shape_sorter
Program to demonstrate implementation of various sorting algorithms in C.
The shape information will be stored in a text file as this is a program just to practice implementation not analyze the speed of each algorithm time will not be tracked
and the size of the file will be kept small.
In an effort to keep the overhead as small as possible the 2 and 3 dimensional regular polygons (the shapes) will be stored in a struct with a 4-bit unsigned int used 
to indicate which kind of shape they are for area calculations(attribute size may be increased to hold more types of shapes. These shapes will then be sorted by surface area(the only attribute they share) and placed into a file. The file the shape objects will be read from will start with the total number of shapes to be sorted so we do not need to implement and arrayList or any other data structure to store them.
The program will take in command line arguements to see which algorithm you would like to use and whether the text file will use a integer to indicate the shape type or
the english name. File format comma delimenated ShapeName,side1,side2,ShapeName - side1 and side2 will be floating point numbers.
Shapes are sorted from lowest to highest for every algorithm,
$./a.out filename 1 bubble //file must be inside of the files folder 1 for number, 2 for shapename in file
$./a.out filename 2 quick //for number in file instead of shape name and use quicksort
If shapename is used rather than number to indicate file it will be case sensitive
