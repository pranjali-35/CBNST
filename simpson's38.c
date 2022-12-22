#include <stdio.h>

float f(float x){
    return (1/(1+x));
}

int main(){
    float upper,lower,sum = 0,h;
    int n;
    printf("Enter lower and upper limit : ");
    scanf("%f%f",&lower,&upper);
    printf("Enter the number of sub-intervals : ");
    scanf("%d",&n);

    h = (upper-lower)/n;

    sum += f(lower) + f(upper);
    for(int i = 1 ; i < n ; i++){
        if(i%3 == 0){
            sum += (2*f(lower+i*h));
           
        }else{
             sum += (3*f(lower+i*h));
            
        }
    }sum *= ((3*h)/8);
    printf("Required value of integration is %f\n",sum);

    return 0;
}
