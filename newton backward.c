#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of terms : ");
    scanf("%d",&n);
    float a[n][n+1];
    printf("Enter x and corresponding y : \n");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 2 ; j++){
            scanf("%f",&a[i][j]);
        }
    }

    //creating backward difference table
    for(int j = 2 ; j <= n ; j++){
        for(int i = n-1 ; i >= 0 ; i--){
            a[i][j] = a[i][j-1] - a[i-1][j-1];
        }
    }

    //printing backward difference table
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= i+1 ; j++){
            printf("%0.2f   ",a[i][j]);
        }printf("\n");
    }

    float x;
    printf("Enter the value pf x at which you want to interpolate : ");
    scanf("%f",&x);
    float u = ((x-a[n-1][0])/(a[1][0]-a[0][0]));
    float u1 = u;
    int fact = 1;
    float sum = a[n-1][1];

    for(int j = 2 ; j < n ; j++){
        sum += (u1*a[n-1][j])/fact;
        u1 *= (u+(j-1));
        fact *= j;
    }printf("At x = %0.2f y is %f\n",x,sum);

    return 0;
}
