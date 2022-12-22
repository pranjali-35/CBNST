#include <stdio.h>

int main(){
    int n;
    float x;
    printf("Enter the number of terms : ");
    scanf("%d",&n);
    float a[n][n+1];
    printf("Enter the value of x and corresponding y : ");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 2 ; j++){
            scanf("%f",&a[i][j]);
        }
    }

    //creating difference table
    for(int j = 2 ; j <= n ; j++){
        for(int i = 0 ; i < n-j+1 ; i++){
            a[i][j] = a[i+1][j-1] - a[i][j-1];
        }
    }

    //printing forward difference table
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n-i+1 ; j++){
            printf("%0.2f  ",a[i][j]);
        }printf("\n");
    }

    printf("Enter the value for which you want to interpolate : ");
    scanf("%f",&x);

    float u = ((x-a[0][0])/(a[1][0]-a[0][0]));
    float u1 = u;
    int fact = 1;

    float sum = a[0][1];

    for(int j = 2 ; j <= n ; j++){
        sum += ((u1*a[0][j])/fact);
        u1 *= (u-(j-1));
        fact *= j;
    }

    printf("y = %f at x = %0.2f\n",sum,x);

    return 0;
}
