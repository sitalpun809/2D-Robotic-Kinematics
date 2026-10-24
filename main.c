#include<stdio.h>
#include<math.h>
#include"matrix.h"

int main(){
    double L1, L2;
    double theta1_deg, theta2_deg;

    printf("Enter the length for the Link 1(L1): ");
    if (scanf("%lf",&L1) != 1) return 1;

    printf("Enter the length for the Link 2(L2): ");
    if (scanf("%lf",&L2) != 1) return 1;

    printf("Enter the angle for the joint 1(theta1): ");
    if (scanf("%lf",&theta1_deg) != 1) return 1;

    printf("Enter the angle for the joint 2(theta2): ");
    if (scanf("%lf",&theta2_deg) != 1) return 1;

    double theta1 = theta1_deg * (M_PI / 180);
    double theta2 = theta2_deg * (M_PI / 180);

    matrix3x3 T1 = transformation_matrix(theta1, L1);

    matrix3x3 T2 = transformation_matrix(theta2, L2);

    matrix3x3 T_total = matrix_multiply(T1, T2);

    double x = T_total.data[0][2];
    double y = T_total.data[1][2];

    printf("-------------------------------\n");
    printf("Final transformation matrix: \n");
    matrix_print(T_total);

    printf("End-factor position:\n");
    printf("x = %.3f\n",x);
    printf("y = %.3f\n",y);
    printf("-------------------------------\n");

    return 0;
}