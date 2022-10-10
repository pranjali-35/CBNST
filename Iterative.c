//Iterative Method Implementation
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

float f(float x){
    return (cos(x) - (3*x) + 1);
	//return (2*x - log10f(x) - 7);
}

float g(float x){               //value of x
    return ((cos(x) + 1)/3);
	//return ((log10f(x) + 7)/2.0); 
}

float df(float x){              //differentiation of x
	return ((sin(x)/3)*(-1));
    //return(fabs(1/(2*x*log(10))));  
}

int main(){
	float x0, x, allowed_err;
	printf("Enter the value of x0 : ");
	scanf("%f",&x0);

    if(df(x0) >= 1){
        printf("Failed!!!\n");
        return 0;
    }

    printf("Enter the allowed error : ");
    scanf("%f",&allowed_err);

    int it = 1;
    while(1){
        x = g(x0);
        if(fabs(x-x0) < allowed_err){
            printf("Iteration %d : x = %f\n",it,x);
            printf("Root is %f\n",x);
            break;
        }else{
            printf("Iteration %d : x = %f\n",it,x);
            x0 = x;
            it++;
        }
    }
	return 0;
}
