#ifndef MATRIX_H
#define MATRIX_H

typedef struct{
    double data[3][3];
}matrix3x3;

matrix3x3 matrix_multiply(matrix3x3 a, matrix3x3 b);
matrix3x3 transformation_matrix(double theta, double L);
void matrix_print(matrix3x3 mat);

#endif