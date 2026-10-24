#include "matrix.h"
#include<stdio.h>
#include<math.h>

matrix3x3 matrix_multiply(matrix3x3 a, matrix3x3 b)
{
    matrix3x3 result = {{{0.0}}};
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            for(int k = 0;k < 3;k++){
                result.data[i][j] += a.data[i][k]*b.data[k][j];
            }
        }
    }
    return result;
}
/*
[cos(theta) -sin(theta) L*cos(theta)]
[sin(theta)  cos(theta) L*sin(theta)]
[    0            0          1      ]
*/
matrix3x3 transformation_matrix(double theta,double L)
{
    matrix3x3 t = {{{0.0}}};
    
    t.data[0][0] = cos(theta);
    t.data[0][1] = -sin(theta);
    t.data[0][2] = L*cos(theta);

    t.data[1][0] = sin(theta);
    t.data[1][1] = cos(theta);
    t.data[1][2] = L*sin(theta);

    t.data[2][0] = 0.0;
    t.data[2][1] = 0.0;
    t.data[2][2] = 1.0;

    return t;
}

void matrix_print(matrix3x3 mat)
{
    for(int i = 0; i < 3;i++){
        printf("[");
        for(int j = 0;j < 3;j++){
            printf("%8.4f",mat.data[i][j]);
        }
        printf("]\n");
    }
}