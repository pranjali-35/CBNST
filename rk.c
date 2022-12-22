#include <stdio.h>

float f(float x, float y){
    return (y-x);
}

int main(){
    int n;
    float x0,y0,y,k1,k2,k3,k4,h,xn;
    printf("Enter the value of x0 and y0 : ");
    scanf("%f%f",&x0,&y0);
    printf("Enter the width : ");
    scanf("%f",&h);
    printf("Enter xn : ");
    scanf("%f",&xn);

    n = (xn-x0)/h;

    for(int i = 0 ; i < n ; i++){
        k1 = h*f(x0,y0);
        k2 = h*f(x0+0.5*h,y0+0.5*k1);
        k3 = h*f(x0+0.5*h,y0+0.5*k2);
        k4 = h*f(x0+h,y0+k3);

        y = y0 + ((k1 + 2*k2 + 2*k3 + k4)/6);
        y0 = y;
        x0 = x0+h;

        printf("The value of y at %f is %f\n",x0,y0);
    }printf("\nThe value of y at %f is %f\n",x0,y0);

    return 0;
}
