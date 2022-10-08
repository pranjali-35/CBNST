#include <stdio.h>
#include <math.h>

int main(){
    

    float true_val = sqrt(2);
    float approx_val;
    printf("Enter the approximate value of square root of 2 : ");
    scanf("%f",&approx_val);

    float abs_err, rel_err, per_err;
    abs_err = fabs(true_val - approx_val);
    rel_err = abs_err/true_val;
    per_err = rel_err * 100;

    printf("Absolute error = %f\nRelative error = %f\nPercentage error = %f\n",abs_err,rel_err,per_err);

    return 0;
}
