#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of terms : ");
    scanf("%d",&n);

    float X[n],y[n], x, sum = 0;
    printf("Enter the value of x and corresponding y : \n");
    for(int i = 0 ; i < n ; i++){
        scanf("%f%f",&X[i],&y[i]);
    }

    printf("Enter the value at which y is required : ");
    scanf("%f",&x);

    for(int i = 0 ; i < n ; i++){
        float term = 1;
        for(int j = 0 ; j < n ; j++){
            if(i != j)
                term *= ((x-X[j])/(X[i]-X[j]));
        }sum += term*y[i];
    }printf("y = %f at x = %f\n",sum,x);

    return 0;
}
