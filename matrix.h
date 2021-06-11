
#ifndef __MATRIX__
#define __MATRIX__

typedef struct {
	//number of rows in the data array
	unsigned int    m;
	//number of columns in the data array
	unsigned int    n;
	//reference to an array with data
	double* a;
} TMatrix;

/**
Frees up memory
*/
void mx_free(TMatrix* m);

/**
Displays the matrix m
*/
void mx_print(TMatrix* m);

/**
Returns a unit matrix of size n
*/
TMatrix* mx_identity(unsigned int n);

/**
Returns a matrix created from a string, where the string elements are separated by a space, and the strings are separated by a straight slash.
*/
TMatrix* mx_from_text(const char* s);

/**
Returns the result of multiplying m1 and m2
*/
TMatrix* mx_mul(TMatrix* m1, TMatrix* m2);

/**
Returns the result of adding m1 and m2
*/
TMatrix* mx_add(TMatrix* m1, TMatrix* m2);

/**
Returns the result of multiplying the matrix m by the scalar s
*/
TMatrix* mx_mul_scalar(TMatrix* m, double s);

/**
Returns the result of raising the matrix m to the power of s
*/
TMatrix* mx_pow(TMatrix* m, double s);

/**
Returns the result of transposing the matrix m
*/
TMatrix* mx_transponse(TMatrix* m);

/**
Returns the determinant of the matrix m
*/
double mx_det(TMatrix* m);

/**
Sort by the 1st line
*/
void mx_sort(TMatrix* m);

#endif