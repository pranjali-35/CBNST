#include <stdio.h>
#include <math.h>

float f(float x){
    return (1/(1+x));
}

int main(){
    float lower,upper,h,sum = 0;
    int n;
    printf("Enter upper limit : ");
    scanf("%f",&upper);
    printf("Enter lower limit : ");
    scanf("%f",&lower);
    printf("Enter number of sub-intervals : ");
    scanf("%d",&n);

    h = (upper-lower)/n;
    sum += f(lower) + f(upper);
    for(int i = 1 ; i < n ; i++){
        sum += 2*(f(lower+i*h));
    }sum *= (h/2);

    printf("Required value of integration is : %f\n",sum);

    return 0;
}
