#include <stdio.h>

float f(float x){
    return (1/(1+x));
}

int main(){
    float upper,lower,h, sum = 0;
    int n;
    printf("Enter the lower and the upper limit : ");
    scanf("%f%f",&lower,&upper);
    printf("Enter the number of sub-intervals : ");
    scanf("%d",&n);

    h = (upper-lower)/n;

    sum += f(lower)+f(upper);
    for(int i = 1 ; i < n ; i++){
        if(i%2 != 0){
            sum += (4*f(lower+i*h));
        }else{
            sum += (2*f(lower+i*h));
        }
    }sum *= (h/3);
    printf("Required value of integration is %f\n",sum);

    return 0;
}
