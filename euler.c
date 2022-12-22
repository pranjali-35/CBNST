#include <stdio.h>

float f(float x, float y){
    return ((y-x)/(y+x));
}

int main(){
    float x0,y0,h,xn,x,y;
    int n;

    printf("Enter the value of x0 and y0 : ");
    scanf("%f%f",&x0,&y0);
    printf("Enter the number of sub-intervals : ");
    scanf("%d",&n);
    printf("Enter the value at which you want to find y : ");
    scanf("%f",&xn);

    h = (xn-x0)/n;
    for(int i = 0 ; i <= n ; i++){
        y = y0 + h*f(x0,y0);
        x = x0+h;
        printf("X = %f  Y = %f\n",x0,y0);
        if(x < xn){
            x0 = x;
            y0 = y;
        }
    }printf("Value at X = %f Y is %f\n",x0,y0);

    return 0;
}
